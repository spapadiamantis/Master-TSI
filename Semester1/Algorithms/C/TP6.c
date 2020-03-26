#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MaxLines 1000
int my_strlen(char* s)
{
    int i=0;
    int cnt =0;
    while(s[i]!='\0')
    {
        cnt++;
        i++;
    }
    return cnt;
}

int my_strcmp(char* s1, char* s2)
{
    while(*s1 && (*s1 == *s2))
    {
        s1++;
        s2++;
    }
    return *(const unsigned char*)s1 - *(const unsigned char*)s2;
}

char* my_strcpy(char* destination, const char* source)
{
    // return if no memory is allocated to the destination
    if (destination == NULL)
        return NULL;

    // take a pointer pointing to the beginning of destination string
    char *ptr = destination;

    // copy the C-string pointed by source into the array
    // pointed by destination
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    // include the terminating null character
    *destination = '\0';

    // destination is returned by standard strcpy()
    return ptr;
}

char* my_strcat(char* destination, const char* source)
{
    // make ptr point to the end of destination string
    char* ptr = destination + strlen(destination);

    // Appends characters of source to the destination string
    while (*source != '\0')
        *ptr++ = *source++;

    // null terminate destination string
    *ptr = '\0';

    // destination is returned by standard strcat()
    return destination;
}

int readtext(char *s[])
{
    char buffer[200];
    int i =0;
    scanf("%s",buffer);
    s[i] = (char*) malloc(my_strlen(buffer)*sizeof(char));
    my_strcpy(s[i],buffer);
    i++;
    while(my_strcmp(buffer,"FIN")!=0)
    {
        scanf("%s",buffer);
        s[i] = (char*) malloc(my_strlen(buffer)*sizeof(char));
        my_strcpy(s[i],buffer);
        i++;
    }
    printf("Stopping reading input\n");
    return i;
}

int member_already(char* s1,char *s[], int len)
{
    int i;
    for(i=0;i<len;i++)
    {
        if(my_strcmp(s1,s[i])==0)
            return i;
    }
    return -1;
}

int readtext6(char *s[],int* nb)
{
    int k =0;
    int lenk = 5;


    int flag;
    char buffer[200];
    int i =0;
    scanf("%s",buffer);
    s[i] = (char*) malloc(my_strlen(buffer)*sizeof(char));
    my_strcpy(s[i],buffer);
    nb[i]++;
    i++;
    while(my_strcmp(buffer,"FIN")!=0)
    {
        scanf("%s",buffer);
        flag = member_already(buffer,s,i);
        if(flag == -1) {
            s[i] = (char *) malloc(my_strlen(buffer) * sizeof(char));
            if(k<lenk){
                k++;
                nb[i]++;
            }
            else
            {
                lenk = 2*lenk;
                nb = (int*)realloc(nb,lenk*sizeof(int));
            }
            my_strcpy(s[i], buffer);
            i++;

        }
        else{
            nb[flag]++;
        }

    }
    printf("Stopping reading input\n");
    return i;
}

int main(void)
{
    /*
    char *test = (char*) malloc(12*sizeof(char));
    strcpy(test, "testingonl");
    printf("Length is  %d\n",my_strlen(test));

    char *test2 = (char*) malloc(12*sizeof(char));
    my_strcpy(test2, "testingonly");
    printf("Comp is %d\n",my_strcmp(test,test2));

    char* t[MaxLines];
    int lines = 0;
    int* nb;
    nb = (int*)malloc(5*sizeof(int));
    lines = readtext6(t,nb);
    int i;
    for(i=0;i<lines;i++)
    {
        printf("%s ,%d\n",t[i],nb[i]);
    }
     */
    char dec[25];

    char buffer[50];
    int choice = -1;

    char *t[MaxLines];
    int lines = 0;
    int *nb;
    nb = (int *) malloc(5 * sizeof(int));
    char *test2 = (char *) malloc(12 * sizeof(char));
    my_strcpy(test2, "testingonly");
    printf("---------------TP6------------------\n");

    while(choice!=0) {


        printf("Choose question number.\n");
        printf("1. Exercise 1\n");
        printf("2. Exercise 2\n");
        printf("3. Exercise 3 \n");
        printf("4. Exercise 4\n");
        printf("5. Exercise 5 \n");
        printf("6. Exercise 6 \n");
        printf("7. Exercise 7 \n");
        printf("0. To exit\n");
        scanf("%d", &choice);
        printf("\n");
        switch (choice) {
            case 0 :
                printf("Exiting program!! \n");
                break;
            case 1:/*Ex1 strlen implementation*/
                printf("Give string to count length\n");
                scanf("%s", buffer);
                printf("Length is  %d\n", my_strlen(buffer));
                break;
            case 2:/*Ex2 strcmp implementation*/
                printf("Enter first string\n");
                scanf("%s", buffer);
                printf("Enter second string\n");
                scanf("%s", dec);
                printf("%d\n", my_strcmp(buffer, dec));
                break;
            case 3:/*Ex3 strcpy implementation*/
                printf("Comp is %s\n", test2);
                break;
            case 4: /*Ex4 strcat implementation**/
                printf("Enter first string");
                scanf("%s", buffer);
                printf("Enter second string");
                scanf("%s", dec);
                printf("%s\n", my_strcat(buffer, dec));
                break;
            case 5:
            case 6:
            case 7:

                lines = readtext6(t, nb);
                int i;
                for (i = 0; i < lines; i++) {
                    printf("%s ,%d\n", t[i], nb[i]);
                }
                break;
            default:
                printf("Wrong Choice. Enter again!\n");
                break;
        }
    }
}