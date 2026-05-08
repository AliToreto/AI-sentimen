import pandas as pd
import re
import matplotlib.pyplot as plt
import seaborn as sns
from Sastrawi.Stemmer.StemmerFactory import StemmerFactory
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.naive_bayes import MultinomialNB
from sklearn.metrics import accuracy_score, classification_report
from sklearn.metrics import confusion_matrix
import joblib

# --- 1. DEFINISI FUNGSI ---
def labeling(rating):
    if rating >= 4: return 'positif'
    elif rating <= 2: return 'negatif'
    else: return 'netral'

factory = StemmerFactory()
stemmer = factory.create_stemmer()

# Kamus singkatan sesuai temuan di datamu
slang_dict = {
    "yg": "yang", "bgt": "banget", "jlk": "jelek", "ga": "tidak", 
    "gak": "tidak", "gk": "tidak", "mks": "terima kasih", "lmbt": "lambat", 
    "brg": "barang", "dateng": "datang", "psn": "pesan", "dtg": "datang"
}

def clean_text(text):
    text = str(text).lower()
    for slang, formal in slang_dict.items():
        # Tambahin spasi biar ga salah replace (misal: "gajah" ga jadi "tidakjah")
        text = text.replace(f" {slang} ", f" {formal} ")
    text = re.sub(r'[^a-zA-Z\s]', '', text) 
    return stemmer.stem(text)

print("🚀 Memulai mode sat-set... Manggil data bersih.")

# 1. Panggil file yang udah lu bikin tadi
df_sample = pd.read_csv('dataset_siap_pakai.csv')

# 2. Cek kalau ada baris yang tiba-tiba kosong setelah dibersihin
df_sample = df_sample.dropna(subset=['review_clean'])

print(f"✅ Berhasil muat {len(df_sample)} data bersih. Siap tempur!")

# --- 5. FEATURE EXTRACTION & TRAINING ---
tfidf = TfidfVectorizer(max_features=2000)
X = tfidf.fit_transform(df_sample['review_clean'])
y = df_sample['sentimen']

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

model = MultinomialNB()
model.fit(X_train, y_train)

# Trik Simpen Model buat Bikin Web App Nanti:
joblib.dump(model, 'model_sentimen_nb.pkl')
joblib.dump(tfidf, 'tfidf_vectorizer.pkl')

# --- 6. HASIL AKURASI ---
y_pred = model.predict(X_test)
print(f"\n📊 Akurasi Model: {accuracy_score(y_test, y_pred) * 100:.2f}%")
print("\n📝 Laporan Klasifikasi:\n", classification_report(y_test, y_pred))

# --- 7. TES PREDIKSI (Bongkar Isi Otak AI) ---
print("\n--- Tes Input Sendiri ---")
test_teks = "Barang cacat jelek rusak parah lambat" # Coba pake kalimat murni negatif tanpa kata "toko/belanja"
clean_test = clean_text(test_teks)
v_test = tfidf.transform([clean_test])

# Prediksi label
hasil = model.predict(v_test)

# Prediksi probabilitas (Biar ketahuan yakinnya berapa persen)
probabilitas = model.predict_proba(v_test)[0]
persen_negatif = probabilitas[0] * 100
persen_positif = probabilitas[1] * 100

print(f"Input: '{test_teks}'")
print(f"👉 Hasil Prediksi: {hasil[0].upper()}")
print(f"Detail Keyakinan AI -> Negatif: {persen_negatif:.2f}% | Positif: {persen_positif:.2f}%")

# --- 8. VISUALISASI CONFUSION MATRIX ---
cm = confusion_matrix(y_test, y_pred)

plt.figure(figsize=(8, 6))
sns.heatmap(cm, annot=True, fmt='d', cmap='Blues', 
            xticklabels=['Negatif', 'Positif'], 
            yticklabels=['Negatif', 'Positif'])

plt.title('Confusion Matrix - Analisis Sentimen E-Commerce', fontsize=15, fontweight='bold')
plt.xlabel('Tebakan Model (Predicted)', fontsize=12)
plt.ylabel('Label Asli (Actual)', fontsize=12)

# Ini yang bikin grafiknya muncul di layar lu
plt.show()