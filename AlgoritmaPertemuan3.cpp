#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip> 

using namespace std;

int pil;

void pilih();
void buat_baru();
void push_depan();
void pop_depan();
void tampil();

struct node
{
    char nama[20];
    int umur;
    float tinggi;
    struct node *prev, *next;
};

node *baru, *head = NULL, *tail = NULL, *hapus, *bantu;

int main()
{
    do
    {
        system("cls");

        cout << "MENU DOUBLE LINKED LIST" << endl;
        cout << "1. Push Depan" << endl;
        cout << "2. Pop Depan" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "4. Selesai" << endl;
        cout << "Pilihan Anda : ";
        cin >> pil;

        pilih();
    }
    while (pil != 4);

    return 0;
}

void pilih()
{
    if (pil == 1)
        push_depan();
    else if (pil == 2)
        pop_depan();
    else if (pil == 3)
        tampil();
    else if (pil == 4)
        cout << "Selesai" << endl;
    else 
        cout << "Pilihan tidak valid!" << endl;
}

void buat_baru()
{
    baru = new node;

    cout << "input nama     : ";
    cin >> baru->nama;
    cout << "input umur     : ";
    cin >> baru->umur;
    cout << "input tinggi   : ";
    cin >> baru->tinggi;

    baru->prev = NULL;
    baru->next = NULL;
}

void push_depan()
{
    buat_baru();

    if (head == NULL)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }

    cout << endl << endl;
    tampil();
}

void pop_depan()
{
    if (head == NULL)
    {
        cout << "Kosong";
    }
    else if (head->next == NULL)
    {
        hapus = head;
        head = NULL;
        tail = NULL;
        delete hapus;
    }
    else
    {
        hapus = head;
        head = hapus->next;
        head->prev = NULL;
        delete hapus;
    }

    cout << endl << endl;
    tampil();
}

void tampil()
{
    if (head == NULL)
    {
        cout << "Kosong";
    }
    else
    {
        bantu = head;
        cout << "\n--------------------------------------------------" << endl;
        cout << left << setw(15) << " NAMA" 
             << setw(10) << "UMUR" 
             << setw(10) << "TINGGI" << endl;
        cout << "--------------------------------------------------" << endl;

        while (bantu != NULL)
        {
            cout << " " << left << setw(14) << bantu->nama; 
            cout << setw(10) << bantu->umur;
            cout << setw(10) << bantu->tinggi << endl;

            bantu = bantu->next; // Geser ke node berikutnya
        }
        cout << "--------------------------------------------------" << endl;
    }

    getch();
}