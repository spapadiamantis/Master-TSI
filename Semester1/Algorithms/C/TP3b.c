/* TP3bis Sotirios PAPADIAMANTIS */
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define PI 3.14159265

/*Ex1*/


/*Function from first TP*/
float addtaxes(float price)
{
    /*Adds taxes to input tax - 20%*/
    float full_price = price + price*0.2;
    return full_price;
}


void addtaxesmod()
{
    /* Adds taxes to prices read from stdin
     and exits for price 0 showing how many calculations
     were performed*/


    float prix = 0;    // price
    int i =0;          // counter for calculations
    float sumHC= 0;    // Sum before tax
    float sumTTC = 0;  // Sum after tax

    // Scan price
    printf("Enter price to convert, 0 to exit\n");
    scanf("%f",&prix);

    // Until price is 0
    while(prix!= 0)
    {

        // Calculate price after tax
        float prixTTC= addtaxes(prix);

        // Augment calculations counter
        i++;

        // Print result
        printf("Prix TTC %f",prixTTC);

        // Add to sums
        sumHC = sumHC + prix;
        sumTTC = sumTTC + prixTTC;

        // Scan price
        printf("Enter price to convert, 0 to exit\n");
        scanf("%f",&prix);

    }

    // Print stats
    printf("There were %d calculations, sum HT %f , sum TTC %f", i, sumHC, sumTTC);
}

/*Ec2*/
void sinus_values() {
    /* Prints sine values for degrees a to b with step p
     * provided by stdin  */

    int p; // iteration step
    int a; // start
    int b; //end


    // Scan values
    printf("Give iteration step\n");
    scanf("%d", &p);

    // Make sure that p>0
    while (p == !0) {
        printf("Step must have non-zero value\n");
        scanf("%d", &p);
    }
    printf("Give starting values\n");
    scanf("%d", &a);
    printf("Give final value\n");
    scanf("%d", &b);

    // radians
    float val = PI / 180;

    // Make sure that start<end
    if (a > b) {
        int temp = b;
        b = a;
        a = temp;

    }

    int i; // iterator

    // print values
    for (i = a; i <= b; i = i + p) {
        printf("sin(%d) = %f\n", i, sin(i * val));
    }

    printf("\n");
}

/*Ex3*/

void mean_average()
{
    /* Returns mean averages of series of positive numbers
     * read from stdin */

    int num;     // Current num
    printf("Enter series of positive numbers, end with a negative number\n");
    scanf("%d",&num);

    // Declare and initialize sum and counter of numbers
    int sum=0;
    int n=1;

    // While input is positive
    while(num>=0)
    {
        // Augment sum value and n
        sum = sum +num;
        n++;

        // Scan next
        scanf("%d",&num);

    }

    // Print results
    printf("Mean Average: %f\n",(float)sum/n);
    printf("\n");
}

/* Ex4 */
void print_in_inverse_order()
{
    /* Reads n numbers from stdin and prints them in
     * reverse order*/

    int *array; // array pointer
    int n;      // number of elements
    printf("Enter number of elements\n");
    scanf("%d",&n);

    // Dynamically allocate array
    array = (int *)malloc(sizeof(int)*n);


    int i=0; // iterator

    // Scan Values
    while(i<n)
    {
        scanf("%d",&array[i]);
        i++;
    }

    // Reset to n-1 to traverse array from final element
    i=n-1;

    // Print values in reverse order
    while(i>=0)
    {
        printf("%d ",array[i]);
        i--;

    }
    printf("\n");

    // Free dynamically allocated memory
    free(array);
}

/*EX5*/
void print_couples()
{
    /* Prints all possible int coubples between 1 and
     * q,p provided by user*/

    int p,q; // num variables

    // Scan values
    printf("Give p\n");
    scanf("%d",&p);

    printf("Give q\n");
    scanf("%d",&q);


    int i; // iterator for p
    int j; // iterator for q

    // Print all possible values iteratively
    for(i =1; i <= p; i++)
    {
        for(j=1 ; j<= q; j++ )
        {
            printf("( %d, %d ) ", i ,j);
        }
        printf("\n");
    }
}

/*Ex6*/

void elem_apparitions()
{
    /* Reads a series of numbers between 0 and 20 from terminal
     * and returns distributions of elements*/

    int array[21];  // buffer for all possible values

    int i; // iterator

    // Initialize buffer values
    for(i=0;i<=20;i++)
    {
        array[i] = 0;
    }

    // Scan values
    int x;
    printf("Give numbers, to terminate program give negative value\n");
    scanf("%d",&x);

    // while input is positive
    while(x>=0)
    {
        if(x<= 20)
             array[x]++;
        scanf("%d",&x);
    }

    // Print distributions for each element

    for(i=0;i<=20;i++)
    {
        printf("Number: %d Occurances: %d\n", i , array[i]);
    }

    printf("\n");

}

/*EX7*/
void print_table()
{
    /* Reads a rectangular array and prints its values as well
     * as column and line sums*/

    // Declare table
    float T[4][5];

    int i; // iterator for lines
    int j; // iterator for columns

    // Initialize table
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            T[i][j] = 0;
        }
    }

    float x;

    //Scan values
    printf("Enter input values in the following form\n");
    printf(" i j value\n");
    printf(" set i to negative to exit loop\n");
    scanf("%d %d %f",&i,&j,&x);

    while(i>=0)
    {
        if(i<=3 && j<=2)
            T[i][j] = x;
        else
            printf("Please add valid iterators for 4x3 array\n");

        scanf("%d %d %f",&i,&j,&x);

    }


    //Calculate sums
    float sumline = 0, sumcol = 0 ;

    // For lines
    for(i=0;i<4 ;i++)
    {
        sumline = 0;
        for(j=0;j<3;j++)
        {
            sumline= T[i][j]+ sumline;
            T[3][4] = T[3][4] + sumline;
        }
        T[i][4]= sumline;

    }

    //For Columns

    for(j=0;j<3;j++)
    {
        sumcol = 0;
        for(i=0;i<4;i++)
        {
            sumcol= T[i][j]+ sumcol;

        }
        T[3][j]= sumcol;
    }

    //print result
    for(i=0;i<4;i++)
    {
        for(j=0;j<5;j++)
        {
            if(j==4) {
                printf("|");
            }
            printf("%0.2f ",T[i][j]);
        }
        printf("\n");

        if(i == 2)
            printf("----------------------------\n");
    }


}

int main(void)
{

    int choice = -1;
    printf("---------------TP3------------------\n");

    while(choice!=0){

        printf("Choose question number.\n");
        printf("1. Modify addtaxes code\n");
        printf("2. Print sin values*\n");
        printf("3. Print mean average\n");
        printf("4. Print in inverse order\n");
        printf("5. Print Couples*\n");
        printf("6. Print frequency distributions in series\n");
        printf("7. Print row and column sums in rectangular array\n");
        printf("0. To exit\n");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("Exiting program!! \n");
                break;
            case 1:/* Ex1 Modify addtaxes code*/
                addtaxesmod();
                break;
            case 2:/* Ex2 Print sin values*/
                sinus_values();
                break;
            case 3:/* Ex3 Print mean average*/
                mean_average();
                break;
            case 4: /*Ex4 Print in inverse order*/
                print_in_inverse_order();
                break;
            case 5: /*Ex5 Print Couples */
                print_couples();
                break;
            case 6:/*Ex6 Print frequency distributions in series*/
                elem_apparitions();
                break;
            case 7:/*Ex7 Print row and column sums*/
                print_table();
                break;
            default:
                printf("Wrong Choice. Enter again!\n");
                break;
        }
    }
}