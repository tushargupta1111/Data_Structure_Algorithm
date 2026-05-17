#include<bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
        vector<int> arr;

    //  O(log N) Time complexity insert & delete element in Heap DS
    void insert(int value)
    {
        arr.push_back(value);
        int index = arr.size()-1;
        
        while(index>0)
        {
            int parentindex =(index-1)/2;
            if(arr[index] > arr[parentindex])
            {
                swap(arr[index],arr[parentindex]);
                index = parentindex;
            }
            else break;
        }
    }


    void deletes()
    {
        swap(arr[0],arr[arr.size()-1]);
        arr.pop_back();
        int i = 0;
        while(i<arr.size())
        {
            int largest=i;
            int left =i*2+1;
            int right =i*2+2;
            if(left < arr.size() && arr[left] > arr[largest])
                largest = left;
            if(right < arr.size() && arr[right] > arr[largest])
                largest = right;
            
            if(largest != i)
                swap(arr[i],arr[largest]) , i =largest;
            else break;

        }
    }

    void print()
    {
        for(auto i : arr)
            cout<<i<<" ";
        cout<<endl;
    }
};


int main()
{
    MaxHeap heap;

    heap.insert(20);
    heap.insert(12);
    heap.insert(16);
    heap.insert(25);
    heap.print();
    heap.deletes();
    heap.print();

    return 0;
}
