// Enes Karacabay

/*Dosyadan alinan bir metin yine dosyadan alinan bir 
matrise gore sifrelenip bir dosyaya aktariliyor */

/*gerekli kutuphaneler tanimlaniyor*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
	/*gerekli dosya isimleri aliniyor*/
	char matris_txt_adi[30],metin_txt_adi[30],sifre_txt_adi[30];

	/*Metni sifreleyecek matrisin ismi kullanıcıdan aliniyor*/
	printf("Matrisin yazildiği dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",matris_txt_adi);

	/*Sifrelenecek metin kullanicidan aliniyor*/
	printf("Sifrelenecek metni iceren dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",metin_txt_adi);

	/*Sifre metninin yazilacagi dosya ismi aliniyor*/
	printf("Sifrelenmis metni icerecek dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",sifre_txt_adi);

	/*Matris dosyasi aliniyor*/
	FILE *matris_txt;
	matris_txt = fopen(matris_txt_adi,"r");

	/*Eger yanlıs bir isim verilmisse program sonlandiriliyor*/
	if(matris_txt == NULL)
	{
		printf("\nERROR\nMatris dosyasi bulunamadi..\n");
		exit(1);
	}	

	/*Matris ve degiskenler tanimlaniyor*/
	char matris[11][11];
	int i=0,j=0;

	/*Matris dosyasinin icindeki matris, matris 
	degiskenine aktariliyor*/
	while(!feof(matris_txt))
	{	
		matris[i][j] = fgetc(matris_txt);
		/*Eger satir sonu ise matrisin diger satirina geciliyor.*/
		if(matris[i][j]==10) 
		{
			j=-1;
			i++;
		}	
		j++;
	}

	/*Matris dosyasi kapaniyor*/
	fclose(matris_txt);

	/*Metnin bulundugu dosya aciliyor*/
	FILE *metin_txt;
	metin_txt = fopen(metin_txt_adi,"r");

	/*Eger yanlıs bir isim verilmisse program sonlandiriliyor*/
	if(metin_txt == NULL)
	{
		printf("\nERROR\nSifrelenecek metin dosyasi bulunamadi..\n");
		exit(1);
	}

	/*Sifre dosyasi olusturuluyor*/
	FILE *sifre_txt;
	sifre_txt = fopen(sifre_txt_adi,"w");

	/*Metnin ici gezilerek sifre_txt'ye sifrelenerek yaziliyor*/
	char ch;
	i = 0;
	while(!feof(metin_txt))
	{
		ch = fgetc(metin_txt);
		if(ch==10)
		{
			fprintf(sifre_txt,"\n");
		}
		else
		{
			for(i=0;i<10;i++)
			{
				for (j=0;j<10;j++)	
				{
					if(ch==matris[i][j])
					{
						i++;
						j++;
						fprintf(sifre_txt,"%d%d",i,j);
						i=9;j=9;
					}
					
				}
				
			}
		}	
	}


	/*Dosyalar kapaniyor*/
	fclose(sifre_txt);
	fclose(metin_txt);

	//islemin basarili oldugunu gosteren metin yazdiriliyor.
	printf("\nSifreleme tamamlanmıstır.\n");

	return 0; //islem basarili cıkısı
}
