// Enes Karacabay

/*Sifreli metni ve cozum matrisinin isimlerini kullanicidan 
alip bu sifreleme yontemine gore sifreyi cozecek program*/

/*Gerekli kutuphaneler tanimlaniyor*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	/*gerekli dosya isimleri aliniyor*/
	char matris_txt_adi[30], sifreli_metin_txt_adi[30], desifre_txt_adi[30] ;

	/*Metni desifreleyecek matrisin ismi kullanıcıdan aliniyor*/
	printf("Matrisin yazildigi dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",matris_txt_adi);

	/*Sifre dosyasinin ismi kullanicidan aliniyor*/	
	printf("Sifrelenmis metni iceren dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",sifreli_metin_txt_adi);

	/*Desifre metninin yazilacagi txt ismi aliniyor*/
	printf("Sifresi cozulmus metni icerecek dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",desifre_txt_adi);

	/*Matris dosyasi aliniyor*/
	FILE *matris_txt;
	matris_txt = fopen(matris_txt_adi,"r");
	
	/*Eger yanlıs bir isim verilmisse program sonlandiriliyor*/
	if(matris_txt == NULL)
	{
		printf("\nERROR\nMatris dosyasi bulunamadi..\n");
		exit(1);
	}

	/*Matris ve diger degiskenler tanimlaniyor*/
	char matris[11][11];
	int i=0,j=0;
	
	/*Matris_txt ici gezilerek matris degiskenine aktariliyor */
	while(!feof(matris_txt))
	{	
		matris[i][j] = fgetc(matris_txt);
		if(matris[i][j]==10)
		{
			j=-1;
			i++;
		}	
		j++;
	}

	/*Matris dosyasi kapaniyor*/
	fclose(matris_txt);

	/*Sifre dosyasi aciliyor*/
	FILE *sifre_txt;
	sifre_txt = fopen(sifreli_metin_txt_adi,"r");
	
	/*Eger yanlıs bir isim verilmisse program sonlandiriliyor*/
	if(sifre_txt == NULL)
	{
		printf("\nERROR\nSifre dosyasi bulunamadi..\n");
		exit(1);
	}
	
	/*Desifre dosyasi aciliyor*/
	FILE *desifre_txt;
	desifre_txt = fopen(desifre_txt_adi,"w");
	
	/*sifre txt dosyasina bakilarak ve matris 
	kullanilarak desifreleme islemi yapiliyor*/
	int ch[2];
	int temp;
	i=0;
	while(!feof(sifre_txt))
	{	

		temp = fgetc(sifre_txt);
		ch[i] = temp - 49 ; //ascii kodundan 49 asagısı
		i++;
		if(i==2) 
		{
			fprintf(desifre_txt,"%c",matris[ch[0]][ch[1]]);
			i=0;
		}
		
	}

	/*Dosyalar kapatiliyor*/
	fclose(desifre_txt);
	fclose(sifre_txt);

	/*Onay metni ekrana bastiriliyor*/
	printf("Sifre cozme tamamlanmıştır\n");

	return 0; //islem basarili cikisi
}
