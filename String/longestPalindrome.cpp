#include <bits/stdc++.h>
using namespace std;

string expandAroundCenter(string s, int l, int r)
{
    while (l >= 0 && r < s.size() && s[l] == s[r])
    {
        --l;
        ++r;
    }
    return s.substr(l + 1, r - l - 1);
}

bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l <= r)
    {
        if (s[l] != s[r])
            return false;
    }
    return true;
}

string longestPalindrome(string s)
{
    if (isPalindrome(s))
        return s;
    if (s.empty())
        return "";

    string longest = "";
    for (int i = 0; i < s.size(); ++i)
    {
        string oddPalindrome = expandAroundCenter(s, i, i);
        if (oddPalindrome.size() > longest.size())
            longest = oddPalindrome;

        string evenPalindrome = expandAroundCenter(s, i, i + 1);
        if (evenPalindrome.size() > longest.size())
            longest = evenPalindrome;
    }
    return longest;
}

int main()
{
    string s;
    cin >> s;
    cout << longestPalindrome(s);
}