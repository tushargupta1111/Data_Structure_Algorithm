#include <bits/stdc++.h>
using namespace std;

int minimumCostPath(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

    // Min-heap priority queue where first element is the cost and second is the cell (i, j)
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    // Start from the top-left corner (0, 0)
    pq.push({grid[0][0], {0, 0}});
    dist[0][0] = grid[0][0];

    // Directions to move in the grid: right, down, left, and up
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int cost = top.first;
        int x = top.second.first;
        int y = top.second.second;

        // If we have reached the bottom-right corner, return the cost
        if (x == n - 1 && y == n - 1)
        {
            return cost;
        }

        // Explore all four possible directions
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // Check if the new position is within bounds
            if (nx >= 0 && ny >= 0 && nx < n && ny < n)
            {
                int newCost = cost + grid[nx][ny];

                // Update the distance if a shorter path is found
                if (newCost < dist[nx][ny])
                {
                    dist[nx][ny] = newCost;
                    pq.push({newCost, {nx, ny}});
                }
            }
        }
    }

    // If for some reason we never reach the bottom-right corner, return -1 (though this should never happen)
    return -1;
}

// Convert Min Heap to Max Heap
void heapify(vector<int> &arr, int i, int N)
{
    int largest = i;
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest, N);
    }
}
void convertMinToMaxHeap(vector<int> &arr, int N)
{
    for (int i = (N / 2) - 1; i >= 0; i--)
        heapify(arr, i, N);
}

// Lucy's Neighbours
vector<int> Kclosest(vector<int> arr, int n, int x, int k)
{
    priority_queue<pair<int, int>> pq;

    for (auto i : arr)
    {
        pq.push({abs(i - x), i});
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ans;

    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }

    sort(ans.begin(), ans.end());
    return ans;
}

// K Sized Subarray Maximum
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<k;i++)
            pq.push({arr[i],i});
            
        vector<int> ans;
        ans.push_back(pq.top().first);
        
        for(int i=k;i<arr.size();i++)
        {
            pq.push({arr[i],i});
            while(pq.top().second <= i-k)
                pq.pop();
            ans.push_back(pq.top().first);
        }
        return ans;
    }

// Kth Largest sum contiguous array
int kthLargest(vector<int> &arr, int k) {
        // priority_queue<int> pq;
        
        // for(int i=0;i<arr.size();i++)
        // {
        //     int sum = 0;
        //     for(int j=i;j<arr.size();j++)
        //     {
        //         sum += arr[j];
        //         pq.push(sum);
        //     }
        // }
        
        // while(--k)
        //     pq.pop();
        // return pq.top();
        
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<arr.size();i++)
        {
            int sum = 0;
            for(int j=i;j<arr.size();j++)
            {
                sum += arr[j];
                if(pq.size()<k) 
                    pq.push(sum);
                else if(sum>pq.top())
                    pq.pop(),pq.push(sum);
            }
        }
        return pq.top();
    }

int main()
{
    vector<vector<int>> grid = {{9, 4, 9, 9},
                                {6, 7, 6, 4},
                                {8, 3, 3, 7},
                                {7, 4, 9, 10}};

    cout << "Minimum Cost path : " << minimumCostPath(grid) << endl;
    return 0;
}