#include <bits/stdc++.h>
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

// Build Binary Search Tree
node *buildAndInsertBST(node *root, int data)
{
    if (root == NULL)
        return new node(data);

    if (data < root->data)
        root->left = buildAndInsertBST(root->left, data);
    else
        root->right = buildAndInsertBST(root->right, data);
    return root;
}

void buildtree(node *&root)
{
    int data;
    while (cin >> data && data != -1)
        root = buildAndInsertBST(root, data);
}

// Validate BST
bool solve(node *root, int lb, int ub)
{
    if (root == NULL)
        return true;

    if (root->data > lb && root->data < ub)
    {
        bool left = solve(root->left, lb, root->data);
        bool right = solve(root->right, root->data, ub);

        return left && right;
    }
    return false;
}

bool isvalid(node *root)
{
    int lowerbound = INT_MIN;
    int upperbound = INT_MAX;

    return solve(root, lowerbound, upperbound);
}

//  Kth smallest element  in BST
int kthsmallestBST(node *root, int k)
{
    if (root == NULL)
        return -1;

    int left = kthsmallestBST(root->left, k);
    if (left != -1)
        return left;

    k--;
    if (k == 0)
        return root->data;

    return kthsmallestBST(root->right, k);
}

// LCA of BST
node *LCA(node *root, int p, int q)
{
    if (root == NULL)
        return NULL;

    if (p < root->data && q < root->data)
        return LCA(root->left, p, q);
    else if (p > root->data && q > root->data)
        return LCA(root->right, p, q);

    return root;
}

// Inorder Predecessor / Successor
pair<int, int> predeccessorSuccessor(node *root, int key)
{
    node *temp = root;
    int pred = -1, succ = -1;

    while (temp->data != key)
    {
        if (temp->data > key)
        {
            succ = temp->data;
            temp = temp->left;
        }
        else
        {
            pred = temp->data;
            temp = temp->right;
        }
    }

    node *leftans = temp->left;
    while (leftans != NULL)
    {
        pred = leftans->data;
        leftans = leftans->right;
    }

    node *rightans = temp->right;
    {
        succ = rightans->data;
        rightans = rightans->left;
    }

    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}

int main()
{
    node *root = NULL;
    cout << " Enter the value for BST : ";
    buildtree(root);
    cout << kthsmallestBST(root, 2);

    return 0;
}