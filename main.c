#include<stdio.h>
#include<stdlib.h>
typedef struct Takimlar
{
	char takimad[20];
	int takimpuan;
}Takim;
int main()
{
	FILE *dosya;
	Takim *takimlar;
	int i,sayac=0;
	dosya=fopen("ligler.txt","r");
	if(dosya==NULL)
	{
		printf("\ndosya okunmak icin acilamadi\n");
		return -1;
	}
	printf("\nDosyadan okunan takim bilgileri:\n");
	printf("\nTakim Ad:  Takim Puan:\n");
	while(!feof(dosya))
	{
		sayac++;
		if(sayac==1)
		{
			takimlar=(Takim*)malloc(sayac*sizeof(Takim));

		}
		else
		takimlar=(Takim*)realloc(takimlar,sayac*sizeof(Takim));
		i=sayac-1;
		fscanf(dosya,"%s %d",(takimlar+i)->takimad,&(takimlar+i)->takimpuan);
		printf("%s\t\t%d\n",(takimlar+i)->takimad,(takimlar+i)->takimpuan);
	}
	fclose(dosya);
	printf("Takim bilgileri dosyadan okunup struct dizisine aktarildi\n");

getch();
system("cls");

}
