#include<stdio.h>

void booleanMatrixJoint(int A[][30], int B[][30], int res[][30], int row, int col){

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(*(res+i)+j) = 0;
            if (*(*(A + i) + j) == 1 || *(*(B + i) + j) == 1)
            {
                *(*(res + i) + j) = 1;
            }
        }
    }
    
}
void booleanMatrixMeet(int A[][30], int B[][30], int res[][30], int row, int col){

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            *(*(res+i)+j) = 0;
            if (*(*(A + i) + j) == 1 && *(*(B + i) + j) == 1)
            {
                *(*(res + i) + j) = 1;
            }
        }
    }
}

void booleanMatrixProduct(int matrixA[][30], int matrixB[][30], int resMatrix[][30], int rowA, int colA, int rowB, int colB)
{
    //*(*(arr + i) + j)
    for(int i=0;i<rowA;i++)
    {
        for(int j=0;j<colB;j++)
        {
            *(*(resMatrix+i)+j) = 0;
            for(int k=0;k<rowB;k++)
            {
                *(*(resMatrix+i)+j) += *(*(matrixA+i)+k) * *(*(matrixB+k)+j);
            }
        }
    }
}
void display( int row,int col,int matrix[30][30]){
    int matrixd[30][30];
        for(int k=0; k<row; k++){
            for(int l=0; l<col; l++){
                matrixd[k][l]= matrix[k][l];
            }
        }

    for(int k=0; k<row; k++){
        for(int l=0; l<col; l++){
            if(matrixd[k][l]>1){
                matrixd[k][l] = 1;
            }
        }
    }
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            printf("%5d",matrixd[i][j]);
        }
        printf("\n");
    }
        printf("---------------------------------------------\n");
}
int main(){
    int rowA,colA,rowB,colB;
    printf("Enter number of row of matrix A: ");
    scanf("%d",&rowA);
    printf("Enter number of column of matrix A: ");
    scanf("%d",&colA);
    printf("Enter number of row of matrix B: ");
    scanf("%d",&rowB);
    printf("Enter number of column of matrix B: ");
    scanf("%d",&colB);


    printf("\n\n");

    if(colA == rowB){
        int matrixA[30][30],matrixB[30][30],resMatrixProduct[30][30];
        int resMatrixMeet[30][30], resMatrixJoint[30][30];

        printf("Enter the elements of matrix A[%d][%d]: \n",rowA,colA);                 //input element for matrix A
        for(int i=0;i<rowA;i++){
            for(int j=0; j<colA;j++){
                scanf("%d",&matrixA[i][j]);
            }
        }

        printf("\n\n");

        printf("Enter the elements of matrix B[%d][%d]: \n",rowB, colB);                //input element for matrix B
        for(int i=0;i<rowB;i++){
            for(int j=0; j<colB;j++){
                scanf("%d",&matrixB[i][j]);
            }

        }
        printf("\n");

        // system("clear");
        printf("The element of boolean matrix A[%d][%d]: \n",rowA,colA);
        display(rowA,colA,matrixA);
        printf("The element of boolean matrix B[%d][%d]: \n",rowB, colB);
        display(rowB,colB,matrixB);
        // printf("The element of matrix AB[%d][%d]: \n",rowA,colB);
    
        printf("The element of Boolean matrix meet is A ∧ B: \n");
        booleanMatrixMeet(matrixA,matrixB,resMatrixMeet,rowA,colA);
        display(rowA,colB,resMatrixMeet);

        printf("The element of Boolean matrix joint is A ∨ B: \n");
        booleanMatrixJoint(matrixA,matrixB,resMatrixJoint,rowA,colA);
        display(rowA,colB,resMatrixJoint);

        printf("The element of Boolean matrix Product is A ⊙ B: \n");
        booleanMatrixProduct(matrixA,matrixB,resMatrixProduct,rowA,colA,rowB,colB);
        display(rowA,colB,resMatrixProduct);

    }

    else{
        printf("Error!!! \n The number of column of matrixA and the number of row of matrixB must be equal!!!\n");
    }

}
