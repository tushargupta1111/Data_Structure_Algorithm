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

node *buildTree(node *root)
{
    cout << "Enter the Data : ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data for inserting in left : " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Enter data for inserting in right : " << root->data << endl;
    root->right = buildTree(root->right);
    return root;
}
// Inorder Traversal 
// Morris Traversal (time complixity:- O(n) && space complixity:- O(1))
void morristraversal(node* root)
{
    node* curr = root;
    while(curr!= NULL)
    {
        if(curr->left == NULL)
        {
            cout<<curr->data<<" ";
            curr = curr->right;
        }
        else
        {
            node* pred = curr->left;
            while(pred->right != NULL && pred->right != curr)
                pred = pred->right;

            if(pred->right == NULL)
            {
                pred->right =curr;
                curr = curr->left;
            }
            else
            {
                pred->right =NULL;
                cout<<curr->data<<" ";
                curr = curr->right;
            }
        }
    }
}

// Flatter BT to Linked list
void flatter(node* root)
{
    node* curr = root;
    while(curr !=NULL)
    {
        if(curr->left)
        {
            node* pred =curr ->left;
            while(pred->right)
                pred = pred->right;

            pred->right =curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}
int main()
{
    node* root = NULL;
    root = buildTree(root);

    // Convert BT into linked List
    flatter(root);

    cout<<"Morris Traversal : "<<endl;
    morristraversal(root);

    return 0;
}
