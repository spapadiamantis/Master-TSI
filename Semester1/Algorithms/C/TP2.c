/* TP2 Sotirios PAPADIAMANTIS */
#include <stdio.h>

void ex1()
{
    /* Counts number of l in string provided by user*/
    char c;
    int nb = 0;
    scanf("%c",&c);
    while(c!='.')
    {
        if(c == 'l')
            nb++;
        scanf("%c",&c);
    }
    printf("There are %d 'l'  in the input string",nb);
}

void ex2()
{
    /* Counts number of le in string provided by user*/
    char c;
    int nb = 0;
    scanf("%c",&c);
    while(c != '.')
    {
        if(c == 'l') {
            scanf("%c", &c);
            if (c == 'e'){
                nb++;
                scanf("%c", &c);
            }
        }
        else
            scanf("%c",&c);
    }
    printf("There are %d 'le'  in the input string",nb);

}

void ex3()
{
    /* Counts number of les in string provided by user*/
    char c;
    int nb  = 0;

    scanf("%c",&c);
    while(c != '.')
    {
        if(c =='l') {
            scanf("%c", &c);

            if (c == 'e') {

                scanf("%c", &c);
                if(c =='s'){

                    nb = nb + 1;

                }
            }

        }
        else
            scanf("%c",&c);
    }
    printf("There are  %d 'les' in input", nb);
}

void ex4()
{
     char p,c;
     int nb = 0;
     p=' ';

     printf("Enter input string:\n");
     scanf("%c",&c);
     while(c != '.')
     {

         if(p=='l' && c == 'e')
             nb++;
         p = c;
         scanf("%c",&c);

     }

    printf("There are  %d 'le' in input", nb);
}


void ex5()
{
    int nb;
    char pp , p , c;
    nb = 0;

    printf("Enter input string:\n");
    scanf("%c",&c);
    scanf("%c",&c);

    p = ' ';
    pp = ' ';
    while(c != '.')
    {

        if(pp == 'l' && p == 'e' && c == 's') {

            nb = nb++;
        }

        p = c;
        pp = p;
        scanf("%c",&c);
    }
    printf("il y a %d 'les' dans la suite donnee", nb);
}

void ex6()
{
    char c;
    int nb  = 0;

    printf("Enter input string:\n");

    scanf("%c",&c);
    // Transverse whitespace at the beginning
    while(c == ' ')
        scanf("%c",&c);

    while(c != '.')
    {
        // Augment counter
        nb++;

        // Read word
        while( c!= ' ' && c!='.')
            scanf("%c",&c);

        // Read whitespace
        while(c == ' ')
            scanf("%c",&c);

    }

    printf("There are %d word in input",nb);
}

void ex7() {

    char p, c;
    int nb;
    int a;
    nb = 0;
    p = ' ';

    printf("Enter input string:\n");
    scanf("%c", &c);
    scanf("%c", &c);

    while (c != '.') {
        p = c;
        scanf("%c", &c);
        if ((p != ' ') && (c == ' ' || c == '.'))
            nb++;
    }
    printf("There are %d words in input", nb);
}

int main(void)
{
    int choice = -1;
    printf("---------------TP2--------------\n");
    while(choice!=0){
        printf("\n");
        printf("Choose question number.\n");
        printf("0. to exit\n");
        printf("1. Exercise 1\n");
        printf("2. Exercise 2\n");
        printf("3. Exercise 3\n");
        printf("4. Exercise 4\n");
        printf("5. Exercise 5\n");
        printf("6. Exercise 6\n");
        printf("7. Exercise 7\n");
        scanf("%d", &choice);

        switch(choice){
            case 0:
                break;
            case 1:
                ex1();
                break;
            case 2:
                ex2();
                break;
            case 3:
                ex3();
                break;
            case 4:
                ex4();
                break;
            case 5:
                ex5();
                break;
            case 6:
                ex6();
                break;
            case 7:
                ex7();
                break;
            default:
                printf("Wrong Choice. Enter again!\n");
                break;
        }
    }


}