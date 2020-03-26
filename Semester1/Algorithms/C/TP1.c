/*TP1  Sotirios PAPADIAMANTIS*/
#include <stdio.h>
#include <math.h>


/*Exo 1*/

float addtaxes(float price)
{
    /*Adds taxes to input tax - 20%*/
    float full_price = price + price*0.2;
    return full_price;
}

/*Exo 2*/

void monnaie(int somme)
{
    /*Breaks down somme to series of currency*/

    /*For every unit of currency in descending order
    divide somme and set somme as rest*/
    printf("%d x 200 + ",somme/200);
    somme = somme%200;
    printf("%d x 100 + ", somme/100);
    somme = somme%100;
    printf("%d x 50 + ", somme/50);
    somme = somme%50;
    printf("%d x 20 + ", somme/20);
    somme = somme%20;
    printf("%d x 10 + ", somme/10);
    somme = somme%10;
    printf("%d x 5 + ", somme/5);
    somme = somme%5;
    printf("%d x 2 + ", somme/2);
    somme = somme%2;
    printf("%d x 1", somme/1);
    somme = somme%1;

    printf("\n");

    return;

}

/*Exo3*/

void addtaxesarrondi(float price)
{
    /*Adds tax to price and prints rounded values*/

    // Add tax
    float full_price = price + price*0.2;

    // Print price rounded down
    printf("Prix arrondi a l'euro inferieur %d\n", (int)full_price);

    // Print price rounded up
    printf("Prix arrondi a l'euro le plus proche %d\n", (int)(full_price+ 0.5));

    // Print price rounded to 0,25
    int full_price_quart = (int)(full_price*4);
    printf("Prix arrondi au quart d'eurole plus proche %d\n", full_price_quart/4);

}

/*Exo 4*/

void comparenums(int a, int b)
{
    /* Prints bigger among 2 input numbers*/

    if(a > b)
        printf("%d is bigger than %d\n", a,b);
    else if( a<b)
        printf("%d is bigger than %d\n", b,a);
    else
        printf("%d  and %d sont egaux\n", b,a);


}

/*Exo 5*/

void second_degree()
{
    /* Returns roots of second degree equation */

    // Scan variables from standard input
    printf("Give second degree equation variables\n");
    float a,b,c;
    printf("First variable: ");
    scanf("%f",&a);
    printf("Second variable: ");
    scanf("%f",&b);
    printf("Third variable: ");
    scanf("%f",&c);

    // Calculate discriminant
    float discriminant = (b*b)-4*a*c;
    float root1 = 0;
    float root2 = 0;

    // If D>0 there are two positive roots
    if(discriminant> 0){

        // Calculate and print each root
        root1 = (-b+sqrt(discriminant))/(2*a);
        root2 = (-b-sqrt(discriminant))/(2*a);

        printf("First root: %f \n",root1);
        printf("Second root: %f \n",root2);
    }// If D = 0, threre is 1 root
    else if (discriminant == 0){

        // Calculate and print root
        root1 = -b/(2*a);

        printf("Root at %f\n",root1);
    }// If D<o there are two complex roots
    else{

        // Calculate real part
        float partie_reel = -b/(2*a);

        // Calculate imaginary part
        float partie_imaginaire= sqrt(-discriminant)/(2*a);

        // Print roots
        printf("First root %f + i * %f",partie_reel, partie_imaginaire);
        printf("Second root %f - i * %f",partie_reel, partie_imaginaire);

    }


}

/*Exo 6*/
void getnextday()
{

    // Scan values
    printf("Give day\n");
    int j,m,a, jmax;
    scanf("%d",&j);
    printf("Give week\n");
    scanf("%d",&m);
    printf("Give year\n");
    scanf("%d",&a);


    // If month has 30 days
    if(m==4 || m==6|| m==9 || m==11){

        // Set max dayss
        jmax=30;
    }
    else{

        // If February
        if (m == 2) {

            // If odd year
            if ((a % 4 == 0 && a % 100 == 0) || (a % 400 == 0)) {
                jmax = 29;
            } else
                jmax = 28;
        }
        else
            jmax = 31;
    }

    // If not last day of the month
    if(j<jmax)
        // Set next day
        j = j+1;
    else{ // If last day

        // Reset days
        j = 1;

        // If not December
        if (m<12)
            // Set next month
            m= m+1;
        else {
            // If December

            // Reset months
            m = 1;

            // Set next year
            a = a+1;
        }
    }

    // Print result
    printf("Next day is%d/%d/%d",j,m,a);

}

/*Exo 7*/
void getday()
{
    /*Scans date and prints day of the week*/

    int j,m,a;
    // Scan date
    printf("Give day\n");
    scanf("%d",&j);
    printf("Give month\n");
    scanf("%d",&m);
    printf("Give year\n");
    scanf("%d",&a);

    int m1, a1, ns, as;

    if(m>=3) {
        m1 = m - 2;
        a1 = a;
    }
    else{
        m1 = m+10;
        a1 = a -1;
    }
    ns = a/100;

    as = a%100;

    int weekday = j + as+ as/4 - 2*ns +ns/4 + (26*m1-2)/10;

    weekday = weekday%7;

    switch(weekday) {
        case 0:
            printf(" Sunday.\n");
            break;
        case 1:
            printf(" Monday.\n");
            break;
        case 2:
            printf(" Tuesday.\n");
            break;
        case 3:
            printf(" Wednesday.\n");
            break;
        case 4:
            printf(" Thursday.\n");
            break;
        case 5:
            printf(" Friday.\n");
            break;
        case 6:
            printf(" Saturday.\n");
    }

    return;
}

/* Main Function*/

int main(void){
    int choice,input1;
    int input2;
    float inputf;
    printf("Choose question number.\n");
    scanf("%d", &choice);

    switch (choice)
    {
                    case 1:/*Exo 1: Add taxes*/
                        printf("Give price to add taxes:\n");
                        scanf("%f",&inputf);
                        printf("\n");
                        printf("After taxes price : %f\n", addtaxes(inputf));
                        break;
                    case 2: /* Exo 2: Make change */
                        printf("Give int amount to make change:\n");
                        scanf("%d",&input1);
                        printf("\n");
                        monnaie(input1);
                        break;
                    case 3: /*Exo 3: Rounded up taxes*/
                        printf("Give price to add taxes:\n");
                        scanf("%f",&inputf);
                        printf("\n");
                        addtaxesarrondi(inputf);
                        break;
                    case 4: /*Exo 4: Compare Integers*/
                        printf("First Number to compare:\n");
                        scanf("%d",&input1);
                        printf("Second Number to compare:\n");
                        scanf("%d",&input2);
                        printf("\n");
                        comparenums(input1,input2);
                        break;
                    case  5: /*Exo 5: Second Degree Equations */
                        second_degree();
                        break;
                    case  6: /*Exo 6: Get next day */
                        getnextday();
                        break;
                    case 7 : /*Exo 7: Get day of the week*/
                        getday();
                        break;
                    default:
                        printf("Wrong Choice. Enter again!\n");
                        break;
                }

}