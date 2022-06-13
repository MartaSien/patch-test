#include  <stdio.h> 
#define TABLE_SIZE 20 

static int getNext(void)
{
    static int s_Table[TABLE_SIZE] =
    {
        1,  3,  8,  28, 29,

        18, 24, 30, 12, 30,

        8,  10, 17, 2,  17,

        3,  4,  29, 6,  3,
    };

    static int i = 0;
    int retVal;

    if (i < TABLE_SIZE)
    {
        retVal = s_Table[i++];
    }
    else
    {
        retVal = -1;
    }

    return retVal;
}

void sortTable(int* myTable)
{
    for (int i = 0; i < (TABLE_SIZE - 1); i++) {
        for (int j = i; j > 0; j--) {
            if (myTable[j] > myTable[j + 1]) {
                int temp_value;
                temp_value = myTable[j + 1];
                myTable[j + 1] = myTable[j];
                myTable[j] = temp_value;
            }
        }
    }
    return 0;
}

void printTable(int* myTable)
{
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("%d\n", myTable[i]);
}

int main(void)
{
    int myTable[TABLE_SIZE];

    for (int i = 0; i < TABLE_SIZE; i++) {
        myTable[i] = getNext();
    }

    printf("UNSORTED TABLE:\n");
    printTable(&myTable);

    sortTable(&myTable);

    printf("\nSORTED TABLE:\n");
    printTable(&myTable);

    return 0;
}