//  Name: Matthew Jensen
//  Assignment number: 6
//  Assignment: Sorting Comparison
//  File name: sorting.cpp
//  Date last modified: November 14, 2021
//  Honor statement: I have neither given nor received any unauthorized help on this assignment. 

#include <iostream>
#include <algorithm> // std::sort
#include <vector>    // std::vector
#include "Stopwatch.h"

// selection sort
void selection_sort(std::vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (v[j] < v[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            int temp = v[i];
            v[i] = v[min];
            v[min] = temp;
        }
    }
}

// insertion sort
void insertion_sort(std::vector<int> &v)
{
    int size = v.size();
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (j > 0 && v[j] < v[j - 1])
        {
            int temp = v[j];
            v[j] = v[j - 1];
            v[j - 1] = temp;
            j--;
        }
    }
}

// exchange sort
void exchange_sort(std::vector<int> &vec)
{
    int n = vec.size();
    int k = 0;
    bool sorted = false;
    while (k < n - 1 && !sorted)
    {
        sorted = true;
        for (int i = 0; i < n - k - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                std::swap(vec[i], vec[i + 1]);
                sorted = false;
            }
        }
        k++;
    }
}

// heapsort
void heapify(std::vector<int> &v, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && v[l] > v[largest])
    {
        largest = l;
    }
    if (r < n && v[r] > v[largest])
    {
        largest = r;
    }
    if (largest != i)
    {
        int temp = v[i];
        v[i] = v[largest];
        v[largest] = temp;
        heapify(v, n, largest);
    }
}

void heap_sort(std::vector<int> &v)
{
    int size = v.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(v, size, i);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = v[0];
        v[0] = v[i];
        v[i] = temp;
        heapify(v, i, 0);
    }
}

// quicksort
int partition(std::vector<int> &v, int low, int high)
{
    int pivot = v[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
        }
    }
    int temp = v[i + 1];
    v[i + 1] = v[high];
    v[high] = temp;
    return i + 1;
}

void quicksort(std::vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int p = partition(v, low, high);
        quicksort(v, low, p - 1);
        quicksort(v, p + 1, high);
    }
}

// quick sort helper
void quick_sort(std::vector<int> &v)
{
    quicksort(v, 0, v.size() - 1);
}

// print vector
void print_vector(std::vector<int> &v)
{
    int size = v.size();
    for (int i = 0; i < size; i++)
    {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

// test sort
void test_sort(std::vector<int> &v, void (*sort)(std::vector<int> &))
{
    std::vector<int> v_copy = v;
    Stopwatch timer;
    timer.start();
    sort(v_copy);
    timer.stop();
    std::cout << "Time: " << timer.elapsed() << std::endl;
    //print_vector(v_copy);
}

// test std sprt
void test_std_sort(std::vector<int> &v)
{
    std::vector<int> v_copy = v;
    Stopwatch timer;
    timer.start();
    std::sort(v_copy.begin(), v_copy.end());
    timer.stop();
    std::cout << "Time: " << timer.elapsed() << std::endl;
    //print_vector(v_copy);
}

void sort_helper(int n)
{
    std::cout << "Testing sorts on arrays of size " << n << std::endl;

    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back(rand() % 100000); // generates an array of random numbers between 0 and 100000
    }

    std::cout << "Standard Sort" << std::endl;
    test_std_sort(v);

    std::cout << "Selection Sort" << std::endl;
    test_sort(v, selection_sort);

    std::cout << "Insertion Sort" << std::endl;
    test_sort(v, insertion_sort);

    std::cout << "Exchange Sort" << std::endl;
    test_sort(v, exchange_sort);

    std::cout << "Heap Sort" << std::endl;
    test_sort(v, heap_sort);

    std::cout << "Quick Sort" << std::endl;
    test_sort(v, quick_sort);
}

int main()
{
    sort_helper(10);
    sort_helper(100);
    sort_helper(1000);
    sort_helper(10000);
    sort_helper(100000);
}
