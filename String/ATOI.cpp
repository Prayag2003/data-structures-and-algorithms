#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int myAtoi(string s)
    {
        int i = 0;
        long ans = 0;
        int sign = 1;
        int n = s.length();

        // NOTE: Remove the whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // NOTE: Check the sign for the answer
        if ((i < n) && (s[i] == '-' || s[i] == '+'))
        {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // NOTE: Calculate the answer using the formula ab = 10 * a + b;
        while (i < n && isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');
            if (ans * sign <= INT_MIN)
                return INT_MIN;
            if (ans * sign >= INT_MAX)
                return INT_MAX;
            i++;
        }

        return ans * sign;
    }
};