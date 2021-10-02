#include <stdio.h>

//Euclidean Algorithm
void Euclidean(int a,int b){

    int rem,quo;
    printf("\n");
    while(b>0){
        rem = a%b;
        quo = a/b;
        printf("%d = %d x %d + %d \n",a,b,quo,rem);
        a = b;
        b=rem;
    }
    printf("\nSo, The GCD is %d\n",a);
}

//Extended Euclidean algorithms
int gcdExtended(int a, int b, int* x, int* y)
{
	// Base Case
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; 
	int gcd = gcdExtended(b % a, a, &x1, &y1);


	*x = y1 - (b / a) * x1;
	*y = x1;
	return gcd;
}

int main()
{
	int x, y;
	int a, b;

	printf("Enter two numbers: ");
	scanf("%d %d", &a, &b);

	printf("\nBy Euclidean Algorithm: \n");
	Euclidean(a, b);
	printf("\n\nBy Extended Euclidean algorithm: \n\n");
	int g = gcdExtended(a, b, &x, &y);
	printf("gcd(%d, %d) = %d\n\n", a, b, g);
	printf("(%d)*(%d) + (%d)*(%d) = %d\n", x, a, y, b, g);
	printf("x = %d  y = %d\n\n", x, y);

	return 0;
}
