#include<iostream>
#include<stdlib.h>
#include<omp.h>

using namespace std;

void bubble(int *arr,int n)
{
    for(int i=0;i<n-1;i++)
    {
        #pragma omp parallel for shared(arr,swap)
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void swap(int &a, int &b)
{
    int test;
    test=a;
    a=b;
    b=test;

}


int main()
{
    int n;
    cout<<"No of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    bubble(arr,n);
    cout<<"sorted array : ";
    for(int num : arr)
    {
        cout<<num<<endl;
    }
    return 0;
}
