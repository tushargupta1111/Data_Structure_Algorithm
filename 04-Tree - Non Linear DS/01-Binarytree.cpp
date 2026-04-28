#include<bits/stdc++.h>
using namespace std;

//Defining the structure of Binary Tree
class node{
    public:
        int data;
        node* left;
        node* right;

    //Inserting a data in node through Constructor
    node(int d)
    {
        this->data=d;
        this->left=this->right=NULL;
    }
};

//Building the Binary tree with basic way
node* buildTree(node* root)
{
    cout<<"Enter the Data : ";
    int data;
    cin>>data;
    root = new node(data);

    if(data==-1)
        return NULL;

    cout<<"Enter data for inserting in left : "<<root->data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right : "<<root->data<<endl;
    root->right = buildTree(root->right);
    return root;
}

//Level Order traversal (using Queue to traverse in Binary Tree)
void levelorderTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL); // Separator

    while(!q.empty())
    {
        node* temp = q.front();
        q.pop();
        if(temp == NULL)
        {
            cout<<endl;
            if(!q.empty())
                q.push(NULL);
        }
        else
        {
            cout<<temp->data<<" ";
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
} 

//Inorder Traversal (L N R)
void inorder(node* root)
{
    if(root==NULL)
        return;

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//Preorder Traversal (N L R)
void preorder(node* root)
{
    if(root==NULL)
        return;

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//Postorder traversal (L R N)
void postorder(node* root)
{
    if(root==NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//Building a binary tree with level way
node* buildfromlevelorder(node* root)
{
    queue<node*> q;
    cout<<"Enter data for root : ";
    int data;
    cin>>data;
    root=new node(data);
    q.push(root);

    while(!q.empty())
    {
        node* temp =q.front();
        q.pop();

        cout<<"Enter left node for : "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData != -1)
        {
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        cout<<"Enter Right node for : "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData != -1)
        {
            temp->right = new node(rightData);
            q.push(temp->right);
        }
    }
    return root;

}

int main()
{
    node* root =NULL;
    
    //Input Data :- 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
    //Creating a Binary tree
    // root =buildTree(root);

    //Creating a Binary Tree through Level Order Traversal
    //Input Data :- 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1 
    root =buildfromlevelorder(root);


    //Level Order Traversal
    cout<<"Printing the Level Order Traversal : "<<endl;
    levelorderTraversal(root);

    //Inorder Traversal
    cout<<"Inorder Traversal : ";
    inorder(root);

    //Preorder Traversal 
    cout<<endl<<"Preorder Traversal : ";
    preorder(root);

    //Postorder Traversal  
    cout<<endl<<"PostOrder Traversal : ";
    postorder(root);

    return 0;
}

//Homework :- Reverse Level Order Traversal
//Inorder,Preorder,Postorder Traversal Using Iteration 
//Problem :- Counting leaf Node in Binary tree