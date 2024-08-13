#include <bits/stdc++.h>
using namespace std;

bool isomorphic(string s, string t)
{
    if (s.size() != t.size())
        return false;

    unordered_map<char, char> sToT, tToS;

    for (int i = 0; i < s.size(); ++i)
    {
        char c1 = s[i];
        char c2 = t[i];

        if (sToT.count(c1) && sToT[c1] != c2)
            return false;

        if (tToS.count(c2) && tToS[c2] != c1)
            return false;

        sToT[c1] = c2;
        tToS[c2] = c1;
    }

    return true;
}

bool isomorphicOptimal(string s, string t)
{
    vector<int> first(256, 0), second(256, 0);

    for (int i = 0; i < s.size(); ++i)
    {
        if (first[s[i]] != second[t[i]])
            return false;

        first[s[i]] = i + 1;
        second[t[i]] = i + 1;
    }
    return true;
}

int main()
{
}