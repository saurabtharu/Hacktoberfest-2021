#include<stdio.h>
#include<stdlib.h>

// C function for extended Euclidean Algorithm
int gcdExtended(int a, int b, int* x, int* y)
{
	// Base Case
	if (a == 0) {
		*x = 0;
		*y = 1;
		return b;
	}

	int x1, y1; // To store results of recursive call
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	// Update x and y using results of recursive
	// call
	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}
void GCD(int a,int b){

    int rem,quo;
    printf("\n");
    while(b>0){
        rem = a%b;
        quo = a/b;
        printf("\
                %d = %d x %d + %d \n",a,b,quo,rem);
        a = b;
        b=rem;
    }
    // printf("\nSo, The GCD is %d\n",a);
}

int main(){

	int x, y;
	int a, b, m;

    printf("The linear congurence is in the form of \n ax ≡ b (mod m) \n\n");

    printf("Enter the value of a : ");
    scanf("%d", &a);
    printf("Enter the value of b : ");
    scanf("%d", &b);
    printf("Enter the value of m : ");
    scanf("%d", &m);

    printf("\nLet, v be the inverse of %d modulo %d\n\n", a, m);
    printf("The linear congurence is in the form of \n\
                         %dx ≡ %d (mod %d) . . . . . [i]", a, b, m);

    printf("\nHere, we can express it as: %dy + %dw = 1 . . . . . [ii] \n\
                                where w be any integer\n", a, m);

    int g = gcdExtended(a, m, &y, &x);


    printf("\nBy Euclidean Algorithm");
    GCD(a, m);
    
    printf("\ngcd(%d, %d) = %d\n", a, m, g);

    if ((b%g)!=0){

        printf("since, and gcd = %d does not divide %d i.e. %d !| %d\n\
        %dx ≡ %d (mod %d)  is not  solvable\n\n",g, b, g, b, a, b, m);

        exit(0);
    }
    
    printf("since, and gcd = %d divides %d i.e. %d | %d\n\
        %dx ≡ %d (mod %d)  is solvable\n\n",g, b, g, b, a, b, m);


    printf("Now,\n\
    by Extened Euclidean algorithm, we get\n");
    printf("\
            (%d)*(%d) + (%d)*(%d) = %d\n\n", a, y, m, x, g);

    printf("Comparing it with equation [ii]\n\
                y = %d\n\
        And,\n\
            (%d)*(%d) ≡ 1 (mod %d)\n",y,a,y,m);


    if (y<0)
    {
        printf("or,\n\
            (%d)*(%d + %d) ≡ 1 (mod %d)\n\
            (%d)*(%d) ≡ 1 (mod %d)\n\n",a,y,m,m,a,y+m,m);
        y = y + m;

    }

    printf("So, %d is the inverse of %d modulo %d\n", y, a, m);

    printf("Now,\n\
        multiplying %dx ≡ %d (mod %d) by %d ,we get\n",
           a, b, m, y);

    printf("\
            %d*%dx ≡ %d*%d (mod %d)\n",y,a,y,b,m);
    printf("\
            %dx ≡ %d (mod %d)\n",(y * a) % m, y * b, m);
    printf("\
            %dx ≡ %d (mod %d) is a solution for the linear congruence of ",(y * a) % m, (y * b) % m, m);
    printf("%dx ≡ %d (mod %d)\n\n", a, b, m);

    return 0;
}