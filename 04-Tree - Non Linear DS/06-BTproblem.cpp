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

// Minimum tree to Burn the entire BT
node *createparentmapping(node *root, int target, map<node *, node *> &nodetoparent)
{
    node *res = NULL;
    queue<node *> q;
    q.push(root);
    nodetoparent[root] = NULL;

    while (!q.empty())
    {
        node *front = q.front();
        q.pop();

        if (root->data == target)
            res = front;

        if (root->left)
        {
            nodetoparent[front->left] = front;
            q.push(front->left);
        }
        if (root->right)
        {
            nodetoparent[front->right] = front;
            q.push(front->right);
        }
    }
    return res;
}

int burntree(node *root, map<node *, node *> &nodetoparent)
{
    map<node *, bool> visited;
    queue<node *> q;
    q.push(root);
    visited[root] = true;
    int time = 0;
    
    while (!q.empty())
    {
        int size = q.size();
        bool flag = 0;
        for (int i = 0; i < size; i++)
        {
            node *front = q.front();
            q.pop();

            if (front->left && !visited[front->left])
            {
                flag = 1;
                q.push(front->left);
                visited[front->left] = true;
            }
            if (front->right && !visited[front->right])
            {
                flag = 1;
                q.push(front->right);
                visited[front->right] = true;
            }

            if (nodetoparent[front] && !visited[nodetoparent[front]])
            {
                flag = 1;
                q.push(nodetoparent[front]);
                visited[nodetoparent[front]] = true;
            }
        }
        if (flag)
            time++;
    }
    return time;
}

int mintree(node *root, int target)
{
    // algo :
    //  step 1 : create nodetoparnet mapping
    //  step 2 : find target node
    //  step 3 : burn the tree in min time

    map<node *, node *> nodetoparent;
    node *targetnode = createparentmapping(root, target, nodetoparent);
    int ans = burntree(targetnode, nodetoparent);
    return ans;
}

//

int main()
{
    //  Input :- 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 -1 6 -1 9-1 10 -1 -1
    node *root = NULL;
    root = buildTree(root);
    int target = 8;
    int result = mintree(root,target);
    // cout << mintree(root, 8);
    return 0;
}