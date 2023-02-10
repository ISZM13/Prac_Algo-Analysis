#include<iostream>
using namespace std;

#include<vector>
// #include<cstdlib>
#include<bits/stdc++.h>
vector<int> temp;
int divide(vector<int> arr, int start, int end);
int conquer(int num);

int divide(vector<int> arr, int start, int end)
{
    int mid = (start + end)/2;
    if(start == mid)
    {
        if(start==end)
        {
            conquer(arr[start]);
        }
        else
        {
            conquer(arr[start]);
            conquer(arr[start+1]);
        }
    }
    else
    {
        divide(arr, start, mid);
        divide(arr, mid + 1, end);
    }
    return 0;
}

int conquer(int num)
{   
    int done =0;
    for(int i=0; i<int(temp.size());i++)
    {
        if(temp[i]>num)
        {
            temp.insert(temp.begin() + i,1,num);
        }
    }
    if(done==0)
    {
        temp.push_back(num);
    }
    return 0;
}

// int merge_sort(vector<int> arr,int start, int end)
// {
    
// }


int main()
{
cout<<"Enter the number of characters in the dataset:";
int n;
cin>>n;
vector<int> dataset;
cout<<endl<<"created dataset";
for(int i=0;i<n;i++)
{
    dataset.push_back(rand()%n);
}
cout<<"done insertion";
cout<<endl<<"You want to show the dataset?";
cout<<"haha";
cout<<endl<<"Press 1 for Yes || 0 for No";
int choice =0 ;
while(choice != 0 && choice!=1)
{
    cin>>choice;
    if(choice != 0 || choice!=1)
    cout<<"\nEnter valid option.\n";
}
if(choice==1)
{
    for(int i=0;i<dataset.size();i++)
    cout<<dataset[i]<<"\t";
}
divide(dataset,0,dataset.size());
cout<<"\nThe dataset has been sorted using merge sort.";
cout<<"Do you wish to see the result?";
cout<<"Press 1 for Yes || 0 for No";
while(choice != 0 || choice!=1)
{
    cin>>choice;
    if(choice != 0 && choice!=1)
    cout<<"\nEnter valid option.";
}
if(choice==1)
{
    for(int i=0;i<dataset.size();i++)
    cout<<temp[i]<<"\t";
}
system("pause");
return 0;
}