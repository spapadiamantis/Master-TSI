#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INT_MAX 100

int chemin[20];

float power( float base, int exponent)

{   // Does not work for negative exponents. (But that would be leaving the range of int)
    if (exponent == 0) return 1;  // base case;
    float temp = power(base, exponent/2);
    if (exponent % 2 == 0)
        return temp * temp;
    else
        return (base * temp * temp);
}



int Combinaisons(int p , int n){

    if(p==0 || p==n)
        return 1 ;
    else if( p>0 && p <n)
        return (Combinaisons(p-1,n-1) + Combinaisons(p,n -1));
    else
        return 0;


}

int palindrome_iter(char *s, int debut, int fin)
{
    // iterative solution
    int i,j;
    i = debut;
    j = fin-1;
    int flag = 1;

    while(j!=i && flag)
    {

        if(s[i] != s[j])
        {
            flag = 0;
        }

        i++;
        j--;
    }

    return flag;

}

int palindrome_rec(char *s, int debut, int fin)
{

    if(debut == fin)
        return 1;

    if (s[debut] != s[fin])
        return 0;

    if (debut < fin + 1)
        return palindrome_rec(s, debut + 1, fin - 1);

    return 1;
}

void mirror(void)
{
    char c;

    scanf("%c",&c);

    if(c == '?')
    {
        printf("%c",c);
        return;
    }

    mirror();

    printf("%c",c);
    return;
}


void swap(char *x, char *y)
{
    char temp;

    temp = *x;

    *x = *y;

    *y = temp;


}


void permute(char *a, int l, int r) {
    int i;
    if (l == r)
        printf("%s\n", a);
    else {

        for (i = l; i <= r; i++) {
            swap((a+l), (a+i));
            permute(a, l + 1, r);

            swap(&a[l], &a[i]);

        }
    }
}


int main(void)
{

    float inputf;
    int input1, input2;
    char buffer[50];
    char *test = (char *) malloc((strlen("esoperesteicietserepose") + 1) * sizeof(char));
    strcpy(test, "esoperesteicietserepose");
    // Making a graph

    int M[5][5] = {
            {0,10,20,INT_MAX,INT_MAX},
            {10,0,5,12,INT_MAX},
            {20,5,0,INT_MAX,18},
            {INT_MAX,12,INT_MAX,0,20},
            {INT_MAX,INT_MAX,18,20}
    };
    int choice = -1;
    printf("---------------TP3------------------\n");

    while(choice!=0)
    {
        printf("Choose question number.\n");
        printf("1. Exercise 1\n");
        printf("2. Exercise 2\n");
        printf("3. Exercise 3 \n");
        printf("4. Exercise 4\n");
        printf("5. Exercise 5 \n");
        printf("6. Exercise 6 \n");
        printf("0. To exit\n");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {

            case 0:
                printf("Exiting program!! \n");
                break;
            case 1:/*Ex2 power*/
                printf("Give Base:\n");
                scanf("%f",&inputf);
                printf("Give power:\n");
                scanf("%d",&input2);
                printf("\n");
                printf("Result is:  %f \n",power(inputf,input2));
                break;
            case 2:/*Ex1 Combinations*/
                printf("First Number for combinations:\n");
                scanf("%d", &input1);
                printf("Second Number for combinations:\n");
                scanf("%d", &input2);
                printf("%d\n", Combinaisons(input1, input2));
                break;
            case 3: /*Ex2 Recursive palindrome*/

                printf("%d\n", palindrome_rec(test, 0, strlen(test) - 1));
                break;
            case 5: /*Ex3 string permutation*/
                strcpy(buffer, "abc");
                permute(buffer, 0, 2);
                break;
            case 4:
                mirror();
                break;
            default:
                printf("Wrong Choice. Enter again!\n");
                break;


        }
    }
}