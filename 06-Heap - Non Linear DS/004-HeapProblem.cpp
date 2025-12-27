#include<bits/stdc++.h>
using namespace std;

// Kth Smallest element in array
int ksmallest(vector<int>& arr,int k)
{
    priority_queue<int> pq;

    for(int i=0;i<k;i++)
        pq.push(arr[i]);

    for(int i=k;i<arr.size();i++)
    {
        if(arr[i]<pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

// Kth Largest element in array
int klargest(vector<int>& arr,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;

    for(int i=0;i<k;i++)
        pq.push(arr[i]);

    for(int i=k;i<arr.size();i++)
    {
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    return pq.top();
}

// Kth largest element in stream
vector<int> klargeststream(vector<int>& arr,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans(arr.size(),-1);

    for(int i=0;i<arr.size();i++)
    {
        pq.push(arr[i]);
        if(pq.size()>k)
            pq.pop();
        if(pq.size()==k)
            ans[i]=pq.top();
    }
    return ans;
}

// Sum of Elements b/w k1 and k2 smallest element 
int sumofelements(vector<int>& arr,int k1,int k2)
{
    priority_queue<int> p1;
    priority_queue<int> p2;

    for(int i=0;i<k1;i++)
        p1.push(arr[i]);

    for(int i=0;i<k2;i++)
        p2.push(arr[i]);

    int sum1=0;
    while(!p1.empty())
    {
        sum1 += p1.top();
        p1.pop();
    }
    int sum2=0;
    while(!p2.empty())
    {
        sum2 += p2.top();
        p2.pop();
    }
    return sum2-sum1;
}

int main()
{
    vector<int> arr={22,8,20,4,12,10,14};
    // cout<<"Kth Smallest Element : "<<ksmallest(arr,4);
    // cout<<"kth Largest Element : "<<klargest(arr,3);
    // vector<int> ans=klargeststream(arr,4);
    // for(auto i : ans)
    //     cout<<i<<" ";
    // cout<<endl;
    // cout<<"Sum of elements : "<<sumofelements(arr,3,6);
    return 0;
}