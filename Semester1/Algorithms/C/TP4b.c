/* TP4 bis Sotirios PAPADIAMANTIS */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/*Exo1*/
int printArray(int pary[], int n)
{
    /*  prints array*/
    int r; //row iterator

    for (r = 0; r < n; r++)
    {
            printf("%d ", pary[r]);

    }
    printf("\n");
}

void get_equal_elems(int array1[],int array2[],int N){

    /* Returns number of equal elements to tables of
     equal size*/


    int i;			                        // iterator
    int nb;			                        // number of equal elements

    nb = 0;
    i = 0;

    // number of indices with same values
    while (i < N){
        if (array1[i] == array2[i])
            nb++;
        i++;
    }

    printf("There are %d equal 1 - 1 elements\n", nb);

}

void min_of_table(int array[], int N)
{
    /* Return minimum of a table passed as argument
     * along table size*/

    int i;			// iterator
    int min;		// array minimum


    // Set smallest element as first at beginning
    min = array[0];

    // Iterate through the table
    for(i = 1; i<N ; i++)
    {

        // If current element < minimum
        if (array[i] < min)
            // set as minimum
            min = array[i];
    }

    printf("Smallest element of table is : %d\n", min);
}

void min_of_table_index(int array[], int N)
{
    /* Return minimum of a table passed as argument
     * along table size*/

    int i;			// iterator
    int min;		// array minimum
    int ind;

    // Set smallest element as first at beginning
    min = array[0];

    // Iterate through the table
    for(i = 1; i<N ; i++)
    {

        // If current element < minimum
        if (array[i] < min)
        {
            // set as minimum
            min = array[i];
            ind = i;
        }
    }

    printf("Smallest element of table is in place : %d\n", ind);
}

void sequential_search_1(int T[N][M], int N, int X)
{
    /* Finds first index of value X. We know that
     * this element exists*/

    int i = 0;			// Iterator

    // Iterate through array until first instance
    while (T[i] != X)
        i++;

    printf("Found %d at index %d\n", X, i);
}

void sequential_search_2(int T[], int N , int X)
{

    int i = 0;
    while (T[i] != X && i < N)
        i++;

    if (i == N)
        printf("Element was not found in table\n");
    else
        printf(" Found %d at index %d\n", X, i);
}


void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;


}

void tidy_table(int T[], int N)
{

    int new_size;		// size of new table
    int i,k;			// iterators
    int temp;			    // temp variable


    // Initialize variables
    new_size = N;
    i = 0;

    // Until we rich final element
    while (i < new_size)
    {

        // if zero element
        if (T[i] == 0)
        {

            // Move next elements to the left
            for(k = i; k < new_size-1; k++){
               swap(&T[k], &T[k+1]);
            }
            // Reduce size
            new_size--;
        }
        // If not zero continue
        else
            i++;
    }


}

void merge_sorted_arrays(int A[],int B[], int C[], int size_a, int  size_b)
{

    int i = 0;
    int k = 0;
    int j = 0;

    while (k != size_a || j != size_b){
        if (k == size_a){
            C[i] = B[j];
            j++;
        }
        else if (j == size_b){
            C[i] = A[k];
            k++;
        }
        else if (A[k] < B[j]){
            C[i] = A[k];
            k++;
        }
        else{
            C[i] = B[j];
            j++;
        }
        i++;
    }

}

int binarySearch(int T[], int l, int r, int X)
{
    /* Performs a binary search on sorted table T searching
     * for element X */
    int counter = 0;
    while (l <= r)
    {
        // Find middle element
        int m = l + (r-l)/2;
        counter++;
        // X in middle return index
        if (T[m] == X)
        {
            printf("Element was found at %d position with %d calculations\n", m,counter);
            return m;
        }

        // If X greater, ignore left half
        if (T[m] < X)
        {
            l = m + 1;
        } // If X is smaller, ignore right half
        else
            r = m - 1;
    }

    //Element not found
    printf("Element was not found\n");
    return -1;
}

float horners(float *coeffs, int n, float X)
{
    /*  Employs horners methods on polynomes*/
    float result = 0.0;

    for(int i=n-1; i >= 0; i--)
    {
        result = result * X + coeffs[i];
    }
    return result;
}

int min_row(int N, int M, int A[N][M], int p, int q){
    int i;

    i = 0;
    while (i < M){
        if (A[p][q] > A[p][i])
            return 0;
        i++;
    }
    return 1;
}

int max_col(int N, int M, int A[N][M], int p, int q){
    int i;

    i = 0;
    while (i < N){
        if (A[p][q] < A[i][q])
            return 0;
        i++;
    }
    return 1;
}

