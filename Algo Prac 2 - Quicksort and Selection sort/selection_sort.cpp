// Online C++ compiler to run C++ program online
#include<iostream>
#include <cstdlib>
using namespace std;


void selection_sort(int arr[], int length);
int main()
{
    int arr[100000] ;
    cout<<"Enter number: ";
    int num;
    cin>>num;
    for(int i =0; i < num; i++)
    {
        arr[i]=rand()%num;
    }

    selection_sort(arr, num);
}

void selection_sort(int arr[], int length)
{
    int i = 0;

    for(i = 0; i < length - 1; i++)
    {
        int min = i;

        for(int j = 0; j < length; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
            swap(arr[i], arr[min]);
        }
    }
    cout<<"Sorted array: ";
    for(int k = 0; k < length; k++)
    {
        cout<< arr[k] << ' ';
    }
}