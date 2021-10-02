/*takes two sets as input and produces their Cartesian product as output.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void CartProduct(int arr1[],int arr2[],int n1, int n2){
	int i,j;
	printf("{");
	for(i=0; i < n1; i++){
		for(j=0; j < n2; j++){
            if (i<n1-1){
                printf(" (%d,%d)",arr1[i],arr2[j]);
            }
            else if (i== n1-1){
                printf(" (%d,%d)",arr1[i],arr2[j]);
            }
		}
	}
	printf("}\n");
}

void display(int set[],int size){
	int i,j,k;
	printf("{");
	for(i=0;i<size;i++){

		if(i<size-1){
			printf("%d, ",set[i]);
		}
		else if (i==size-1){
			printf("%d",set[i]);
		}
	}
	printf("}\n\n");
}
int main(){
	int n1,n2,i,j;

	printf("Enter the size of Set A : ");	scanf("%d",&n1);
	printf("Enter the size of Set B: ");	scanf("%d",&n2);
    int setA[n1],setB[n2];
	printf("Enter the elements of Set A:\n");
	for(i=0; i<n1; i++){
		scanf("%d",&setA[i]);
	}
	printf("Enter the elements of Set B :\n");
	for(j=0;j<n2;j++){
		scanf("%d",&setB[j]);
	}
    
    printf("The elements of setA: \n");
    display(setA,n1);
    printf("The elements of setB: \n");
    display(setB,n2);

	printf("The Cartesain Product of Set A and Set B is: \n ");
	CartProduct(setA,setB,n1,n2);
	return 0;
}
