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

void insertion(data[], int);
void selection(data[], int);
void backup(data[], data[]);
int menu();

int main()
{
    data tampung[MAKS];
    int pilih, mode;
    data student[MAKS];
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
    backup(student,tampung);
    do
    {
        backup(tampung,student);
        printf("\n\nMenu Sorting\n");
        printf("1. Insertion\n");
        printf("2. Selection\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &pilih);
        switch(pilih)
        {
        case 1 :
            mode = menu();
            insertion(student, mode);
            break;

        case 2 :
            mode = menu();
            selection(student, mode);
            break;

        case 3 :
            exit(0);
            break;
        }
    }
    while(1);
    return 0;
}

void backup(data A[], data temp[])
{
    int i;
    for(i=0; i<MAKS; i++)
        temp[i] = A[i];
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

void insertion(data student[], int mode)
{
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
}

void selection(data student[], int mode)
{
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
}
