#include <bits/stdc++.h>
using namespace std;

string largestOddNumber(string s)
{
    for (int i = s.size() - 1; i >= 0; --i)
    {
        if ((s[i] - '0') % 2 != 0)
        {
            return s.substr(0, i + 1);
        }
    }
    return "";
}

int main()
{
}