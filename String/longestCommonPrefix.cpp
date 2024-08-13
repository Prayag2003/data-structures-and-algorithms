#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        sort(strs.begin(), strs.end());
        int n = strs.size() - 1;
        string common = "";
        string first = strs[0];
        string last = strs[n];

        int minLen = min(first.size(), last.size());
        for (int i = 0; i < minLen; ++i)
        {
            if (first[i] == last[i])
            {
                common += first[i];
            }
            else
                break;
        }
        return common;
    }
};

int main()
{
}