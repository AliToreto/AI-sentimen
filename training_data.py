import pandas as pd
import re
import pickle

from Sastrawi.Stemmer.StemmerFactory import StemmerFactory
from Sastrawi.StopWordRemover.StopWordRemoverFactory import StopWordRemoverFactory

from sklearn.model_selection import train_test_split
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, classification_report

print("🚀 MEMULAI TRAINING MODEL")

# =====================================================
# STEMMER & STOPWORDS
# =====================================================

factory = StemmerFactory()
stemmer = factory.create_stemmer()

stop_factory = StopWordRemoverFactory()
stopwords = set(stop_factory.get_stop_words())

# =====================================================
# SLANG WORD
# =====================================================

slang_dict = {
    "yg": "yang",
    "bgt": "banget",
    "ga": "tidak",
    "gak": "tidak",
    "gk": "tidak",
    "tdk": "tidak",
    "jlk": "jelek",
    "lmbt": "lambat",
    "brg": "barang",
    "kcewa": "kecewa",
    "ancur": "hancur",
    "mantul": "mantap"
}

# =====================================================
# CLEANING FUNCTION
# =====================================================

def clean_text(text):

    text = str(text).lower()

    # hapus url
    text = re.sub(r'http\S+', '', text)

    # hapus simbol
    text = re.sub(r'[^a-zA-Z\s]', ' ', text)

    # hapus spasi berlebih
    text = re.sub(r'\s+', ' ', text).strip()

    words = text.split()

    # slang replacement
    words = [slang_dict.get(word, word) for word in words]

    # stopword removal
    words = [word for word in words if word not in stopwords]

    # stemming
    words = [stemmer.stem(word) for word in words]

    return ' '.join(words)

# =====================================================
# LOAD DATASET
# =====================================================

df = pd.read_csv(
    "Dataset Review Product di Shopee dan Tokopedia.csv",
    sep=';',
    encoding='latin-1',
    on_bad_lines='skip'
)

# =====================================================
# AMANKAN DATA
# =====================================================

df['rating'] = pd.to_numeric(df['rating'], errors='coerce')

df = df.dropna(subset=['review', 'rating'])

df = df.drop_duplicates(subset=['review'])

# =====================================================
# LABELING
# =====================================================

def label_sentimen(rating):

    if rating >= 4:
        return 'positif'

    elif rating <= 2:
        return 'negatif'

    else:
        return 'netral'

df['sentimen'] = df['rating'].apply(label_sentimen)

# hapus netral
df = df[df['sentimen'] != 'netral']

# =====================================================
# BALANCING 3000 DATA
# =====================================================

df_pos = df[df['sentimen'] == 'positif'].sample(
    n=1500,
    random_state=42
)

df_neg = df[df['sentimen'] == 'negatif'].sample(
    n=1500,
    random_state=42
)

df = pd.concat([df_pos, df_neg])

# shuffle
df = df.sample(frac=1, random_state=42).reset_index(drop=True)

print("\n📊 DATASET FINAL")
print(df['sentimen'].value_counts())

# =====================================================
# PREPROCESSING
# =====================================================

print("\n⏳ MEMBERSIHKAN TEKS...")

df['review_clean'] = df['review'].apply(clean_text)

df = df[df['review_clean'].str.strip() != '']

# =====================================================
# TF-IDF
# =====================================================

tfidf = TfidfVectorizer(
    max_features=10000,
    ngram_range=(1,2),
    min_df=2,
    max_df=0.9
)

X = tfidf.fit_transform(df['review_clean'])

y = df['sentimen']

# =====================================================
# SPLIT DATA
# =====================================================

X_train, X_test, y_train, y_test = train_test_split(
    X,
    y,
    test_size=0.2,
    random_state=42,
    stratify=y
)

# =====================================================
# MODEL
# =====================================================

model = LogisticRegression(max_iter=1000)

model.fit(X_train, y_train)

# =====================================================
# EVALUASI
# =====================================================

y_pred = model.predict(X_test)

akurasi = accuracy_score(y_test, y_pred)

print(f"\n✅ AKURASI MODEL: {akurasi*100:.2f}%")

print("\n📋 CLASSIFICATION REPORT")
print(classification_report(y_test, y_pred))

# =====================================================
# SIMPAN MODEL
# =====================================================

pickle.dump(model, open("model_sentimen.pkl", "wb"))

pickle.dump(tfidf, open("tfidf_vectorizer.pkl", "wb"))

print("\n💾 MODEL BERHASIL DISIMPAN")