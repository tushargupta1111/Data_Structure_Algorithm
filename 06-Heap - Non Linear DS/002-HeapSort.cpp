#include<bits/stdc++.h>
using namespace std;

// O(N) Time Complexity Using Step Down apporach
void heapify(vector<int>& arr,int index,int n)
{
    int largest=index;
    int left=index*2+1;
    int right=index*2+2;

    if(left<n && arr[left]>arr[largest])
        largest =left;
    if(right<n && arr[right]>arr[largest])
        largest=right;
    
    if(largest != index)
    {
        swap(arr[index],arr[largest]);
        heapify(arr,largest,n);
    }
}

void BuildMaxHeap(vector<int>& arr)
{
    int n=arr.size()-1;
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,i,n);
}

void HeapSort(vector<int>& arr)
{
    // BuildMaxHeap(arr);
    for(int i=arr.size()-1;i>0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,0,i);
    }
}

void print(vector<int>& arr)
{
    cout<<"Printing the Max Heap Data Structure : ";
    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;
}

int main()
{
    vector<int> arr={14,15,12,22,17,20,18,24,23,30,19};
    BuildMaxHeap(arr);
    print(arr);
    HeapSort(arr);
    print(arr);
    return 0;
}