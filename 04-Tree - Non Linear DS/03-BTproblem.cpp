#include<bits/stdc++.h>
using namespace std;

class node{
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

// Zig-Zag Traversal
vector<int> ZigZagTraversal(node* root)
{
    vector<int> result;
    if(root == NULL)
        return  result;
    
    queue<node*> q;
    q.push(root);

    bool lefttoright=true;

    while(!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for(int i=0;i<size;i++)
        {
            node* frontnode = q.front();
            q.pop();

            int index =lefttoright ? i : size -i-1;
            ans[index]=frontnode->data;

            if(frontnode->left)
                q.push(frontnode->left);
            if(frontnode->right)
                q.push(frontnode->right);    
        }

        lefttoright = !lefttoright;
        for(auto i:ans)
            result.push_back(i);
    }
    return result;
}

// Boundary Traversal
void traverseleft(node* root,vector<int> &ans)
{
    if((root==NULL) || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if(root->left)
        traverseleft(root->left,ans);
    else
        traverseleft(root->right,ans);
}

void traverseleaf(node* root,vector<int> &ans)
{
    if(root==NULL) 
        return;
    if(root->left ==NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
}

void traverseright(node* root,vector<int> &ans)
{
    if((root==NULL) || (root->left ==NULL && root->right==NULL))
        return;

    if(root->right)
        traverseright(root->right,ans);
    else
        traverseright(root->left,ans);
    ans.push_back(root->data);
}

vector<int> Boundary(node* root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    ans.push_back(root->data);
    traverseleft(root->left,ans);
    traverseleaf(root->left,ans);
    traverseleaf(root->right,ans);
    traverseright(root->right,ans);

    return ans;  
}

// Vertical Order traversal
// Time Complexity: O(nlogn)
vector<int> verticalorder(node* root)
{
    map<int, map<int , vector<int>>> nodes;
    queue<pair<node*, pair<int, int>>> q;
    vector<int> ans;

    if(root == NULL) return ans;

    q.push(make_pair(root,make_pair(0,0)));
    while(!q.empty())
    {
        pair<node* ,pair<int,int>> temp =q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd = temp.second.first;
        int level =temp.second.second;

        nodes[hd][level].push_back(frontnode->data);

        if(frontnode->left)
            q.push(make_pair(frontnode->left,make_pair(hd-1,level+1)));
        if(frontnode->right)
            q.push(make_pair(frontnode->right,make_pair(hd+1,level+1)));
    }

    for(auto i : nodes)
        for(auto j : i.second)
            for(auto k :j.second)
                ans.push_back(k);

    return ans;
}

// Top View Binary Tree
vector<int> topview(node* root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    map<int,int> topnode;
    queue<pair<node*, int>> q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node* ,int> temp =q.front();
        q.pop();
        node* frontnode = temp.first;
        int hd =temp.second;

        if(topnode.find(hd) == topnode.end())
            topnode[hd]=frontnode->data;

        if(frontnode->left)
            q.push(make_pair(frontnode->left,hd-1));
        
        if(frontnode->right)
            q.push(make_pair(frontnode->right,hd+1));
    } 
    for(auto i : topnode)
        ans.push_back(i.second);
    
    return ans;  
}

// Bottom view binary tree
vector<int> bottomview(node* root)
{
     vector<int> ans;
    if(root == NULL) return ans;

    map<int,int> bottomnode;
    queue<pair<node*, int>> q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node* ,int> temp =q.front();
        node* frontnode = temp.first;
        int hd =temp.second;

        bottomnode[hd]=frontnode->data;

        if(frontnode->left)
            q.push(make_pair(frontnode->left,hd-1));
        
        if(frontnode->right)
            q.push(make_pair(frontnode->right,hd+1));
    } 
    for(auto i : bottomnode)
        ans.push_back(i.second);
    
    return ans;  
}

// Left view binary tree
void solveleft(node* root,vector<int> &ans,int level)
{
    if(root == NULL) return;
    if(level == ans.size())
        ans.push_back(root->data);

    solveleft(root->left,ans,level+1);
    solveleft(root->right,ans,level+1);
}

vector<int> leftview(node* root)
{
    vector<int> ans;
    solveleft(root,ans,0);
    return ans;
}

// Right view binary tree
void solveright(node* root,vector<int> &ans,int level)
{
    if(root == NULL) return;
    if(level == ans.size())
        ans.push_back(root->data);
    
    solveright(root->right,ans,level+1);
    solveright(root->left,ans,level+1);
}

vector<int> rightview(node* root)
{
    vector<int> ans;
    solveright(root,ans,0);
    return ans;
}

int main()
{
    node* root = NULL;
    root = buildTree(root);
    // vector<int> result = ZigZagTraversal(root);
    // vector<int> result = Boundary(root);
    vector<int> result = verticalorder(root);
    for(auto i : result)
        cout<<i<<" ";
    return 0;
} 

//Homework :- Diagonal traversal 