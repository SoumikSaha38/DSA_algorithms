#include <stdio.h>
#include <stdlib.h>
int main()
{
    int arr1[10][10], row1, col1, k1 = 0, size1 = 0;
    printf("Enter number of rows in the first matrix : ");
    scanf("%d", &row1);
    printf("Enter number of columns in the first matrix : ");
    scanf("%d", &col1);

    printf("Enter elements in the matrix : ");
    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            scanf("%d", &arr1[i][j]);

    printf("The matrix is: \n");

    for (int i = 0; i < row1; i++)
    {
        for (int j = 0; j < col1; j++)
        {
            printf(" %d ", arr1[i][j]);
            if (arr1[i][j] != 0)
                size1++;
        }
        printf("\n");
    }

    int M1[3][size1];

    for (int i = 0; i < row1; i++)
        for (int j = 0; j < col1; j++)
            if (arr1[i][j] != 0)
            {
                M1[0][k1] = i;
                M1[1][k1] = j;
                M1[2][k1] = arr1[i][j];
                k1++;
            }

    int arr2[10][10], row2, col2, k2 = 0, size2 = 0;
    printf("Enter number of rows in the second matrix : ");
    scanf("%d", &row2);
    printf("Enter number of columns in the second matrix : ");
    scanf("%d", &col2);

    printf("Enter elements in the matrix : ");
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++)
            scanf("%d", &arr2[i][j]);

    printf("The matrix is: \n");

    for (int i = 0; i < row2; i++)
    {
        for (int j = 0; j < col2; j++)
        {
            printf(" %d ", arr2[i][j]);
            if (arr2[i][j] != 0)
                size2++;
        }
        printf("\n");
    }

    int M2[3][size2];
    for (int i = 0; i < row2; i++)
        for (int j = 0; j < col2; j++)
            if (arr2[i][j] != 0)
            {
                M2[0][k2] = i;
                M2[1][k2] = j;
                M2[2][k2] = arr2[i][j];
                k2++;
            }

    printf("Triplet representation of the first matrix is \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size1; j++)
            printf(" %d ", M1[i][j]);
        printf("\n");
    }

    printf("Triplet representation of the second matrix is \n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < size2; j++)
            printf(" %d ", M2[i][j]);
        printf("\n");
    }

    if (size1 = size2)
    {
        int sum[3][k1];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j<size1; j++)
            {
                sum[i][j] = M1[i][j] + M2[i][j];
            }
        }
        printf ("The sum of the triplet matrices is: \n");
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j<size1; j++)
            {
                printf ("%d ", sum[i][j]);
            }
            printf ("\n");
        }
    }

    else
    printf ("Addition between the two matrices is not possible.");
    return 0;
}