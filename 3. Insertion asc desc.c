#include <stdio.h>
#include <stdlib.h>
#define MAKS 5
#define batas 88

typedef struct
{
    int no;
    char nama[batas];
    int nilai;
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
        gets(student[i].nama);
        fflush(stdin);
        printf("Nilai: ");
        scanf("%d", &student[i].nilai);
        fflush(stdin);
    }
    int mode=menu();
    for(int i=1; i<MAKS; i++)
    {
        if(mode==1)
        {
            for(int j=i; j>0 && student[j].no<student[j-1].no; j--)
            {
                data temp=student[j-1];
                student[j-1]=student[j];
                student[j]=temp;
            }
        }
        else
        {
            for(int j=i; j>0 && student[j].no>student[j-1].no; j--)
            {
                data temp=student[j-1];
                student[j-1]=student[j];
                student[j]=temp;
            }
        }
    }
    printf("\nSetelah diurutkan: \n");
	for(int i=0; i<MAKS; i++){
		printf("%d %s %d\n", student[i].no, student[i].nama, student[i].nilai);
	}
    return 0;
}

int menu()
{
    int pilih;
    printf("\nMode Urut\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Masukkan pilihan: ");
    scanf("%d", &pilih);
    return pilih;
}
