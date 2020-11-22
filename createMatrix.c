// Enes Karacabay

/*Belirledigimiz karakterleri random sekilde bir matrise
atayıp bu matrisi alinan dosya adında bir txt dosyasi olusturup
icine yerlestiren modulumuz*/

/*gerekli kutuphaneler tanimlaniyor*/
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	/*degiskenler tanımlanıyor*/
	int satir_boyutu, sutun_boyutu, satir, sutun, i, j;
	int BUYUK_HARF_ASCII=65, kucuk_harf_ascii=97, diger_karakterler[3]={32,44,46};
	char **matris, matris_txt_adi[20];
	
	/*random fonksiyonu icim srand time fonksiyonu cagrılıyor*/
	srand(time(NULL));
	
	/*matrisin yazdirilacagi dosya adi aliniyor*/
	printf("Matrisin yazilacagi dosya ismini uzantisi ile birlikte veriniz\n");
	scanf("%s",matris_txt_adi);
	
	/*matrisin boyutlari istenilen değerlerde olana kadar aliniyor*/
	i=0;
	while (i<1)
	{
		printf("Matrisin satir ve sutun sayisini ayni sira ile veriniz\n");
		scanf("%d %d",&satir_boyutu,&sutun_boyutu);
		if(satir_boyutu*sutun_boyutu <55)
		{
			printf("Carpimlari 55'ten buyuk olmalıdır..\n");
			continue;	
		}
		if (sutun_boyutu > 10 || satir_boyutu > 10)
		{
			printf("herhangi bir boyut 10'dan buyuk olamaz..\n");	
			continue;
		}
		i++;
	}
	
	/*calloc kullanilarak verilen boyutlarda bir matris olusturuluyor*/
	matris = (char **)calloc(satir_boyutu,sizeof(char*));
	for (i=0;i<satir_boyutu;i++)
	{
		matris[i]=(char*)calloc(sutun_boyutu,sizeof(char));
	}
	
	/*matrise random bir sekilde buyuk harfler yerlestiriliyor*/
	i=0;
	while (i<26)
	{
		satir=(rand()%(satir_boyutu));
		sutun=(rand()%(sutun_boyutu));

		if (matris[satir][sutun]==0)
		{
			matris[satir][sutun]=BUYUK_HARF_ASCII;
			i++;
			BUYUK_HARF_ASCII++;
		}
	}	
	
	/*matrise random bir sekilde kucuk harfler yerlestiriliyor*/
	i=0;
	while (i<26)
	{
		satir=(rand()%(satir_boyutu));
		sutun=(rand()%(sutun_boyutu));
		if (matris[satir][sutun]==0)
		{
			matris[satir][sutun]=kucuk_harf_ascii;
			i++;
			kucuk_harf_ascii++;
		}
	}

	/*matrise random bir sekilde ". ," karakterleri yerlestiriliyor*/
	i=0;
	while (i<3)
	{
		satir=(rand()%(satir_boyutu));
		sutun=(rand()%(sutun_boyutu));
		if (matris[satir][sutun]==0)
		{
			matris[satir][sutun]=diger_karakterler[i];
			i++;
		}
	}

	/*adi verilen verilen matris_txt dosyasi 'w' (write) kipinde aciliyor*/
	FILE *matris_txt;
	matris_txt = fopen(matris_txt_adi, "w");


	/*matrisimiz matris dosyasina yaziliyor*/
	for (i=0;i<satir_boyutu;i++)
	{
		for (j=0;j<sutun_boyutu;j++)
		{
			if (matris[i][j]==0)
			{
				fprintf(matris_txt,"*");
			}
			else
			{
				fprintf(matris_txt,"%c",matris[i][j]);
			}
		}

		fprintf(matris_txt,"\n");
	}
	// matris dosyamiz kapaniyor
	fclose(matris_txt);

	//islemin basarili oldugunu gosteren metin yazdiriliyor.
	printf("Sifre matrisi dosyasi olusturuldu..\n");	

	return 0; //islem basarili cıkısı
}
