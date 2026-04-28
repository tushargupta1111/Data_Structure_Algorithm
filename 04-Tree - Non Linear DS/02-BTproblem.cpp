#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = this->right = NULL;
    }
};

// Height of Binary Tree
int height(node *root)
{
    if (root == NULL)
        return -1;
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}

// Diameter of binary tree
int diameter(node *root)
{
    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + height(root->right) + 1;

    return max(op3, max(op1, op2));
}

// Balanced binary tree
bool isbalanced(node *root)
{
    if (root == NULL)
        return true;

    int leftheight = height(root->left);
    int rightheight = height(root->right);
    int diff = abs(leftheight - rightheight);

    bool ans = (diff <= 1);

    bool leftans = isbalanced(root->left);
    bool rightans = isbalanced(root->right);
    if (ans && leftans && rightans)
        return true;
    else
        return false;
}

//Identical Tree
bool Identicaltree(node* root1,node* root2)
{
    if(root1 == NULL && root2 == NULL) 
        return true;
    if(root1 != NULL && root2 !=  NULL)
        return false;

    bool left = Identicaltree(root1->left,root2->left);
    bool right = Identicaltree(root1->right,root2->right);
    bool same = root1->data == root2->data;

    if(left && right && same)
        return true;
    else
        return false;
}

//Sum Tree
bool sumtree(node* root)
{
    if(root ==NULL)
        return true;
    
    bool left = sumtree(root->left);
    bool right = sumtree(root->right);
    bool compare =root->data == root->left->data + root->right->data;

    if(left && right && compare)
        return true;
    else
        return false;
}


int main()
{
    return 0;
}