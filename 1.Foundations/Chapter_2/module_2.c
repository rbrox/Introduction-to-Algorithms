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
void selection_sort(int arr[], int first, int last);

// Global 

#define SIZE 1000
#define RANGE 1000
int arr[SIZE];

// Main Function
void main()
{
    array_gen();
    array_disp();
    //merger(arr, 0, SIZE - 1);
    selection_sort(arr, 0, SIZE - 1);
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

    int left[n1 + 1], right[n2 + 1];

    for (int i = 0; i < n1; i++)
    {
        left[i] = arr[p + i];
    }
    
    for (int i = 0; i < n2; i++)
    {
        right[i] = arr[q + 1 + i];
    }

    left[n1]  = 2147483647;
    right[n2] = 2147483647;  

    for ( int k = p, i = 0, j = 0; k < r + 1; k++)
    {
        if (left[i] <= right[j])
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


void selection_sort(int arr[], int first, int last)
{
    // looping from the start to the end
    for(int i = 0; i <= last; ++i)
    {
        // reset min, and pos
        int min = arr[i], pos = i;
        // Checking fro the least element in remaing portion of the array
        for (int j = i + 1; j <= last; ++j)
        {
            // Finding the min element
            if(arr[j] < min)
            {
                // Saving the position
                min = arr[j];
                pos = j;
            }
        }

        // Swapping the min element with i^th element ,
        // Hence bringing least ele first, 2^nd smallest 2^nd so on.. 

        arr[pos] = arr[i];
        arr[i] = min;
    }

    return;
}

/*
In the module herin we have discussed the following topics
    2.2 Runtimes, an informal introduction to thetha of n, or worst case run time complexity.
    Exercises
        2.2-1 0(n^3): Since the highest ordered terms order is the power / exponent at which the 
                        function grows.
        2.1-3 Implementation  of Selection sort.
        2.1-4 Binary Adder
*/