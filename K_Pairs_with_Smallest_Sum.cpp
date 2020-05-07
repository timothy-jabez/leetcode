// https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
// You are given two integer arrays nums1 and nums2 sorted in ascending order and an integer k.
// Define a pair (u,v) which consists of one element from the first array and one element from the second array.
// Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.

#include <bits/stdc++.h>
using namespace std;

vector<int> v1, v2;
class CompareClass
{
public:
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return v1[a.first] + v2[a.second] > v1[b.first] + v2[b.second];
    }
};
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    int n1 = nums1.size(), n2 = nums2.size();
    pair<int, int> top;
    vector<vector<int>> res;
    vector<int> single_pair;
    if (!n1 || !n2)
        return res;
    // Store the indices of nums1 and nums2 in pq in such a way that the sum of the elements
    // in the respective indices are in increasing order from top to bottom
    priority_queue<pair<int, int>, vector<pair<int, int>>, CompareClass> pq;
    for (int j = 0; j < n2; j++)
        pq.push(make_pair(0, j));
    for (int i = 0; i < min(k, n1 * n2); i++)
    {
        top = pq.top();
        pq.pop();
        single_pair.push_back(nums1[top.first]);
        single_pair.push_back(nums2[top.second]);
        res.push_back(single_pair);
        single_pair.clear();
        if (top.first + 1 == n1)
            continue;
        pq.push(make_pair(top.first + 1, top.second));
    }
    return res;
}

int main()
{
    v1.push_back(1);
    v1.push_back(1);
    v1.push_back(2);

    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    vector<vector<int>> res = kSmallestPairs(v1, v2, 10);

    cout << "printing the pairs:\n";
    for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[0].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
}

