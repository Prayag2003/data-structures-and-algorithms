#include <bits/stdc++.h>
using namespace std;

int findAllSubArrays(vector<int> arr, int k)
{
    unordered_map<int, int> mp;
    int ans = 0;

    int n = arr.size();
    int pref[n];

    pref[0] = arr[0];

    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + arr[i];

    for (int i = 0; i < n; ++i)
    {
        if (pref[i] == k)
            ans++;

        if (mp.find(pref[i] - k) != mp.end())
        {
            ans += mp[pref[i] - k];
        }

        mp[pref[i]]++;
    }
    return ans;
}

int findMaxSubArray(vector<int> arr, int k)
{
    unordered_map<int, int> prefixMap;
    int maxLength = 0;
    int currentSum = 0;

    for (int i = 0; i < arr.size(); ++i)
    {
        currentSum += arr[i];

        if (currentSum == k)
            maxLength = i + 1;

        if (prefixMap.find(currentSum - k) != prefixMap.end())
        {
            maxLength = max(maxLength, i - prefixMap[currentSum - k]);
        }

        if (prefixMap.find(currentSum) == prefixMap.end())
        {
            prefixMap[currentSum] = i;
        }
    }

    return maxLength;
}

int main()
{
    vector<int> arr = {1, 2, 3, 1, 1, 1, 2, 1};
    int k = 3;
    cout << findAllSubArrays(arr, k) << "\n";
    cout << findMaxSubArray(arr, k);
}