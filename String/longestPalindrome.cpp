#include <iostream>
#include <string>
#include <vector>

using namespace std;

string preprocess(const string &s)
{
    string result = "#";
    for (char c : s)
    {
        result += c;
        result += "#";
    }
    return result;
}

string manacher(const string &s)
{
    string t = preprocess(s);
    int n = t.size();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 0; i < n; ++i)
    {
        if (i < right)
        {
            p[i] = min(right - i, p[2 * center - i]);
        }
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1])
        {
            ++p[i];
        }
        if (i + p[i] > right)
        {
            center = i;
            right = i + p[i];
        }
    }

    int maxLen = 0, start = 0;
    for (int i = 0; i < n; ++i)
    {
        if (p[i] > maxLen)
        {
            maxLen = p[i];
            start = i;
        }
    }

    return s.substr((start - maxLen) / 2, maxLen);
}

int main()
{
    string input;
    cin >> input;
    cout << manacher(input) << endl;
    return 0;
}
