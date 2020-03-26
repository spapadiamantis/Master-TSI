#include <stdio.h>
#include <string.h>
#define Max 15
// plus longe nombre  "MMMDCCCLXXXVIII"(3888) de longeur 15

typedef struct
    {
    char t[Max];
    int lg;
    } NR;


int get_num(char c)
{
    int num =0;
    switch(c)
    {
        case 'M':
            num = 1000;
            break;
        case 'D':
            num = 500;
            break;
        case 'C':
            num = 100;
            break;
        case 'L':
            num = 50;
            break;
        case 'X':
            num = 10;
            break;
        case 'V':
            num = 5;
            break;
        case 'I':
            num = 1;
            break;
    }

    return num;

}

int Romain_Entier(NR x)
{
    int i;
    int num = 0;

    int to_add = 0;

    for(i=0;i<x.lg;i++)
    {
        int flag = 0;
        to_add = get_num(x.t[i]);
        if( to_add < get_num(x.t[i+1]))
            flag = 1;

        if(flag)
            num = num-to_add;
        else
            num = num+to_add;

    }

    return num;
}

void Entier_Romain(int num, NR *x)
{
    int i = 0;
    while(num != 0)
    {

        if (num >= 1000)       // 1000 - m
        {
            (*x).t[i] = 'M';
            num = num - 1000;
        }

        else if (num >= 900)   // 900 -  cm
        {
            (*x).t[i] = 'C';
            (*x).t[++i] = 'M';
            num = num - 900;
        }

        else if (num >= 500)   // 500 - d
        {
            (*x).t[i] = 'D';
            num = num - 500;
        }

        else if (num >= 400)   // 400 -  cd
        {
            (*x).t[i] = 'C';
            (*x).t[++i] = 'D';
            num = num - 400;
        }

        else if (num >= 100)   // 100 - c
        {
            (*x).t[i] = 'C';
            num = num - 100;
        }

        else if (num >= 90)    // 90 - xc
        {
            (*x).t[i] = 'X';
            (*x).t[++i] = 'C';
            num = num - 90;
        }

        else if (num >= 50)    // 50 - l
        {
            (*x).t[i] = 'L';
            num = num -50;
        }

        else if (num >= 40)    // 40 - xl
        {
            (*x).t[i] = 'X';
            (*x).t[++i] = 'L';
            num = num -40;
        }

        else if (num >= 10)    // 10 - x
        {
            (*x).t[i] = 'X';
            num = num - 10;
        }

        else if (num >= 9)     // 9 - ix
        {
            (*x).t[i] = 'I';
            (*x).t[++i] = 'X';
            num = num - 9;
        }

        else if (num >= 5)     // 5 - v
        {
            (*x).t[i] = 'V';
            num = num - 5;
        }

        else if (num >= 4)     // 4 - iv
        {
            (*x).t[i] = 'I';
            (*x).t[++i] = 'V';
            num = num - 4;
        }

        else if (num >= 1)     // 1 - i
        {
            (*x).t[i] = 'I';
            num = num - 1;
        }
        i++;
        (*x).lg++;
    }

    return;

}

int main(void)
{
    NR num;
    strcpy(num.t ,"MCDXCIV");
    num.lg = 7;
    int i = Romain_Entier(num);

    printf("%d\n",i);

    NR num2;

    Entier_Romain(1494,&num2);
    printf("%s\n",num2.t);

}