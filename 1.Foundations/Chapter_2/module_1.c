/*
Code by Rishav Bhagat

An implentation of algorithms presented in the book Introduction to Algorithms

FIRST :
Insertion Sort 


*/

// Linkers
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global

#define RANGE 999
#define SIZE 10


// Prototypes
void random_gen(int *arr); 
void display(int *arr);
void insertion_sort_increasing(int *arr);
void insertion_sort_decreasing(int *arr);
void random_gen_binary(int *arr);
void bin_add(int* a, int* b, int* sum);
void display_sum(int *arr);

// Main function
void main()
{
    int a[SIZE], b[SIZE], c[SIZE + 1];
    random_gen_binary(a);
    random_gen_binary(b);
    printf("\na:\n");
    display_sum(a);
    printf("\nb:\n");
    display_sum(b);
    bin_add(a, b, c);
    printf("\nc:\n");
    display_sum(c);

}


/*

PSUEDOCODE

1 for j = 2 to A.length
2 key = A[j]
3 // Insert A[j] into the sorted sequence A[1 . . . j - 1]
4 i = j - 1
5 while i > 0 and A[i] > key
6   A[i + 1]  = A[i]
7   i = i - 1
8 A[i + 1] = key

Essentially we are bringing a new element in the second for loop each time and then are appropriately positioning it.

--------
Runtime 
--------
Big O(n) = 
Omega(n) =
*/


void insertion_sort_increasing(int *arr)
{
    int i;
    for (int j = 1; j < SIZE; j++)
    {
        int key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key)
        {
            arr[i + 1] = arr[i] ;
            --i;           
        }
        arr[i + 1] = key;
    }
}


void insertion_sort_decreasing(int *arr)
{
    int i;
    for (int j = 1; j < SIZE; j++)
    {
        int key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] < key)
        {
            arr[i + 1] = arr[i] ;
            --i;           
        }
        arr[i + 1] = key;
    }
}

// A function which genarates random array values spanning from 0 to RANGE()
void random_gen(int *arr)
{
    srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        int ele = rand() % RANGE;
        arr[i] = ele;
    }
}

void random_gen_binary(int *arr)
{
    //srand(time(0));
    for (int i = 0; i < SIZE; i++)
    {
        int ele = rand() % 2;
        arr[i] = ele;
    }
}

void bin_add(int* a, int* b, int* sum)
{
    int carry = 0;
    for (int i = 0; i < SIZE; i++)
    {
        sum[i] = a[i] + b[i] + carry;
        carry = sum[i] / 2;
        sum[i] %= 2; 
    }
    sum[SIZE] = carry;
}

int linear_search(int* arr, int x)
{
    for(int i = 0; i < SIZE; i++)
    {
        if (arr[i] = x)
        {
            x = i;
            return x;
        }
    }
    return -1;
}


// Display the array 
void display(int *arr)
{
    for (int i = 0; i < SIZE; i++)
    {
        if(i % 10 == 0)
            printf("\n");
        printf("%d\t", arr[i]);
    }
}

void display_sum(int *arr)
{
    for (int i = SIZE ; i >= 0 + 1; i--)
    {
        printf("%d\t", arr[i]);
    }
}




/*
In the chapter herin we have discussed the following topics
    2.1 Insertion sort
    Exercises
        2.1-2 Insertion sort (Decresing)
        2.1-3 Linear Search
        2.1-4 Binary Adder
*/