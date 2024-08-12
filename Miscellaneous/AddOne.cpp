#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        int n = digits.size() - 1;
        vector<int> ans;

        for (int i = n; i >= 0; --i)
        {
            int sum = carry + digits[i];
            carry = sum / 10;
            ans.push_back(sum % 10);
        }

        if (carry)
            ans.push_back(1);

        reverse(ans.begin(), ans.end());
        return ans;
    }
};