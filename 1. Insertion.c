#include <stdio.h>
#include <stdlib.h>
#define MAKS 5
#define batas 88

typedef struct
{
    int no;
    char nama[batas];
    char nilai;
}data;

int main()
{
    data student[5];
    printf("Masukkan Data\n");
    for(int i=0;i<MAKS;i++)
    {
        printf("No: ");
        scanf("%d", &student[i].no);
        fflush(stdin);
        printf("Nama: ");
        scanf("%s", &student[i].nama);
        fflush(stdin);
        printf("Nilai: ");
        scanf("%c", &student[i].nilai);
        fflush(stdin);
    }
    for(int i=1; i<MAKS; i++){
		for(int j=i; j>0 && student[j].no<student[j-1].no; j--){
			data temp=student[j-1];
			student[j-1]=student[j];
			student[j]=temp;
		}
	}
    printf("\nSetelah diurutkan: \n");
	for(int i=0; i<MAKS; i++){
		printf("%d %s %c\n", student[i].no, student[i].nama, student[i].nilai);
	}
    return 0;
}
