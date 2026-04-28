#include<bits/stdc++.h>
using namespace std;

class node
{
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

// Sum of nodes on the longest path
void Solve(node* root,int sum,int len,int &maxSum,int &maxlen)
{
    if(root == NULL)
    {
        if(len>maxlen)
        {
            maxlen=len;
            maxSum=sum;
        }
        else if(len == maxlen)
        {
            maxSum = max(sum,maxSum);
        }
        return;
    }
    sum =sum + root->data ;
    Solve(root->left,sum,len+1,maxSum,maxlen);
    Solve(root->right,sum,len+1,maxSum,maxlen);
}


int SumoflongRoottoLeafPath(node* root)
{
    int maxlen=0;
    int maxSum=INT_MIN;
    Solve(root,0,0,maxSum,maxlen);
    return maxSum;
}

// LCA in a Binary tree
node* LCA(node* root,int n1,int n2)
{
    if(root==NULL) return NULL;
    if(root->data == n1 || root->data == n2)
        return root;
    
    node* leftlca = LCA(root->left,n1,n2);
    node* rightlca = LCA(root->right,n1,n2);

    if(leftlca && rightlca)
        return root;
    
    return (leftlca != NULL) ? leftlca : rightlca ;
}

// K-sum Path
void ksum(node* root,int k,int &count,vector<int> path)
{
    if(root == NULL) return ;

    path.push_back(root->data);
    ksum(root->left,k,count,path);
    ksum(root->right,k,count,path);

    int sum=0;
    for(int i=path.size()-1;i>=0;i--)
    {
        sum += path[i];
        if(sum == k) count++;
    }
    path.pop_back();
}

int ksumpath(node* root,int k)
{
    vector<int> path;
    int count =0;
    ksum(root,k,count,path);
    return count;
}

// k-Ancestor in a binary tree
bool ksolze(node* root,int &count,int node,int &val)
{
    if(root == NULL) return 0;
    if(root->data == node) return 1;

    int left = ksolze(root->left,count,node,val);
    int right = ksolze(root->right,count,node,val);

    if(left || right)
    {
        count--;
        if(count == 0) val = root->data ;
        return 1;
    } 
    return 0;

}
int kthAncestor(node* root,int k,int node)
{
    int val=-1;
    ksolze(root,k,node,val);
    return val;
}


// MaxSum of Non-adjacent node in Tree



int main()
{
    node* root = NULL ;
    root = buildTree(root);
    cout<<"MaxSum : "<<SumoflongRoottoLeafPath(root);
    cout<<"KthAncestor : "<<kthAncestor(root,2,4);
    return 0;
}

