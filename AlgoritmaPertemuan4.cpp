#include <stdio.h>
#include <conio.h>
#include <windows.h>
using namespace std;

struct STACK{
	int data[5];
	int atas;
};

STACK tumpuk;

main (){
	system("cls");
	int pilihan, baru, i;
	
	tumpuk.atas = -1;
	do {
		system("cls");
		printf("1. Push Data \n");
		printf("2. Pop Data \n");
		printf("3. Print Data \n");
		printf("4. Clear Data \n");
		printf("5. Top Data \n"); 
		printf("\nPilihan = ");
		scanf("%d", &pilihan);
		switch(pilihan){
			case 1:{
				if(tumpuk.atas == 4){
					printf("Tumpukkan Penuh");
					getch();
				}
				else {
					printf("Data yang akan di-push = ");
					scanf("%i", &baru);
					tumpuk.atas++;
					tumpuk.data[tumpuk.atas] = baru;
				}
				break;
			}
			case 2:{
				if (tumpuk.atas == -1){
					printf("Tumpukkan Kosong");
					getch();
				}
				else {
					printf("Data yang akan di POP = %d", tumpuk.data[tumpuk.atas]);
					tumpuk.atas--;
					getch();
				}
				break;
			}
			case 3:{
				if (tumpuk.atas <= -1){
					printf("Tumpukkan Kosong");
					getch();
				}
				else {
					printf("Data = ");
					for(i = 0; i <= tumpuk.atas; i++){
						printf("%d ", tumpuk.data[i]);
					}
					getch();
				}
				break;
			}
			case 4:{
				if (tumpuk.atas == -1){
					printf("Tumpukkan Kosong");
					getch();
				}
				else {
					printf("Data yang akan di clear = ");
					for(i = 0; i <= tumpuk.atas; i++){
						printf("%d ", tumpuk.data[i]);
					}
					tumpuk.atas = -1; 
					getch();
				}
				break;
			}
			case 5:{ 
				if (tumpuk.atas == -1){
					printf("Tumpukkan Kosong");
					getch();
				}
				else {
					printf("Top Data = %d\n", tumpuk.data[tumpuk.atas]) ;
                    printf("Posisi data saat ini = %d", tumpuk.atas);
					getch();
				}
				break;
			}
			default:{
				printf("\nTidak ada dalam pilihan");
			}
		}
	}
	while(pilihan >= 1 && pilihan <= 5); 
	getch();
}