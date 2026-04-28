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
        this->data =d;
        this->left = this->right =NULL;
    }
};

//  Construct BST from Inorder
node* BSTusingInorder(int inorder[],int s,int e)
{
    if(s > e)
        return NULL;

    int mid =(s+e)/2;
    node* root = new node(inorder[mid]);

    root->left = BSTusingInorder(inorder,s,mid-1);
    root->right = BSTusingInorder(inorder,mid+1,e);

    return root;
}

// Binary Search Tree ---> Doubly Linked List 
void BSTintoLinkedList(node* root,node* &head)
{
    if(root==NULL)
        return;

    BSTintoLinkedList(root->right,head);
    root->right =head;
    if(head !=NULL)
        head->left =root;
    head =root;
    BSTintoLinkedList(root->left,head);
 
}


// Sorted Linked list  ---> Binary Search tree
node* LinkedListintoBST(node* head,int n)
{
    if( n<=0 || head==NULL)
        return NULL;
    
    node* leftsubtree = LinkedListintoBST(head,n/2-1);
    node* root = head;
    root->left = leftsubtree;
    head = head->right;

    root->right = LinkedListintoBST(head,n/2);
    return root;
}


int main()
{
    return 0;
}