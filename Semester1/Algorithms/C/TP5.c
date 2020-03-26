/* TP5 Sotirios PAPADIAMANTIS */

#include <stdio.h>
#include <math.h>
#define  DIM 3
int count = 0;

/*Ex1*/
int pgcd(int a , int b)
{
    /* Returns greatest common divider of arguments a and b*/
    int gcd; // gcd variable
    int i;   // iterator


    for(i=1; i <= a && i <= b; ++i)
    {
        // Checks if i is factor of both integers
        if(a%i==0 && b%i==0)
            gcd = i;
    }

    return gcd;
}

/*Ex2*/
float power(float X , int N)
{
    /*Returns power of float base to int (positive)
     * using iteration*/

    // If n negative return
    if(N<0)
    {
        printf("N must be a positive number");
        return -1;
    }
    // Initialize result value
    float result = 1;

    while (N != 0)
    {
        //If N is even
        if (N%2 == 0)
        {
            X = X * X;
            N = N / 2;
        }
        else // If N is odd
        {

            result = result * X;
            N = N - 1;
        }
    }
    return result;
}


//function in (x-1)^2
/*Ex2*/
float zero(float a , float b )
{
    /* Returns zero for e error using dichotomy
     * between arguments a and b */

    float  epsilon = 0.00001f; // error variable
    float c;                   // current value

    // Check extremes
    if (power(a-1,2)<epsilon)
        return a;

    if (power(b-1,2)<epsilon)
        return b;

    // while absolute difference of a and b is greater than error
    while(fabs(a-b)>epsilon)
    {
        //  find middle and calculate error
        c=(a+b)/2.0f;
        if (fabs(power(c-1,2)) < epsilon)
        {
            return c;
        }
        else // If greater than error set c as extreme
        {
            if (power(a-1,2) - power(b-1,2) > 0.0f)
                a=c;
            else
                b=c;
        }
    }
    return 0;
}

/*Ex4*/

/* Print array function used in exercise*/
int printArray(float pary[][DIM])
{
    int r,c; //row and col counter

    for (r = 0; r < DIM; r++)
    {
        for (c = 0; c <DIM; c++)
        {
            printf("\t%f", pary[r][c]);
        }
        printf("\n");
    }
}

void matrix_product(float array1[][DIM], float array2[][DIM], float product[][DIM])
{

    /* Returns product of two square arrays of the same size*/
    int c,d,k;
    int sum = 0;

    // Calculate Matrix product( elem  = sum of line*col
    for (c = 0; c < DIM; c++) {
        for (d = 0; d < DIM; d++) {
            for (k = 0; k < DIM; k++) {
                sum = sum + array1[c][k]*array2[k][d];
            }

            product[c][d] = sum;
            sum = 0;
        }
    }
}


void arrIdentity(float out[DIM][DIM]) {
    /* initialize array to identity matrix. */
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            out[i][j] = (i == j);
        }
    }
}


void arrCopy(float mat[DIM][DIM], float out[DIM][DIM]) {
    /* copy a matrix. */
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            out[i][j] = mat[i][j];
        }
    }
}

void power_matrix(float X[][DIM] , int N,float result[][DIM])
{
    /*Calculates the power of a matrix using the method of ex2 and matrix product */
    float temp[DIM][DIM];
    if(N<0)
    {
        printf("N must be a positive number");
        return ;
    }


    if (N == 0)  // base case;
    {
        arrIdentity(result);
        return;
    }
    if(N==1)
    {
        arrCopy(X,result);
        return;
    }
    power_matrix(X, N/2,temp);

    if (N % 2 == 0)
    {
        count++;
        matrix_product(temp,temp,result);
        return;
    }
    else
    {
        count = count+2;
        float temp2[DIM][DIM];
        matrix_product(temp,temp,temp2);
        matrix_product(X,temp2,result);
        return;
    }

}
/*Ex6*/
int string_to_int(char table[])
{
    /* Reads an array of characters representing an int in decimal form
     * and returns it as int*/

    int i =0;                //iterator
    int nd = 0;              // number of chars
    int num = 0;             // result variable
    int flag = 0;            // flag used in case of negative value

    // If the number is negative raise flag
    if(table[0] == '-')
    {
        flag = 1;
        table[0]= '0';
    }

    // Read non decimal part
    while(table[i]!=',' && table[i]!='.' )
    {
        // Count chars
        i++;
    }

    // Set number of chars
    nd =i;

    // Initialize number variable
    num = 0;

    // For every char
    for(i = nd-1;i>=0;i--){
        // Augment numb by converting ascci value and multiplying by decimal power
        num =num + ((int)(table[i])-48)*power(10,nd-i-1);
    }

    // Return result
    if(flag)
        return -num;
    return num;
}

