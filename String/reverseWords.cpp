#include <bits/stdc++.h>
using namespace std;

string reverseWords(string s)
{
    // NOTE: Trimming the start and the end
    int start = 0, end = s.size() - 1;
    while (start <= end && s[start] == ' ')
        start++;
    while (end >= start && s[end] == ' ')
        end--;

    // NOTE: Split the words
    vector<string> words;
    string word;
    for (int i = start; i <= end; ++i)
    {
        if (s[i] == ' ' && !word.empty())
        {
            words.push_back(word);
            word.clear();
        }
        else if (s[i] != ' ')
        {
            word += s[i];
        }
    }

    if (!word.empty())
    {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    string ans;
    for (int i = 0; i < words.size(); ++i)
    {
        ans += words[i];
        if (i != words.size() - 1)
            ans += ' ';
    }
    return ans;
}

string reverseWordsSTL(string s)
{
    istringstream ss(s);
    vector<string> words;
    string word;

    // NOTE: >> extraction operator
    // << insertion operator
    while (ss >> word)
    {
        words.push_back(word);
    }

    reverse(words.begin(), words.end());

    // ostringstream oss;
    string op;
    for (int i = 0; i < words.size(); ++i)
    {
        if (i > 0)
            op += " ";
        op += words[i];

        // if (i > 0)
        // oss << " ";
        // oss << words[i];
    }

    return op;
    // return oss.str();
}

string reverseWordOptimal(string s)
{
    string token;
    string ans;
    istringstream ss(s);

    while (ss >> token)
    {
        ans = ' ' + token + ans;
    }

    return ans.erase(0, 1);
}

int main()
{
    string s = "the sky is blue";
    cout << reverseWords(s) << "\n";
    cout << reverseWordsSTL(s) << "\n";
    cout << reverseWordOptimal(s) << "\n";
    return 0;
}