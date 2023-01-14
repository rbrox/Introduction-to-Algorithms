/*
Code by Rishav Bhagat
*/

// Linkers
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Prototypes
void merge(int arr[], int p, int q, int r);
void merger(int arr[], int first, int last);
void array_gen();
void array_disp();


// Global 

#define SIZE 20
#define RANGE 1000
int arr[SIZE];

// Main Function
void main()
{
    array_gen();
    array_disp();
    merger(arr, 0, SIZE - 1);
    array_disp();
}

// Function Definitions

void array_disp()
{

    printf("\nGenarated array\n\n");
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 10 == 0)
        {
            printf("\n");
        }
        printf("%d\t", arr[i]);
    }
}


void array_gen()
{
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % RANGE;
    }
    
}


void merger(int arr[], int first, int last)
{
    if(first < last)
    {
        int mid = (last + first) / 2;
        merger(arr, first, mid);
        merger(arr, mid + 1, last);
        merge(arr, first, mid, last);
    }
    
}

void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    // Creating arrays of size as required
    int left[n1], right[n2];

    // Copying the first array
    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[p + i];
    }
    
    // Copying the second array
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[q + 1 + i];
    }
 

    for ( int k = p, i = 0, j = 0; k < r + 1; k++)
    {
        if ((left[i] <= right[j] && i != n1) || j == n2)
        {
            arr[k] = left[i];
            ++ i; 
        }
        else
        {
            arr[k] = right[j];
            ++ j;
        }
    }
    
}


/*
In the module herin we have discussed the following topics
    2.3 Designing Algorithms 1.Divide & Conquer 2.Analyzing divide & conquer algo 
    
    Exercises
        2.3-1:
        
        A = {3; 41; 52; 26; 38; 57; 9; 49}
        a1 = {3; 41; 52; 26}        a2 = {38; 57; 9; 49}
        a1-1 = {3; 41}  a1-2 = {52; 26}     a2-1 = {38; 57} a2-2 = {9; 49}
        
        // Merging Step
        a1-1 = {3; 41}  a1-2 = {26; 52}     a2-1 = {38; 57} a2-2 = {9; 49}
        a1 = {3; 26; 41; 52}        a2 = { 9; 38; 57; 49}
        return sorted
*/