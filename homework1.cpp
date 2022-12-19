#include <stdio.h>
#include <stdlib.h>

void matmul(int **A, int **B, int **C, int n, int k, int m)
{
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < m; j ++)
        {
            C[i][j] = 0;
            // **** Fill the content here for multiplication (4)
            
            for(int q = 0; q < k; q++){
                C[i][j] += A[i][q] * B[q][j];
            }
            
            // End of the multiplication
        }
}   

void printOut(int ** matrix, int row, int col)
{
    printf("\n Result of C:\n");
    for (int i = 0; i < row; i ++)
    {
        for (int j = 0; j < col; j ++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int args, char **argv)
{
    // To process the input in order to derive the size of the matrix.
    printf("Input format:/path/exe n k m\n");
    int n=1, k=1, m=1;
    
    /* 
    * Content (1), input the value for the n, k, m. Hint: use "scanf" 
    n = row of a k = col of A, row of b, m = col of b
    *
    */
    
    printf("Enter a size n (rows of Matrix A): ");
    scanf("%d", &n);
    printf("Enter a size k (columns of A, rows of B): ");
    scanf("%d", &k);
    printf("Enter a size m(columns of B): ");
    scanf("%d", &m);
    
    
    /* End of the Content (1) */
    
    printf("Multiplying %dx%d matrix with %dx%d matrix.\n", n, k, k, m);
    
    // Allocate the matrix
    int** A = new int*[n];
    
    // printf("Pointer value: %ld\n", A);
    
    //
    int **B = new int*[k];
    int **C = new int*[n];
    
    for(int i = 0; i < n; i ++)
        A[i] = new int[k];
    for(int i = 0; i < k; i ++)
        B[i] = new int[m];
    for(int i = 0; i < n; i ++)
        C[i] = new int[m];
    
    // Initialize the value of A and B matrices
    printf("A:\n");
    for(int i = 0; i < n; i ++)
    {
        for(int j = 0; j < k; j ++)
        {
            A[i][j] = 0;
            /* 
            * Content (2), Initial the value of A. Hint: use rand() function and % 9.
            *
            */
            
            A[i][j] = rand()%9;
            
            /* End of the Content (2) */
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
            
    printf("\nB:\n");
    for(int i = 0; i < k; i ++)
    {
        for(int j = 0; j < m; j ++)
        {
            
            B[i][j] = 0;
            /* 
            * Content (3), Initial the value of B. Hint: use rand() function and % 9.
            *
            */
            
            B[i][j] = rand()%9;
            
            /* End of the Content (3) */
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    // Finish initialization of A and B
    
    // Matrix Multiplication
    matmul(A, B, C, n, k, m);
    
    // Print out result
    printOut(C, n, m);
    return 0;
}