/*Ex7*/
void int__to_string(int num,char  buffer[], int nd)
{
    /* Turn int to table of chars in decimal form*/
    int i;

    // Initialize buffer
    for (i=25;i<25-nd;i--)
        buffer[i]=48;
    //printf("%c,",buffer[50]);

    buffer[25-nd-1] = ',';

    int flag = 0;
    if(num>0)
        flag = 1;

    i = 25-nd-1;
    while(num>nd)
    {
        buffer[i] = 48 + num%10;
        num = num/10;
        i--;
    }
    buffer[i] = num+48;

    return;

}

int main(void)
{


    float  product[DIM][DIM];
    float  array1[DIM][DIM] = {{2,4,6},
                               {12,14,16},
                               {22,24,26}};

    float array2[DIM][DIM]= {{2,4,6},
                             {12,14,16},
                             {22,24,26}};

    //matrix_product(array1,array2,product);



    char dec[25];
    char buffer[25];
    int i;


    int choice = -1;
    int input1,input2;
    float inputf;
    printf("---------------TP3------------------\n");
    while(choice!=0){
        printf("Choose question number.\n");
        printf("1. Print greatest common divider \n");
        printf("2. Print power number (fastest method)\n");
        printf("3. Find zeros of function (x-1)^2\n");
        printf("4. Print Matrix product \n");
        printf("5. Print Quick matrix power\n");
        printf("6. Table of chars to Int\n");
        printf("7. Int to table of chars\n");
        printf("0. To exit\n");
        scanf("%d", &choice);
        printf("\n");

        switch(choice)
        {
            case 0:
                printf("Exiting program!! \n");
                break;
            case 1: /*Ex1 print greatest common divider */
                printf("First Number for GCD:\n");
                scanf("%d",&input1);
                printf("Second Number for GCD:\n");
                scanf("%d",&input2);
                printf("GCD is:  %d \n",pgcd(input1,input2));
                printf("\n");
                break;
            case 2:/*Ex2 power*/
                printf("Give Base:\n");
                scanf("%f",&inputf);
                printf("Give power:\n");
                scanf("%d",&input2);
                printf("\n");
                printf("Result is:  %f \n",power(inputf,input2));
                printf(" with %d multiplications\n",count);
                count =0;
                break;
            case 3: /*Ex3 Find zeros of Function*/
                printf("The zero of (x-1)^2 in [0,2] is %f\n",zero(0,2));
                printf("\n");
                break;
            case 4: /*Ex4 print matrix product*/
                printf("for first array:\n");
                printArray(array1);
                printf("for second array:\n");
                printArray(array2);
                matrix_product(array1,array2,product);
                printf("This is the product\n");
                printArray(product);
                break;
            case 5: /*Ex6 Quick power matrix*/
                printf("for array:\n");
                printArray(array1);
                printf("And exponent of 2\n");
                power_matrix(array1,2,product);
                printf("This is the result:\n");
                printArray(product);
                break;
            case 6:/*Ex6 String to Int*/
                printf("Give decimal in string form\n");
                scanf("%s",dec);
                printf(" this int is %d\n",string_to_int(dec));
                break;
            case 7:/*Ex7 Int to string*/
                printf("Enter int to convert\n");
                scanf("%d",&input1);
                int__to_string(input1,buffer,5);
                printf("this is a string %s\n",buffer);
                break;
            default:
                printf("Wrong Choice. Enter again!\n");
                break;

        }
    }

}