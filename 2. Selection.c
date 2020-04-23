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
    int i,j, min;
    for(i=0; i<MAKS-1; i++)
    {
        min = i;
        j = i+1;
        while(j<MAKS)
        {
            if(student[j].no < student[min].no)
                min = j;
            j++;
        }
        data temp = student[i];
        student[i] = student[min];
        student[min] = temp;
    }

    printf("\nSetelah diurutkan: \n");
	for(int i=0; i<MAKS; i++){
		printf("%d %s %d\n", student[i].no, student[i].nama, student[i].nilai);
	}

    return 0;
}
