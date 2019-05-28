#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

int login();
int cursor(int X, int Y);
void boxLine(const int posX, const int posY, const int sizeX, const int sizeY);

int main(){
  boxLine(49,0,22,1);
  cursor(50,0);
  printf("PROGRAM KASIR TOSERBA");
  int r,a;
  int bayar;
  char *nama[10];
  login();
  system("cls");
  nama[0]="IndoMie Goreng";
  nama[1]="IndoMie Rebus";
  nama[2]="Head&Shoulder";
  nama[3]="Lifebuoy";
  nama[4]="PocariSweat";
  nama[5]="Fanta Strawberry";
  int CodeBarang[6];
  CodeBarang[0]=1001;
  CodeBarang[1]=1002;
  CodeBarang[2]=1003;
  CodeBarang[3]=1004;
  CodeBarang[4]=1005;
  CodeBarang[5]=1006;
  int harga[6];
  harga[0]=2000;
  harga[1]=2000;
  harga[2]=24000;
  harga[3]=3000;
  harga[4]=5000;
  harga[5]=6000;
  int loop=0;
  int keranjang[2][20];
  while(1){
    boxLine(49,0,22,1);
    cursor(50,0);
    printf("PROGRAM KASIR TOSERBA");
    cursor(47,3);
    printf("masukkan kode barang : ");
    scanf ("%d",&r);
    for(int i=0;i<6;i++){
      if (CodeBarang[i]==r){
        a=i;
        cursor(47,4);
        printf ("%s, Jumlah :",nama[a]);
        int qty;
        scanf ("%d",&qty);
        keranjang[1][loop]=qty;
        keranjang[0][loop]=i;
        loop++;
        goto Indexing;
      }
      else if(i==5){
        cursor(47,4);
        printf("TIDAK DITEMUKAN\n");
        getch();
        fflush(stdin);
        main();
      }
    }
    Indexing :
    for(int a=0;a<loop;a++)
      printf("                    Kode: %d | Nama: %s | Harga Satuan Rp%d | Qty %d | Harga : Rp%d\n",CodeBarang[keranjang[0][a]],nama[keranjang[0][a]],harga[keranjang[0][a]],keranjang[1][a],harga[keranjang[0][a]]*keranjang[1][a]);
    printf("\n                                        Apa Anda Ingin Memilih Barang Lain? (y/n)");
    while(1){
      int x=_getch();
      if(x=='y'){
        system("cls");
        break;
      }
      else if(x=='n')goto printAll;
    }
  fflush(stdin);
  }
  printAll:
  system("cls");
  boxLine(49,0,22,1);
  cursor(50,0);
  printf("PROGRAM KASIR TOSERBA");
  cursor(57,1);
  printf("INVOICE\n\n");
  int totalharga=0;
  for(int a=0;a<loop;a++){
    printf("                       Kode: %d | Nama: %s | Harga Satuan Rp%d | Qty %d | Harga : Rp%d\n",CodeBarang[keranjang[0][a]],nama[keranjang[0][a]],harga[keranjang[0][a]],keranjang[1][a],harga[keranjang[0][a]]*keranjang[1][a]);
    totalharga+=harga[keranjang[0][a]]*keranjang[1][a];
  }
  cursor(49,4+loop);
  printf("Total Harga : Rp %d",totalharga);
  _getch();
  cursor(45,5+loop);
  printf("Jumlah uang dibayarkan:Rp ");
  scanf("%d",&bayar);
  if (totalharga==bayar){
    cursor(39,6+loop);
    printf("Terima kasih telah berbelanja di toko kami.");
  }else if(totalharga>=bayar){
    cursor(50,6+loop);
    printf("Maaf uang anda kurang");
  }else if(totalharga<=bayar){
    cursor(50,6+loop);
    printf("Kembalian:Rp %d",bayar-totalharga);
  }
  _getch();
  cursor(54,7+loop);
  printf("PROGRAM KASIR");
  cursor(55,8+loop);
  printf("Dio Fajrie F");
  cursor(59,9+loop);
  printf("Ricky");
}

int login(){
  char nama[16];
  int loop=0;
  char user[10];
  char pase[10]="admin";
  while(1){
    system("cls");
    boxLine(49,0,22,1);
    cursor(50,0);
    printf("PROGRAM KASIR TOSERBA");
    cursor(54,3);
    printf("Username:");
    scanf("%s",&user);
    cursor(54,4);
    printf("Password:");
    while(1){
      int x=getch();
      if(x==13) break;
      else if(x==8&&loop>0){
        printf("\b \b");
        nama[loop]=0;
        loop--;
      }
      else{
        printf("*");
        nama[loop]=x;
        loop++;
      }
    }
    nama[loop]=0;
    for(int a=0;a<=strlen(nama);a++){
      if(a==strlen(nama)) return 0;
      else if(nama[a]!=pase[a]){
        loop=0;
        cursor(44,5);
        printf("Maaf Password yang anda masukan salah!!");
        _getch();
        system("cls");
        break;
      }
    }
  }
}

int cursor(int X, int Y){
  COORD pos;
  pos.X=X;
  pos.Y=Y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}

void boxLine(const int posX, const int posY, const int sizeX, const int sizeY){
    cursor(posX,posY);
    printf("%c",218);
    for(int a=posX;a<posX+sizeX;a++ )printf("%c",196);
    cursor(posX+sizeX,posY);
    printf("%c",191);
    for(int a=posY+1;a<posY+sizeY+1;a++){
        cursor(posX,a);
        printf("%c",179);
        cursor(posX+sizeX,a);
        printf("%c",179);
    }
    cursor(posX,posY+sizeY+1);
    printf("%c",192);
    for(int a=posX;a<posX+sizeX;a++ )printf("%c",196);
    cursor(posX+sizeX,posY+sizeY+1);
    printf("%c",217);
}
