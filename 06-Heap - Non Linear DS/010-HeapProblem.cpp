#include <bits/stdc++.h>
using namespace std;

// Min sum formed by digits
long long int minSum(int arr[], int n)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr + n);
    long long int sum1 = 0, sum2 = 0;

    while (!pq.empty())
    {
        sum1 = sum1 * 10 + pq.top();
        pq.pop();

        if (pq.empty())
            break;

        sum2 = sum2 * 10 + pq.top();
        pq.pop();
    }
    return sum1 + sum2;
}

// Gadgets of Doralands
vector<int> TopK(vector<int> &arr, int k)
{
    unordered_map<int, int> freq;
    for (auto i : arr)
        freq[i]++;

    priority_queue<pair<int, int>> pq;
    for (auto i : freq)
        pq.push({i.second, i.first});

    vector<int> ans;
    while (k-- && !pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        ans.push_back(top.second);
    }
    return ans;
}

// Nearly Sorted
vector<int> nearlySorted(int arr[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    vector<int> ans;
    int i = 0;
    while (i < n)
    {
        if (pq.size() > k)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        pq.push(arr[i]);
        i++;
    }

    while (!pq.empty())
    {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// Maximum distinct element after removing K elements
int maxDistinct(vector<int> arr, int k)
{
    unordered_map<int, int> freq;
    for (auto i : arr)
        freq[i]++;

    priority_queue<pair<int, int>> pq;
    for (auto i : freq)
        pq.push({i.second, i.first});

    while (k--)
    {
        auto top = pq.top();
        pq.pop();
        if (top.first - 1 > 0)
            pq.push({top.first - 1, top.second});
    }

    return pq.size();
}

// Game with String
int minValue(string s, int k)
{
    map<char, int> freq;
    for (auto i : s)
        freq[i]++;

    priority_queue<int> pq;
    for (auto i : freq)
        pq.push(i.second);

    while (k--)
    {
        auto top = pq.top();
        pq.pop();

        pq.push(top - 1);
    }
    int sum = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        sum += top * top;
    }

    return sum;
}

// Attend all meetings II
int minMeetingRooms(vector<int> &start, vector<int> &end)
{
    // store the pair in sorted order
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    // store end time of meeting
    priority_queue<int, vector<int>, greater<int>> map;
    // couunt the required meeting room
    int room = 1;

    for (int i = 0; i < start.size(); i++)
        pq.push({start[i], end[i]});

    map.push(pq.top().second);
    pq.pop();

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        if (top.first >= map.top())
            map.pop();
        else
            room++;

        map.push(top.second);
    }
    return max(room, (int)map.size());
}

int main()
{
    // 10 22 11 4 11
    // 14 29 30 12 29
    vector<int> start = {10, 22, 11, 4, 11};
    vector<int> end = {14, 29, 30, 12, 29};

    cout << "Minimun rooms required: " << minMeetingRooms(start, end) << endl;

    return 0;
}