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

// Construct BT form Inorder && preorder
node *solve1(int in[], int pre[], int &index, int start, int end, int n, map<int, int> &nodetoindex)
{
    if (index > n || start > end)
        return NULL;

    int element = pre[index++];
    node *root = new node(element);
    int position = nodetoindex[element];

    root->left = solve1(in, pre, index, start, position - 1, n, nodetoindex);
    root->right = solve1(in, pre, index, position + 1, end, n, nodetoindex);

    return root;
}

node *buildtree1(int in[], int pre[], int n)
{
    int preindex = 0;
    map<int, int> nodetoindex;
    for (int i = 0; i < n; i++)
        nodetoindex[in[i]] = i;
    return solve1(in, pre, preindex, 0, n - 1, n, nodetoindex);
}

// Construct BT form inorder && postorder
node *solve2(int in[], int post[], int &index, int start, int end, int n, map<int, int> &nodetoindex)
{
    if (index < 0 || start > end)
        return NULL;

    int element = post[index--];
    node *root = new node(element);
    int position = nodetoindex[element];

    root->right = solve2(in, post, index, position + 1, end, n, nodetoindex);
    root->left = solve2(in, post, index, start, position - 1, n, nodetoindex);

    return root;
}
node *buildtree2(int in[], int post[], int n)
{
    int postindex = n - 1;
    map<int, int> nodetoindex;
    for (int i = 0; i < n; i++)
        nodetoindex[in[i]] = i;
    return solve2(in, post, postindex, 0, n - 1, n, nodetoindex);
}

// Construct BT form preorder && postorder
node *solve3(int pre[], int post[], int &index, int start, int end, int n, map<int, int> &nodetoindex)
{
    if (index > n || start > end)
        return NULL;

    int element = pre[index++];
    node *root = new node(element);
    if (start == end)
        return root;

    int position = nodetoindex[pre[index]];
    
    root->left = solve3(pre, post, index, start, position, n, nodetoindex);
    root->right = solve3(pre, post, index, position + 1, end - 1, n, nodetoindex);
    
    return root;
}

node *buildtree3(int pre[], int post[], int n)
{
    int preindex=0;
    map<int, int> nodetoindex;
    for (int i = 0; i < n; i++)
        nodetoindex[post[i]] = i;
    return solve3(pre, post, preindex, 0, n - 1, n, nodetoindex);
}

// Inorder Traversal (L N R)
void inorder(node *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal (N L R)
void preorder(node *root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal (L R N)
void postorder(node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    int in[] = {4, 8, 2, 5, 1, 6, 3, 7};
    int pre[] = {1, 2, 4, 8, 5, 3, 6, 7};
    int post[] = {8, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof(pre) / sizeof(pre[0]);

    // node* root = buildtree1(in,pre,size);
    //  postorder(root);

    // node *root = buildtree2(in, post, size);
    // preorder(root);

    node* root = buildtree3(pre, post, size);
    inorder(root);
    return 0;
}