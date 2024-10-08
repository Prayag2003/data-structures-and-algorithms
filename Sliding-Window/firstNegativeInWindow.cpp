#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(
    long long int arr[],
    long long int n,
    long long int k);

int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

vector<long long> printFirstNegativeInteger(
    long long int A[],
    long long int N,
    long long int K)
{

    deque<long long> queue;
    vector<long long> ans;

    int i = 0, j = 0;
    while (j < N)
    {

        if (A[j] < 0)
        {
            queue.push_back(A[j]);
        }

        if (j - i + 1 < K)
        {
            j++;
        }

        else if (j - i + 1 == K)
        {
            if (!queue.empty())
            {
                ans.push_back(queue.front());
            }
            else
                ans.push_back(0);

            if (!queue.empty() && A[i] == queue.front())
            {
                queue.pop_front();
            }

            i++;
            j++;
        }
    }

    return ans;
}