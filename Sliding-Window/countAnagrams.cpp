//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution
{
public:
    int search(string pat, string txt)
    {

        // create map for pattern
        map<char, int> mp;
        for (auto i : pat)
            mp[i]++;

        // making count = 0, so there is no need to travel
        // the whole window at all the times
        int count = mp.size();

        int i = 0, j = 0;
        int N = txt.size();
        int K = pat.size();
        int ans = 0;

        while (j < N)
        {
            // check if the element is currently present in the map
            char ch = txt[j];

            if (mp.count(ch))
            {
                mp[ch]--;
                if (mp[ch] == 0)
                    count--;
            }

            // if the window size is smaller
            if (j - i + 1 < K)
                j++;

            // if the window size is hit
            else if (j - i + 1 == K)
            {

                if (count == 0)
                    ans++;

                // increment the count
                char c = txt[i];
                if (mp.find(c) != mp.end())
                {
                    mp[c]++;
                    if (mp[c] == 1)
                        count++;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends