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

//  2-Sum (Try to using two pointer approach to achieve target)
void inordertraverse(node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inordertraverse(root->left, in);
    in.push_back(root->data);
    inordertraverse(root->right, in);
}

bool TwoSum(node *root, int target)
{
    vector<int> inorder;
    inordertraverse(root, inorder);

    int i = 0, j = inorder.size() - 1;
    while (i < j)
    {
        int sum = inorder[i] + inorder[j];
        if (sum == target)
            return true;
        else if (sum < target)
            j--;
        else
        {
            i++;
        }
    }
    return false;
}

// Binary Search Tree ---> Flattered Linked List  (approach #1)
node *BSTintoLinkedList(node *root)
{
    vector<int> inorder;
    inordertraverse(root, inorder);

    node *head = new node(inorder[0]);
    node *curr = head;

    for (int i = 1; i < inorder.size(); i++)
    {
        node *temp = new node(inorder[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = curr->right = NULL;
    return head;
}

// Binary Search Tree  ---> Flattered Linked List (approach #2)
void binaryTraverse(node* root, node* &tail)
{
    if (!root) return;

    if (root->left != NULL)
        binaryTraverse(root->left, tail);
    tail->right = root;
    tail = root;
    root->left = NULL;
    if (root->right != NULL)
        binaryTraverse(root->right, tail);
}
node *flattenBST(node *root)
{
    node *head = new node(-1);
    node *tail = head;
    binaryTraverse(root, tail);
    root = head->right;
    head->right = NULL;
    return root;
}

// Normal BST ---> Balanced BST
node *BSTusingInorder(vector<int> &inorder, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = (s + e) / 2;
    node *root = new node(inorder[mid]);

    root->left = BSTusingInorder(inorder, s, mid - 1);
    root->right = BSTusingInorder(inorder, mid + 1, e);

    return root;
}

node *NormalBSTintoBalancedBST(node *root)
{
    vector<int> inorder;
    inordertraverse(root, inorder);
    return BSTusingInorder(inorder, 0, inorder.size()-1);
}

// Preorder traverse ---> BST
node *preordertraverse(vector<int> &preorder, int s, int e)
{
    if (s > e)
        return NULL;

    node *root = new node(preorder[s++]);
    int i = s;
    while (i < e && preorder[i] < root->data)
        i++;

    root->left = preordertraverse(preorder, s, i - 1);
    root->right = preordertraverse(preorder, i, e);

    return root;
}

int main()
{
    vector<int> preorder = {20, 10, 5, 15, 13, 35, 30, 42};
    node *root = preordertraverse(preorder, 0, preorder.size() - 1);
    levelorderTraversal(root);
    return 0;
}