#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100


void store_to_table()
{
    int e;
    int t[MAX];
    int n=0;
    int i=0;

    scanf("%d",&e);


    while(e>0)
    {
        n++;
        t[i++] = e;
        scanf("%d",&e);
    }

    for(i = 0 ; i<n;i++){
        printf("%d ", t[i]);
    }
    printf("\n\n");
}

void store_to_table_unique()
{
    int e;
    int t[MAX];
    int n=0;
    int i;

    scanf("%d",&e);

    while(e>0)
    {
        i = 0;

        while(e!= t[i] && i<n)
        {
            i++;
        }
        if(i==n)
            t[n++] = e;

        scanf("%d",&e);
    }

    for(i = 0 ; i<n; i++)
    {

        printf("%d ", t[i]);


    }
    printf("\n\n");
}

void longest_first_word()
{

    /* Returns the first lingest word of input as well as
     * its length*/
    int i;                    // iterator to write to buffers
    int nb;                   // length of first longest word
    char c;                   // current character
    char longest_word[50];    // to store first long word
    char current_word[50];    // to store current word

    // Scan twice to empty input buffer
    printf("Enter string terminating by '.'\n");
    scanf("%c", &c);
    scanf("%c", &c);

    // Initialize length first longest word
    nb = 0;

    // Traverse whitespace
    while (c == ' ')
        scanf("%c", &c);

    // Until end of string
    while(c != '.')
    {

        // Initialize operator
        i = 0;

        // While word
        while (c != '.' && c != ' ' && c != ',')
        {
            // Add to current word buffer
            current_word[i] = c;
            i++;
            // Get next character
            scanf("%c", &c);
        }

        // If current word length > length of longest word
        if (i > nb)
        {
            nb = i; // set first word length to current word length
            i = 0; // reset iterator

            // Write current word to longest word buffer
            while (i < nb)
            {
                longest_word[i] = current_word[i];
                i++;
            }
        }
        // Transverse whitespace
        while (c == ' ' || c == ',')
            scanf("%c", &c);
    }
    if (nb)
        printf("The first longest word is  '%s'; Its length is : %d\n", longest_word, nb);
    else
        printf("Empty input string'n");
}


void instances_of_first()
{

    /* Returns the number of instances of first word in input*/

    int i;       // iterator
    int lf;     // length of first word
    int nb;      // number of instances
    char c;      // current character
    char  buffer[50];  // word buffer

    // Scan twice to empty input buffer
    printf("Enter string terminating by '.'\n");
    scanf("%c", &c);
    scanf("%c", &c);

    // Transverse whitespace
    while (c == ' ')
        scanf("%c", &c);

    nb = 0;
    lf = 0;

    // Store first word and length
    while(c != '.' && c != ' ')
    {
        buffer[lf] = c;
        lf++;
        scanf("%c", &c);
    }
    if (lf != 0)
        nb++;

    while(c != '.')
    {

        i = 0;
        while (c != '.' && c != ' ' && i < lf && buffer[i] == c){
            i++;
            scanf("%c", &c);
        }
        if (i == lf && (c == '.' || c== ' '))
            nb++;

        while (c != '.' && c != ' ')
            scanf("%c", &c);

        while (c == ' ')
            scanf("%c", &c);
    }
    if (nb)
        printf("There are %d instances of the first word", nb);
    else
        printf("Input is empty");
}

void find_palindromes()
{
    int nb;
    int i;
    int j;
    char c;
    char t[50];

    printf("Ecrivez une suite de caractères terminée par '.'\n");
    scanf("%c", &c);
    scanf("%c", &c);

    while (c == ' ')
        scanf("%c", &c);

    nb = 0;
    while(c != '.'){
        j = 0;
        while (c != '.' && c != ' '){
            t[j] = c;
            j++;
            scanf("%c", &c);
        }

        i = 0;
        while (i < j/2 && t[i] == t[j-1-i])
            i++;

        if (i == j/2)
            nb++;

        while (c == ' ')
            scanf("%c", &c);
    }
    if (nb != 0)
        printf("Resultat :There are %d palindromes in the string", nb);
}





int main(void)
{
    int choice = -1;
    printf("---------------TP4------------------\n");

    while(choice!=0){

        printf("Choose question number.\n");
        printf("1. Store to table\n");
        printf("2. Store unique values to table\n");
        printf("3. Get first longest word\n");
        printf("4. Find number of instances of first word\n");
        printf("5. Get number of palindromes\n");
        printf("0. To exit\n");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("Exiting program!! \n");
                break;
            case 1:/*Exo 1:  Store to table */
                store_to_table();
                break;
            case 2:/*Exo 2: Store unique values to table*/
                store_to_table_unique();
                break;
            case 3:/*Exo 3: Get first longest word*/
                longest_first_word();
                break;
            case 4:/*Exo 4: Find number of instances of first word*/
                instances_of_first();
                break;
            case 5:/*Exo 5: Get number of palindromes in input*/
                find_palindromes();
                break;
            default:
                printf("Wrong Choice. Enter again!\n");
                break;
        }
    }
}