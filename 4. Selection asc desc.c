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

int menu();

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
    int i, j, minmax;
    for (i = 0; i < MAKS - 1; i++)
    {
        minmax = i;
        if (mode == 2)
        {
            for (j = i + 1; j < MAKS; j++)
            {
                if (student[j].no > student[minmax].no)
                    minmax = j;
            }
        }
        else
        {
            for (j = i + 1; j < MAKS; j++)
            {
                if (student[j].no < student[minmax].no)
                    minmax = j;
            }
        }
        data temp = student[i];
        student[i] = student[minmax];
        student[minmax] = temp;
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
