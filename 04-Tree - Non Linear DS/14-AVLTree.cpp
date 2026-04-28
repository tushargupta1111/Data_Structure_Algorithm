#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    int height;

    node(int d)
    {
        this->data = d;
        this->left = this->right = NULL;
        this->height = 1;
    }
};
// Levelorder traversal
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

int height(node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getbalance(node *root)
{
    if (!root)
        return 0;
    return height(root->left) - height(root->right);
}

node *rightRotate(node *y)
{
    node *x = y->left;
    node *t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

node *leftRotate(node *x)
{
    node *y = x->right;
    node *t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert node in AVL tree
node *insert(node *root, int data)
{
    if (root == NULL)
        return new node(data);
    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    else
        return root;

    root->height = 1 + max(height(root->left), height(root->right));

    int balanced = getbalance(root);

    // Right Right Case
    if (balanced > 1 && data < root->left->data)
        return rightRotate(root);

    // Left Left Case
    if (balanced < -1 && data > root->right->data)
        return leftRotate(root);

    // Left Right Case
    if (balanced > 1 && data > root->left->data)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Left Case
    if (balanced < -1 && data < root->right->data)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}
// Construct AVL tree
void buildAVLtree(node *&root)
{
    int data;
    while (cin >> data && data != -1)
        root = insert(root, data);
}

node *min(node *root)
{
    if (!root)
        return NULL;
    node *temp = root;
    while (temp->left != NULL)
        temp = temp->left;
    return temp;
}

// Deletion node in AVL Tree
node *deletion(node *root, int target)
{
    if (!root)
        return NULL;

    if (target > root->data)
        root->right = deletion(root->right, target);
    else if (target < root->data)
        root->left = deletion(root->left, target);
    else
    {
        if (!root->left && !root->right)
            return NULL;
        else if (!root->left && root->right)
            return root->right;
        else if (root->left && !root->right)
            return root->left;
        else
        {
            node *child = min(root->right);
            root->data = child->data;
            root->right = deletion(root->right, child->data);
        }
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balanced = getbalance(root);

    // Left Left Case
    if (balanced > 1 && getbalance(root->left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balanced > 1 && getbalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balanced < -1 && getbalance(root->right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balanced < -1 && getbalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

int main()
{
    // Input :-  10 5 20 11 17 15 8 2 4 6 25 -1
    node *root = NULL;
    cout << "Enter the node for AVL Tree : ";
    buildAVLtree(root);

    // root = insert(root, 10);
    // root = insert(root, 20);
    // root = insert(root, 30);
    // root = insert(root, 40);
    // root = insert(root, 50);
    // root = insert(root, 25);
    cout << "Level order Traverse : " << endl;
    levelorderTraversal(root);

    deletion(root,30);

    cout<<endl<<"Level order traverse : "<< endl;
    levelorderTraversal(root);
    return 0;
}