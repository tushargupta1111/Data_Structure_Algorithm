#include<bits/stdc++.h>
using namespace std;

// Height Of Heap tree
int HeightHeap(vector<int>& arr)
{
    int n=arr.size(),height=0;
    while(n!=1)
    {
        height++;
        n /= 2;
    }
    return height;
    // return log2(arr.size());
}

// Minimum cost of Ropes
int MinCostRope(vector<int>& arr)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    int cost = 0;

    for(auto i: arr)
        pq.push(i);

    while(pq.size() != 1)
    {  
        int rope = pq.top();
        pq.pop();
        rope += pq.top();
        pq.pop();
        cost += rope;
        pq.push(rope); 

    }
    return cost;
}

// Magician and chocolates
int Chocolates(vector<int>& arr,int time)
{
    priority_queue<int> pq;
    int choco = 0;

    for(auto i : arr)
        pq.push(i);

    while(time!=0 && time--)
    {
        int eat = pq.top();
        pq.pop();
        choco +=eat;
        pq.push(eat/2);
    }
    return choco;
}

// Last Stone Weight
int laststone(vector<int>& arr)
{
    priority_queue<int> pq; 

    for(auto i :arr)
        pq.push(i);

    while(pq.size() > 1)
    {
        int weight = pq.top();
        pq.pop();
        weight -= pq.top();
        pq.pop();

        if(weight > 0)
            pq.push(weight);
    }
     return pq.empty() ? 0 : pq.top();
}

// Take gift from Richest pile
int richestpile(vector<int>& arr,int A)
{
    priority_queue<int> pq;
    int pile = 0;

    for(auto i :arr)
        pq.push(i);
    
    while(A != 0 && A--)
    {
        int gift =sqrt(pq.top());
        pq.pop();

        pile +=gift;
        pq.push(gift); 
    }
    return pile;
}

// Profit Maximisation
int profitMaximize(vector<int>& arr,int B)
{
    priority_queue<int> pq;
    int profit = 0;

    for(auto i :arr)
        pq.push(i);
    
    while(B != 0 && B--)
    {
        int ticket =pq.top();
        pq.pop();

         profit+=ticket;
        pq.push(ticket-1); 
    }
    return profit;
}



int main()
{
    vector<int> arr={6,5,3,4,2};
    // cout<<"Height of Heap Tree : "<<HeightHeap(arr);
    // cout<<"Minmum Cost Of Rope : "<<MinCostRope(arr);
    // cout<<"Maximum Chocolates Eat : "<<Chocolates(arr,5);
    // cout<<"Last Stone Weight : "<<laststone(arr);
    // cout<<"Take gift from richest PIle : "<<richestpile(arr,5);
    // cout<<"Profit Maximisation : "<<profitMaximize(arr,5);

    return 0;
}