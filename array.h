#ifndef ARRAY_H
#define ARRAY_H

#include <iostream> //iostream.h for old C/C++
#include <stdlib.h>

int* mem_array(int); //alloc memory for array

int* fill_array(int, int, int);
int* sort_array(int*, int); 

int bin_search(int*, int, int); //binary search

void print_array(int*, int);

int* mem_array(int size)
{
    return new int[size];
}

int* fill_array(int size, int low_border, int high_border)
{
    int *array = mem_array(size);

    for (int i = 0; i < size; i++) array[i] = rand() % low_border + high_border;

    return array;
}

int* sort_array(int* array, int size)
{
    int middle;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (array[i] > array[i+1])
            {
                middle = array[i];
                array[i] = array[i+1];
                array[i+1] = middle;
            }
        }
    }

    return array;
}

int bin_search(int* array, int size, int target)
{
    array = sort_array(array, size);

    int min = 0;
    int max = size;
    int middle = (min + max) / 2;

    for (int i = 0; i < size; i++)
    {
        if (array[middle] > target) max = middle;
        if (array[middle] < target) min = middle;
        if (array[middle] == target) return middle;
        middle = (min + max) / 2;
    }

    std::cout << "Can't find target " << target << std::endl;
    return -1;
}

void print_array(int* array, int size)
{
    for (int i = 0; i < size; i++) std::cout << array[i] << "\t";
}

#endif