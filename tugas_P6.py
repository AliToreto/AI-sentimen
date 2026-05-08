##import numpy as np
##
##print("=== Program Operasi Matriks ===")
##baris = int(input("Masukkan jumlah baris matriks: "))
##kolom = int(input("Masukkan jumlah kolom matriks: "))
##
##print("\n--- Input Matriks A ---")
##matrik_a_list = []
##for i in range(baris):
##    row = []
##    for j in range(kolom):
##        nilai = int(input(f"Masukkan elemen baris {i+1} kolom {j+1}: "))
##        row.append(nilai)
##    matrik_a_list.append(row)
##
##print("\n--- Input Matriks B ---")
##matrik_b_list = []
##for i in range(baris):
##    row = []
##    for j in range(kolom):
##        nilai = int(input(f"Masukkan elemen baris {i+1} kolom {j+1}: "))
##        row.append(nilai)
##    matrik_b_list.append(row)
##
##matrik_a = np.array(matrik_a_list)
##matrik_b = np.array(matrik_b_list)
##
##print("\nMatriks A:")
##print(matrik_a)
##print("\nMatriks B:")
##print(matrik_b)
##
##hasil_jumlah = matrik_a + matrik_b
##
##print("\n=== HASIL PENJUMLAHAN (matrik_a + matrik_b) ===")
##print(hasil_jumlah)


