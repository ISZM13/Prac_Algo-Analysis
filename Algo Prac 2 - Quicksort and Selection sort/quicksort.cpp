#include<iostream>
#include <cstdlib>

using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[start];

    int count = 0;
    
    for(int i = start; i < end; i++)
    {
        if(arr[i] < pivot)
        count++;
    }

    int pivot_index = start + count;
    swap(arr[start], arr[pivot_index]);

    int i = start;
    int j = end;

    while(i < pivot_index && j > pivot_index)
    {
        while(i < pivot_index)
        {
            i++;
        }
        while(j > pivot_index)
        {
            j--;
        }
    }
    swap(arr[i++], arr[j--]);
    
    return pivot_index;
}

void quicksort(int arr[], int start, int end)
{
    int p = partition(arr, start, end);

    quicksort(arr, start , p-1);
    quicksort(arr, p + 1, end);
}

int main()
{
    int start;

    int arr[100000];
    
    cout<<"Enter number of elements: ";
    int num;
    cin>>num;

    for(int i = 0; i < num; i++)
    {
        arr[i] = rand()%num;
    }

    quicksort(arr, 0, num - 1);
    
    cout<<"Sorted array: ";
    for(int i = 0; i < num; i++)
    {
        cout<<arr[i] << ' ';
    }
    return 0;
}