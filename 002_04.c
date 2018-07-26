/*PROGRAM PENCARIANBagiduaMenurun_Prosedur*/
//Program untuk menambahkan elemen baru dalam baru jika belum ada. mencari dari sekumpulan data inputan dan muncul pesan baik ditemukan maupun tidak
//larik terurut menurun

#include<stdio.h>				//file header
#define Nmaks 100				//konstanta Nmaks

/*Tipe bentukan baru*/
typedef enum {false=0, true=1} boolean;		//bentukan Boolean
typedef int LarikInt [Nmaks];				//bentukan LarikInt berbentuk Array

/*DEKLARASI PROTOTYPE*/
void BacaLarik (LarikInt L, int n);							//prosedur BacaLarik
void BubbleSort4 (LarikInt L, int n);
void BinarySearch (LarikInt L, int n, int x, int *idx);		//prosedur SeqSearch4 untuk nilai indeks

main()						//main program
{
	/*DEKLARASI*/
	LarikInt L;		//var L bertipe LarikInt
	int i;			//pencacah
	int n;			//variabel n sebagai masukan
	int x;			//variabel x sebagai data yang dicari
	int idx;		//variabel indeks
	
	/*DESKRIPSI*/
	printf("\t\tPROGRAM PENCARIAN BINARY(Menurun)\n\n");
	printf("Masukkan jumlah elemen : ");
	scanf("%i", &n);		//inputan
	
	BacaLarik (L, n);		//pemanggilan BacaLarik
	
	BubbleSort4(L, n);
	
	printf("\nMasukkan nilai yang dicari : ");
	scanf("%i", &x);	//input data yang dicari
	
	BinarySearch(L, n, x, &idx); //pemanggilan SeqSearch4
	if (idx!=-1)		//jika indeks tidak sama dengan -1
	{
		printf("\n%i sudah terdapat dalam larik ke-%i", x, idx+1);
	}
	else				//jika indeks == -1
	{
		L[n]=x;			//menambah elemen
		for(i=0; i<=n; i++)	//perulangan pencetakan
		{
			printf("%i\t", L[i]);
		}
	} 
}

void BacaLarik (LarikInt L, int n)		//prosedur
{
	/*DEKLARASI*/
	int i;			//pencacah

	/*DESKRIPSI*/
	for(i=0; i<n; i++)
	{
		printf("\nMasukkan data ke-%i : ", i+1);
		scanf("%i", &L[i]);	//Masukkan data tiap array
	}
}

void BubbleSort4 (LarikInt L, int n)
{
	/*DEKLARASI*/
	int i;		//pencacah
	int k;		//pencacah
	int temp;	//penyimpan nilai sementara
	
	/*DESKRIPSI*/
	for(i=0; i<n-1; i++)	//perulangan untuk per pass nya
	{
		for (k=n-1; k>i; k--)	//perulangan untuk mengecek data dalam larik
		{
			if(L[k]>L[k-1])		//kondisi jika nilai yang akan dipindahkan adalah lebih besar
			{
				temp=L[k];		//proses pertukaran
				L[k]=L[k-1];
				L[k-1]=temp;
			}
		}
	}
}

void BinarySearch(LarikInt L, int n, int x, int *idx) //fungsi
{
	/*DEKLARASI*/
	int i, j;			//bantuan indeks
	int k;				//indeks elemen tengah
	boolean found;	//nilai found menyimpan true or false
	
	/*DESKRIPSI*/
	i=0;			//inisialisasi
	j=n-1;
	found=false;	//nilai diawali dengan false
	while (!found && i<=j)	//jika terpenuhi
	{
		k=(i+j)/2;
		if(L[k]==x)			//jika sama dengan
		{
			found=true;		//found bernilai benar
		}
		else				//jika berbeda
		{
			if(L[k]<x)		//jika lebih kecil akan masuk masuk ke bagian kiri
			{
				j=k-1;		//penentu indeks
			}
			else			//jika tidak, cek bagian kanan
			{
				i=k+1;		//penentu indeks awal
			}
		}
	}
	
	if(found)				//jika bernilai benar
	{
		*idx=k;				//idx diisi dengan indeks
	}
	else					//jika bernilai salah
	{
		*idx=-1;			//idx diisi dengan -1
	}
	
}
