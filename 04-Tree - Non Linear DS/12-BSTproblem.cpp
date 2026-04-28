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

// Level Order traversal
void levelorderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL); // Separator

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
                q.push(NULL);
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}

// Inorder traversal
void inordertraverse(node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inordertraverse(root->left, in);
    in.push_back(root->data);
    inordertraverse(root->right, in);
}

// inorder traversal --->  BST
node *BSTusingInorder(vector<int> inorder, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    node *root = new node(inorder[mid]);

    root->left = BSTusingInorder(inorder, s, mid - 1);
    root->right = BSTusingInorder(inorder, mid + 1, e);

    return root;
}

// Marge 2 BST 
node* Marge2BST(node* root1,node* root2)
{
    vector<int> inorder;
    inordertraverse(root1,inorder);
    inordertraverse(root2,inorder);
    sort(inorder.begin(),inorder.end());
    node* root = BSTusingInorder(inorder,0,inorder.size()-1);
    return root;
}

int main()
{
    node *root1 = NULL;
    node *root2 = NULL;
    buildtree(root1);
    buildtree(root2);
    node* root = Marge2BST(root1,root2);
    levelorderTraversal(root);
    return 0;
}