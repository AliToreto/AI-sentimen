// #include <stdio.h>
// int main() 
// {
// int a; 
// int *b; 
// a = 3;
// b = &a;  /* b mencetak nilai dari address a*/ 
// if (*b == a) /*cek nilai *b = a = 3 */
// printf("OK\n"); /*jika b = &a, maka *b = a, jadi *b = a = 3 
// dan jika = 3, maka *b = a */
// }

// #include<iostream> 
// #include<conio.h> 
// using namespace std; 
// int main(){
// int ilham,*raka,amir,budi; 
// ilham=75;
// budi =60;
// // raka= &ilham; /*Nilai variabel raka adalah merupakan 
// // alamat memori dari nilai ilham*/
// // amir = ilham; 
// // raka = &budi; 
// // ilham = budi;
// // cout<<"Nilai Ilham adalah "<<ilham<<endl;
// // cout<<"Nilai Raka adalah "<<raka<<endl;
// // cout<<"Nilai Amir adalah "<<amir<<endl; 
// // getch();
// // }

// #include <iostream> 
// #include <conio.h> 
// #include <windows.h> 
// 
// using namespace std;
// 
// struct Mahasiswa {
//     int No;
//     char Nama[20]; 
//     char Nim[15];
//     float Tugas;
//     float UTS;
//     float UAS; 
//     float NilaiAkhir; 
//     char Nilai;       
// };
// 
// void gotoxy(int x, int y) { 
//     COORD coord;
//     coord.X = x; 
//     coord.Y = y;
//     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
// }
// 
// void Input(Mahasiswa *mhs, int jumData) {
//     cout << endl;
//     for(int i = 0; i < jumData; i++) {
//         mhs[i].No = i + 1;
//         cout << "Data Ke-" << mhs[i].No << endl; 
//         cout << "Nama        : "; cin >> mhs[i].Nama; 
//         cout << "Nim         : "; cin >> mhs[i].Nim;
//         cout << "Nilai Tugas : "; cin >> mhs[i].Tugas; 
//         cout << "Nilai UTS   : "; cin >> mhs[i].UTS; 
//         cout << "Nilai UAS   : "; cin >> mhs[i].UAS; 
//         cout << endl;
//     } 
// }
// 
// void ProsesData(Mahasiswa *mhs, int jumData) {
//     for(int i = 0; i < jumData; i++) {
//         mhs[i].NilaiAkhir = (mhs[i].Tugas * 0.3) + (mhs[i].UTS * 0.3) + (mhs[i].UAS * 0.4);
//         
//         if(mhs[i].NilaiAkhir >= 85) 
//             mhs[i].Nilai = 'A';
//         else if(mhs[i].NilaiAkhir >= 75) 
//             mhs[i].Nilai = 'B';
//         else if(mhs[i].NilaiAkhir >= 60) 
//             mhs[i].Nilai = 'C';
//         else if(mhs[i].NilaiAkhir >= 50) 
//             mhs[i].Nilai = 'D';
//         else 
//             mhs[i].Nilai = 'E'; 
//     }
// }
// 
// void Cetak(Mahasiswa *mhs, int jumData) {
//     system("cls");
//     cout << "----------------------------------------------------------------------\n";
//     cout << "No   Nim          Nama           Tugas   UTS    UAS    Rata2   Grade\n";
//     cout << "----------------------------------------------------------------------\n";
//     
//     float totalNilaiKelas = 0; 
//     int y = 3; 
// 
//     for(int i = 0; i < jumData; i++) {
//         y++;
//         gotoxy(0, y);  cout << mhs[i].No; 
//         gotoxy(5, y);  cout << mhs[i].Nim; 
//         gotoxy(18, y); cout << mhs[i].Nama; 
//         gotoxy(33, y); cout << mhs[i].Tugas; 
//         gotoxy(41, y); cout << mhs[i].UTS; 
//         gotoxy(48, y); cout << mhs[i].UAS; 
//         gotoxy(55, y); cout << mhs[i].NilaiAkhir; 
//         gotoxy(63, y); cout << mhs[i].Nilai;      
// 
//         totalNilaiKelas += mhs[i].NilaiAkhir; 
//     }
//     cout << "\n----------------------------------------------------------------------\n";
//     
//     float rataRataKelas = totalNilaiKelas / jumData;
//     cout << "Total Rata-rata Kelas : " << rataRataKelas << endl;
//     cout << "----------------------------------------------------------------------\n";
// }
// 
// int main() {
//     int jumData;
//     Mahasiswa *mhs;
// 
//     cout << "Masukkan jumlah data : "; 
//     cin >> jumData;
// 
//     mhs = new Mahasiswa[jumData]; 
// 
//     Input(mhs, jumData); 
//     ProsesData(mhs, jumData); 
//     Cetak(mhs, jumData);
// 
//     delete[] mhs;
// 
//     getch();
//     return 0;
// }

#include <stdio.h>
void fn_charswap(void *x,  void *y) 
{
char charTemp;
char *x1 = (char *)x;
char *y1 = (char *)y;
charTemp = *x1; 
*x1 = *y1;
*y1 = charTemp; 
}
void fn_intswap(void *x,  void *y) 
{
int intTemp;
int *x1 = (int *)x;
int *y1 = (int *)y;
intTemp = *x1; 
*x1 = *y1;
*y1 = intTemp; 
}
void fn_swap(void *x, void *y, void(*fnPtr)(void *,  void *)) 
{
fnPtr(x, y); 
}

int main() 
{
char charX = 'C'; 
char charY = 'P'; 
int intX = 12; 
int intY = 67;
printf("Variables BEFORE Swapping\n");
printf("--------------------------\n");
printf("charX = %c  ", charX);
printf("charY = %c  ", charY);
printf("\nintX = %d  ", intX);
printf("intY = %d  ", intY);
fn_swap(&intX, &intY, fn_intswap); 
fn_swap(&charX, &charY, fn_charswap);
printf("\n\nVariables AFTER Swapping\n");
printf("--------------------------\n");
printf("charX = %c  ", charX);
printf("charY = %c  ", charY);
printf("\nintX = %d  ", intX);
printf("intY = %d  ", intY); 
return 0;
}