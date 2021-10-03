/*takes two sets as input and produces set operations like union, intersection, difference and symmetric difference as its output.*/

#include<stdio.h>
#include<stdlib.h>

int set_union(int setA[], int m, int setB[], int n, int UNION[])
{
	int i,j,k=0;

	for(i=0;i<m;i++){
		UNION[k]=setA[i];
		k++;
	}
	for(i=0;i<n;i++){
		int flag=1;
		for(j=0;j<m;j++){
			if(setA[j]== setB[i]){
				flag = 0;
				break;
			}
		}
		if(flag ==1){
			UNION[k] = setB[i];
			k++;
		}

	}
	return (k);
}


int Intersection(int setA[],int m,int setB[],int n,int INTER[]){

    int i,j,k=0;

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(setA[i]==setB[j]){
                INTER[k]=setA[i];
                k++;
            }
        }
    }
    return k;

}

int Difference(int setA[],int m, int setB[],int n,int DIFF[]){
    int i,j,k=0;

    for(i=0;i<m;i++){
        int flag=0;
        for(j=0;j<n;j++){
            if(setA[i]==setB[j]){
                flag =1;
                break;
            }

        }
        if (flag == 0){
            DIFF[k++]=setA[i];
        }
    }
    return k;
}

int Symmetric(int setA[],int m,int setB[],int n,int SYMM[]){
    int k = set_union(setA,m,setB,n,SYMM);
	return k;
}

void element(int set[],int size){
	int i;
	for(i=0;i<size;i++){
		scanf("%d",&set[i]);
	}
}

void display(int set[],int size){
	int i;
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

void bubblesort(int set[], int size){
	int i, j,temp;

	for(i=0;i<size-1;i++){
		for(j=0;j<size-i-1;j++){
			if ( set[j]>set[j+1]){
				temp = set[j+1];
				set[j+1] = set[j];
				set[j] = temp;
			}
		}
	}
}

int main(){
	int m,n,UNION[40],DIFFA[40],DIFFB[40], INTER[40],SYMM[40];
	int union_num,inter_num,diff_numA,diff_numB,symm_num;
	printf("Enter size of set A: ");	scanf("%d",&m);
	printf("Enter size of set B: ");	scanf("%d",&n);
	int setA[m], setB[n];

	printf("Enter the elements of setA: \n");
	element(setA, m);
	bubblesort(setA,m);
	printf("Enter the elements of setB: \n");
	element(setB, n);
	bubblesort(setB,n);
	

	//displaying the elemensts of set A and set B
	printf("The Elements of the setA: \n");
	display(setA,m);
	printf("The Elements of the setB: \n");
	display(setB,n);

	//union set operation
	printf("The union of setA and setB: \n");
	union_num = set_union(setA,m,setB,n,UNION);
	bubblesort(UNION,union_num);
	display(UNION,union_num);

	//intersection set operation
	printf("The intersection of setA and setB: \n");
    inter_num = Intersection(setA,m,setB,n,INTER);
	bubblesort(INTER,inter_num);
	display(INTER,inter_num);


	//difference set operation
	printf("The difference of setA and setB (SetA - SetB): \n");
	diff_numA = Difference(setA,m,setB,n,DIFFA);
	bubblesort(DIFFA,diff_numA);
	display(DIFFA, diff_numA);

	//difference set operation
	printf("The difference of setA and setB (SetB - SetA): \n");
	diff_numB = Difference(setB,m,setA,n,DIFFB);
	bubblesort(DIFFB,diff_numB);
	display(DIFFB,diff_numB);


    //symmetric difference set opration
    printf("The symmetric difference of setA and setB ((SetA - SetB) U (SetB - SetA)) : \n");
    symm_num = Symmetric(DIFFA,diff_numA,DIFFB,diff_numB,SYMM);
    bubblesort(SYMM,symm_num);
    display(SYMM, symm_num);

}