void printArray2(int T[N1][N2])
{

    int p = 0;
    int q;
    while (p < N1){
        printf("[");
        q = 0;
        while (q < N2+1){
            printf("%d, ", T[p][q]);
            q++;
        }
        printf("%d]", T[p][q]);
        if (p != N1-1)
            printf(",\n");
        p++;
    }
    printf("]\n");

}

void min_max(int T[N1][N2], int N, int M)
{
    int min[N];
    int i;
    int j;
    int p;
    int q;

    p = 0;
    while (p < N){
        i = 0;
        q = 0;
        while (q < M+1){
            if (min_row(N, M+1, T, p, q) == 1){
                min[i] = q;
                i++;
            }
            q++;
        }
        j = 0;
        while (j < i){
            if (max_col(N, M+1, T, j, q) == 1)
                printf("( %d , %d )\n", j, q);
            j++;
        }
        p++;
    }
}


int main(void)
{
    int array1[] = {37, 13, -245, -12, 1, 18, -567, -183, 19, 55};
    int array2[] = {66, 13, 49, -45, 11, 12, 560, -11, 92 , 55};
    int array_sorted1[] = {-111, -45, -12, -2, 1, 13, 144, 567};
    int array_sorted2[] = {-567, -111, -45, 0, 0, 1, 12, 13, 144};
    float coeffs[] = { -19, 7, -4, 6 };
    float x = 10;
    int array_merged[17];
    for(int i = 0; i< 17;i++)
        array_merged[i]=0;
    int size1 = 8;
    int size2 = 9;
    int n;
    int choice = -1;
    int input;
    int disp[N1][N2] = {
            {10, 11, 12, 13},
            {14, 15, 16, 17}
    };



    printf("---------------TP3------------------\n");



    while(choice!=0){

        printf("Choose question number.\n");
        printf("1. Print number of equal elements in tables\n");
        printf("21. Print array minimum\n");
        printf("22. Print index of array minimum \n");
        printf("31. Sequential search of table 1\n");
        printf("32. Sequential search of table 2\n");
        printf("4. Tidy table\n");
        printf("5. Merge sorted tables\n");
        printf("6. Binary search \n");
        printf("7. Horner's scheme\n");
        printf("8. MIN-MAX\n");
        printf("0. To exit\n");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                printf("Exiting program!! \n");
                break;
            case 1:/*Exo 1 number of equal elements to tables of equal size */
                printf("First array to compare:\n");
                printArray(array1,8);
                printf("Second array to compare:\n");
                printArray(array2,8);
                n = sizeof(array1)/ sizeof(int);
                get_equal_elems(array1,array2,n);
                break;
            case 21:/*Exo 2: Find minimum of table*/
                printf("Array to find min\n");
                n = sizeof(array1)/ sizeof(int);
                printArray(array1,n);
                min_of_table(array1,n);
                break;
            case 22:/*Exo 2: Find index minimum of table*/
                printf("Array to find min\n");
                n = sizeof(array1)/ sizeof(int);
                printArray(array1,n);
                min_of_table_index(array1,n);
                break;
            case 31:/*Exo 3: Sequential search of table knowing element exists */
                printf("Array to search\n");
                n = sizeof(array1)/ sizeof(int);
                printArray(array1,n);
                printf("Enter element to search\n");
                scanf("%d", &input);
                sequential_search_1(array1,n,input);
                break;
            case 32:/*Exo 3: Sequential search of table, not knowing element exists */
                printf("Array to search\n");
                n = sizeof(array1)/ sizeof(int);
                printArray(array1,n);
                printf("Enter element to search\n");
                scanf("%d", &input);
                sequential_search_2(array1,n,input);
                break;
            case 4:
                printf("Array before tiding up\n");
                printArray(array_sorted1,size1);
                tidy_table(array_sorted1,size1);
                printf("Array after\n");
                printArray(array_sorted1,size2);
                break;
            case 5:
                printf("First sorted array :\n");
                printArray(array_sorted1,size1);
                printf("Second sorted array :\n");
                printArray(array_sorted2,size2);
                merge_sorted_arrays(array_sorted1,array_sorted2, array_merged, size1, size2);
                printf("This is the merged table:\n");
                printArray(array_merged,17);
                break;
            case 6:/* Binary search*/
                printf("Binary search on this array:\n");
                printArray(array_sorted1,size1);
                printf("Enter an element to search.\n");
                scanf("%d",&input);
                binarySearch(array_sorted1,0,size1-1,input);
                break;
            case 7:/* Horners*/
                printf("For these coefficients: { -19, 7, -4, 6 }\n");
                printf("And X = %f\n",x);
                printf("Polynome is equal to: %f\n",horners(coeffs,4,x));
                break;
            case 8:
                printf("For this array:\n");
                printArray2(disp,2,4);
                printf("We calculate min-max\n");
                min_max(disp,2,4);
            default:
                printf("Wrong Choice. Enter again!\n");
                break;
        }
    }
}