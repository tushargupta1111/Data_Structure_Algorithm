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

// Searching node in BST
node *findnodeBST(node *root, int data)
{
    if (root == NULL)
        return NULL;
    if (root->data == data)
        return root;

    if (root->data > data)
        return findnodeBST(root->left, data);
    else
        return findnodeBST(root->right, data);
}

// Maximum/Minimum node in BST
node *min(node *root)
{
    if (root == NULL)
        return NULL;
    node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}
node *max(node *root)
{
    if (root == NULL)
        return NULL;
    node *temp = root;
    while (temp->right != NULL)
        temp = temp->right;
    return temp;
}

// Deleting node in BST
node *deletenodeBST(node *root, int target)
{
    if (root == NULL)
        return NULL;

    if (root->data == target)
    {
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            node *temp = root->left;
            delete root;
            return temp;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            node *temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            node *child = max(root->left);
            root->data = child->data;
            root->left = deletenodeBST(root->left, child->data);
            return root;
        }
    }
    else if (root->data > target)
    {
        root->left = deletenodeBST(root->left, target);
        return root;
    }

    else
    {
        root->right = deletenodeBST(root->right, target);
        return root;
    }
}

int main()
{
    // Input :- 10 5 20 11 17 15 8 2 4 6 25 -1
    node *root = NULL;
    cout << " Enter the node for BST : ";
    buildtree(root);
    // int data;
    // while (cin >> data && data != -1)
    //     root = buildAndInsertBST(root, data);

    cout << "Levelorder traversal in BST : " << endl;
    levelorderTraversal(root);
    // cout<<endl<< "Maximum node : "<< max(root)->data;
    // cout<<endl<< "Minimum node : "<< min(root)->data;
    root = deletenodeBST(root, 20);
    cout << endl
         << "Levelorder traversal in BST : " << endl;
    levelorderTraversal(root);
    return 0;
}