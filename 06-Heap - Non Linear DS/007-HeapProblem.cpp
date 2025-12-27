#include<bits/stdc++.h>
using namespace std;


// Merge k Sorted Linked List
class node{
    public:
        int data;
        node* next;

    node(int d)
    {
        this->data=d;
        this->next=NULL;
    }
};

class compare
{
    public:
        bool operator()(node* a,node* b)
        {   
            return a->data > b->data;
        }
};


void printList(node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}

// Merge Kth Sorted Linked List Using Brute Force (#1 Approach)
// Merge Kth Sorted Linked List Using Merge Sort (#2 Approach)

// Merge Kth Sorted Linked List Using Priority Queue and Store all the data in PQ (#3 Approach)
node* mergekLists(vector<node*>& arr)
{
   priority_queue<int,vector<int>,greater<int>> pq;

    for(auto i : arr)
    {
        while(i!=NULL)
        {
            pq.push(i->data);
            i=i->next;
        }   
    }

    node* head = new node(pq.top());
    pq.pop();

    node*  tail = head;

    while(!pq.empty())
    {
        node* temp =  new node(pq.top());
        pq.pop();
        tail->next = temp;
        tail = temp;
    }
    return head;
}

// ___________________________________________________________________________
// Merge  Kth Sorted Linked List Using Priority Queue Of K Size (#4 Approach)
// node* mergekLists(vector<node*>& arr)
// {
//     priority_queue<node*,vector<node*>,compare> pq(arr.begin(),arr.end());
//     node* head = new node(0);
//     node* tail = head;

//     node* temp;

//     while(!pq.empty())
//     {
//         temp = pq.top();
//         pq.pop();
//         tail->next = temp;
//         tail = tail->next;
//         if(temp->next)
//             pq.push(temp->next);
//     }

//     return head->next;
// }

// _______________________________________________________________________________
// Merge  Kth Sorted Linked List Using Priority Queue Of K Size (#5 Approach)
// node* mergekLists(vector<node*>& arr)
// {
//     priority_queue<pair<int,node*>, vector<pair<int,node*>>,greater<pair<int,node*>>> pq;

//     for(auto i :arr)
//         pq.push({i->data,i});

//     node* head = new node(0);
//     node* tail = head;

//     while(!pq.empty())
//     {
//         auto temp = pq.top();
//         pq.pop();
//         tail->next = temp.second;
//         tail = tail->next;
//         if(temp.second->next)
//             pq.push(make_pair(temp.second->next->data,temp.second->next));
//     }
//     return  head->next;
// }


//  Merged k Sorted Array (#1 Approach)
// vector<int> mergeKArrays(vector<vector<int>> arr,int K)
// {
//     vector<int> ans;

//     for(auto i : arr)
//         for(auto j :i)
//             ans.push_back(j);

//     sort(ans.begin(),ans.end());
//     return ans;
// }
// ______________________________________________________
// Merge  k Sorted Arrays (#2 Approach)
vector<int> mergeKArrays(vector<vector<int>> arr,int K)
{
    priority_queue<int,vector<int>,greater<int>> pq;

    for(auto i : arr)
        for(auto j : i)
            pq.push(j);

    vector<int> ans;
    while(!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;    
}
// ________________________________________________________________
// Merge K Sorted Arrays (#3 Approach)
// vector<int> mergeKArrays(vector<vector<int>> arr, int K)
//     {
//         vector<int> ans;
        
//         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        
//         for(int i=0; i<K ; i++)
//             pq.push({arr[i][0],{i,0}});
            
            
//         while(!pq.empty())
//         {
//             auto top =pq.top();
//             pq.pop();
            
//             ans.push_back(top.first);
            
//             int i = top.second.first;
//             int j = top.second.second;

//             if(j+1<K)
//                 pq.push({arr[i][j+1],{i,j+1}});
//         }
//         return ans;
//     }


int main()
{
    node* list1 = new node(1);
    list1->next = new node(2);
    list1->next->next = new node(3);
    
    node* list2 = new node(4);
    list2->next = new node(5);
    list2->next->next = new node(6);
    
    node* list3 = new node(7);
    list3->next = new node(8);
    
    vector<node*> arr = {list1, list2, list3};
    
    node* mergedList = mergekLists(arr);
    
    // Print the merged list
    printList(mergedList);
    
    vector<vector<int>> arr1={{3,4,5,11},{1,6,7,14},{4,5,8,13},{6,9,10,12}};
    vector<int> ans = mergeKArrays(arr1, 4);
    cout<<"Merge K Arrays: ";
    for(auto it:ans)
        cout<<it<<" ";
    return 0;
}