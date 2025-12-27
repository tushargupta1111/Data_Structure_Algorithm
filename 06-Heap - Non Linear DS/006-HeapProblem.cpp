#include<bits/stdc++.h>
using namespace std;

// kth Smallest element in Matrix (#1 Approach)

// int kthSmallest(vector<vector<int>> arr, int n, int k) {
//     vector<int> res;

//     for(auto i :arr)
//         for(auto j : i)
//             res.push_back(j);

//     sort(res.begin(),res.end());

//     return res[k-1];
// }
// Time Complexity,: O(n*m log(n*m))
// Space Complexity: O(n*m)
// _______________________________________________________
// kth Smallest element in Matrix using Priority Queue (#2 Approach)

// int kthSmallest(vector<vector<int>> arr, int n, int k) {
//     priority_queue<int,vector<int>,greater<int>> pq;

//     for(auto i :arr)
//         for(auto j : i)
//             pq.push(j);
        
//     while(k > 1 && k--)
//         pq.pop();
//     return pq.top();
// }
// Time Complexity: O(n*m log(k))
// Space Complexity: O(n*m)
// _______________________________________________________
// kth Smallest element in Matrix using Priority Queue of K size (#3 Approach)

// int kthSmallest(vector<vector<int>> arr,int n,int k) 
// {
//     priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

//     for(int i=0;i<n;i++)
//         pq.push({arr[i][0],{i,0}});

//     while(k > 1 && k--)
//     {
//         auto top = pq.top();
//         pq.pop();

//         int i = top.second.first;
//         int j = top.second.second;

//         if(j+1<n)
//             pq.push({arr[i][j+1],{i,j+1}});
//     }
//     return pq.top().first;
// }
// Time Complexity: O(k log(n))
// Space Complexity: O(n)
// _______________________________________________________
// kth Smallest element in Matrix using Priority_Queue that Moving right and bottom element (#4 Approach)

int kthSmallest(vector<vector<int>> arr,int n,int k)
{
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<bool>> vis(n,vector<bool>(n,false));

    pq.push({arr[0][0],{0,0}});
    vis[0][0] = true;

    while(--k)
    {
        auto top = pq.top();
        pq.pop();

        int i = top.second.first;
        int j = top.second.second;

        if(i+1 < n)
        {
            if(!vis[i+1][j])
            {
            pq.push({arr[i+1][j],{i+1,j}});
            vis[i+1][j]=true;
            }
        }
        if(j+1 < n)
        {
            if(!vis[i][j+1])
            {
            pq.push({arr[i][j+1],{i,j+1}});
            vis[i][j+1]=true;
            }
        }  
    }
    return pq.top().first;
}


// Time Complexity: -
// Space Complexity: - 
// _______________________________________________________
// kth Smallest element in Matrix using Binary Search (#5 Approach)

// int kthSmallest(vector<vector<int>> mat, int n, int k){
//       //Binary search 
//       int low = mat[0][0], high = mat[n-1][n-1];
      
//       if(k== n*n)
//           return high ;
      
//       while(low<high){
//           int mid = (low+ high)/2 ;
//           // number of elements less than mid
//           int smaller = 0;
//           for(int i=0; i<n; ++i)
//               smaller += lower_bound(mat[i], mat[i] + n, mid) - mat[i];
              
//               if(smaller<k)
//                   low = mid + 1;
//               else if(smaller>=k)
//                   high = mid;
//       }
//       return low - 1 ;//The use of 'low - 1' is an attempt to correct an off-by-one error 
//                      //  that was thought to occur due to the way low was being incremented.
// }



// Find Median in a stream
class Median
{
    public:
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;

    void insertHeap(int& X)
    {
        if(left.empty()  || X<=left.top())
            left.push(X);
        else
            right.push(X);

        // Balance the heaps
        balanceheaps();
    }

    void balanceheaps()
    {
        if(left.size()>right.size()+1)
        {
            right.push(left.top());
            left.pop();
        }
        else if(right.size()>left.size()+1)
        {
            left.push(right.top());
            right.pop();
        }
    }

    double getMedian()
    {
        if(left.size()>right.size())
            return left.top();
        else if(left.size()<right.size())
            return right.top(); 
        else
            return (double)(left.top()+right.top())/2;
    }
};

int main()
{
    vector<vector<int>> arr ={{16,28,60,64},
                              {22,41,63,91},
                              {27,50,87,93},
                              {36,78,87,94}};

    // cout<<"kth Smallest Element in Sorted Matrix : "<<kthSmallest(arr,4,6);
    cout<<"Median Stream : "<<endl;
    vector<int> arr1 ={5,10,15};
    Median mo;
    for(auto i : arr1)
    {
        mo.insertHeap(i);
        cout<<mo.getMedian()<<endl;
    }
    return 0;
}