// Given a non-empty array of integers, every element appears three times except for one,
// which appears exactly once. Find that single one.

#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int count, x = 0;
    for (int i = 0; i < 32; i++) // int has 32 bits
    {
        count = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if ((nums[j] & (1 << i)) != 0)
            {
                count++; // count the number of set bits in all the numbers
            }
        }
        if (count % 3 != 0) // if the number of set bits are indivisible by 3, then the number will have this bit set and vice versa
            x += (1 << i);
    }
    return x;
}

int main()
{
    vector<int> num;
    num.push_back(1);
    num.push_back(1);
    num.push_back(1);
    num.push_back(4);
    cout << singleNumber(num);
}

