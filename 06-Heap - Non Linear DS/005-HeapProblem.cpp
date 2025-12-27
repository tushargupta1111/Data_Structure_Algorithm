#include<bits/stdc++.h>
using namespace std;

class node
{
    public:
        int data;
        node* left;
        node* right;

        node(int d)
        {
            this->data=d;
            this->left=this->right=NULL;
        }
};

void heapify(vector<int>& merge,int index,int n)
{
    int largest = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if(left<n && merge[left] > merge[largest])
        largest = left;
    if(right<n && merge[right] > merge[largest])
        largest = right;

    if(largest != index)
    {
        swap(merge[index],merge[largest]);
        heapify(merge,largest,n);
    }
}

// Merge Two Binary MaxHeap
vector<int> mergeMaxHeap(vector<int> heap1,vector<int> heap2)
{
    vector<int> merge;
    for(auto i : heap1)
        merge.push_back(i);
    
    for(auto i : heap2)
        merge.push_back(i);

    int n=merge.size();
    for(int i=n/2-1; i>=0; i--)
        heapify(merge,i,n);

    return merge;
}

// Is Binary Tree --> Heap(maxheap)
int count_nodes(node* root)
{
    if(!root) return 0;

    return 1+count_nodes(root->left)+count_nodes(root->right);
}

bool CBT(node* root,int count,int n)
{
    if(!root) return true;

    if(count>=n) return false;

    return CBT(root->left,2*count+1,n) && CBT(root->right,2*count+2,n);
}

bool MaxHeap(node* root)
{
    if(root->left)
    {
        if(root->data < root->left->data) return false;

        if(!MaxHeap(root->left)) return false;
    }

    if(root->right)
    {
        if(root->data < root ->right->data) return false;

        return MaxHeap(root->right);
    }

    return true;
}

bool BTHeap(node* root)
{
    if(!root) return true;

    int num = count_nodes(root);

    if(!CBT(root,0,num))  return false;

    return MaxHeap(root);    
}

// BST to max heap
void inorder(node* root, vector<int>& arr)
{
    if(!root) return;

    inorder(root->left,arr);
    arr.push_back(root->data);
    inorder(root->right,arr);
}

void postorder(node* root,vector<int>& arr,int& index)
{
    if(!root) return;

    postorder(root->left,arr,index);
    postorder(root->right,arr,index);
    root->data = arr[index++];
}

void BSTtoMaxHeap(node* root)
{   
    // Inorder Traversal
    vector<int> arr;
    inorder(root,arr);

    // Postorder Traversal (fill the value)
    int index = 0;
    postorder(root,arr,index);
}


int main()
{
    // vector<int> heap1={10,5,6,2};
    // vector<int> heap2={12,7,9};

    // vector<int> result =mergeMaxHeap(heap1,heap2);

    // for(auto i : result)
    //     cout<<i<<" ";
    // cout<<endl;

    node* root = new node(4);
    root->left = new node(2);
    root->right = new node(6);
    root->left->left = new node(1);
    root->left->right= new node(3);
    root->right->left = new  node(5);
    root->right->right = new node(7);

    // cout<<"Is Binary Tree is Heap : "<<BTHeap(root)<<endl;
    
    BSTtoMaxHeap(root);
    vector<int> arr;
    inorder(root,arr);

    for(auto i : arr)
        cout<<i<<" ";
    cout<<endl;


    return 0;
}