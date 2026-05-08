#include <stdio.h>
main()
{
    printf("TUGAS 1");
    printf("\n");

    int A[3][2], B[3][2], C[3][2], i, j;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("input data Matriks A[%i][%i]:", i, j);
            scanf("%i", &A[i][j]);
        }
    }
    printf("\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("input data Matriks B[%i][%i]:", i, j);
            scanf("%i", &B[i][j]);
        }
    }
    printf("\n");

    printf("MATRIKS A: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%4i", A[i][j]);
        }
        printf("\n");
    }

    printf("MATRIKS B: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%4i", B[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Hasil Matriks A + B: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%4i", C[i][j]);
        }
        printf("\n");
    }
}