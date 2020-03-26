/* TP3 Sotirios PAPADIAMANTIS */

#include <stdio.h>

/*Ex1*/
void first_char_in_string(void)
{
    /* Reads a string from stdin and returns the number of
    instances of the first character */

    int nb;     //num of appearances
    char cour;  //current char examined
    char prem;  // first char of string

    nb = 0;    //Initialise nb

    scanf("%c",&prem); // Scan to pass enter from input buffer

    // Read input
    printf("Enter a string\n");
    scanf("%c",&prem);

    // Set current as first
    cour = prem;

    // Until end of string
    while(cour != '.')
    {

        // If first is equal to current
        if(cour == prem){

            // Augment counter
            nb = nb+1;
        }

        // Scan next character
        scanf("%c",&cour);

    }

    // Print results
    printf("There are %d '%c' in string input\n", nb, prem);
}

/*Ex2*/
void num_words_of_length(void)
{
    /* Returns the number of words with length of lg,
      where lg is given as input from stdin*/

    int nb;  // counter
    int lgc; // current word length
    int lg;  // word length
    char c;  // char for input

    // Initialize values
    nb = 0;
    lgc = 0;

    scanf("%c",&c); // Scan to pass enter from input buffer

    // Scan length
    printf("Length of word to search for:\n");
    scanf("%d",&lg);

    printf("Enter input string\n");
    // Transverse whitespace at the  beginning
    while(c == ' ')
        scanf("%c",&c);

    // Augment counter
    nb = nb+1;

    // Until end of string
    while(c!='.')
    {

        // Read word
        while(c != ' ' && c != '.')
        {
            lgc = lgc+1;
            scanf("%c",&c);
        }

        // If word is of said length
        if (lgc == lg)
            // Augment counter
            nb = nb +1;

        // Transverse whitespace
        while(c == ' '){
            scanf("%c",&c);
        }

        // Reset current length to 0
        lgc = 0;
    }

    // Print results
    printf("There are %d words of length %d in input string\n", nb, lg);
}

/*Ex3*/

void num_words_of_length_first()
{
    /* Returns the number of words with the
      same length as the first word*/

    int nb =0;  // counter
    int lgl=0;  // length of first word
    int lgc=0;  // length of current word
    char c;     // char to read input

    // Transverse whitespace at the  beginning
    while(c == ' ')
        scanf("%c",&c);

    // Augment counters
    lgl = lgl + 1;
    nb = nb+1;

    // Read first word
    while(c != ' ' && c != '.')
    {
        lgl = lgl+1;
        scanf("%c",&c);
    }

    // Until end of string
    while(c!='.')
    {

        // Read word
        while(c != ' ' && c != '.')
        {
            lgc = lgc+1;
            scanf("%c",&c);
        }

        // If length is same as first word
        if (lgc == lgl)
            nb = nb +1;

        // Transverse whitespace
        while(c == ' '){
            scanf("%c",&c);
        }

        // Reset current length to 0
        lgc = 0;
    }

    // Print result
    printf("There are %d words of same length as the first word in the input string\n", nb);
}


int main(void)
{
    int choice = -1;
    printf("---------------TP3------------------\n");

    while(choice!=0){

        printf("Choose question number.\n");
        printf("1. Print number of instances of first character in a string\n");
        printf("2. Print number of words of certain length in a string\n");
        printf("3. Print number of words of same length as the first word \n");
        printf("0. To exit\n");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("Exiting program!! \n");
                break;
            case 1:/*Exo 1 Print number of instances of first character in a string */
                first_char_in_string();
                break;
            case 2:/*Exo 2: Print number of words of certain length*/
                num_words_of_length();
                break;
            case 3:/*Exo 3: Print number of words of same length as the first word*/
                num_words_of_length_first();
                break;
            default:
                printf("Wrong Choice. Enter again!\n");
                break;
        }
    }
}