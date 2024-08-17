#include <bits/stdc++.h>
using namespace std;

long maximumSumSubarray(int K, vector<int> &Arr, int N)
{
    int i = 0, j = 0;
    long sum = 0;
    long maxSum = INT_MIN;

    while (j < N)
    {

        sum += Arr[j];

        if (j - i + 1 < K)
        {
            j++;
        }

        else if (j - i + 1 == K)
        {
            maxSum = max(sum, maxSum);
            sum -= Arr[i];
            i++;
            j++;
        }
    }
    return maxSum;
}

// int findMaxOfSubArraySum(vector<int> v, int subSize)
// {
//     int sum = 0, ans = 0;
//     for (int j = 0; j < subSize; ++j)
//     {
//         sum += v[j];
//     }

//     for (int i = 0; i <= v.size() - subSize; ++i)
//     {
//         sum -= v[i];
//         sum += v[i + subSize - 1];
//         ans = max(ans, sum);
//     }
//     return ans;
// }

int main()
{
    vector<int> v = {6, 1, 3, 2, 5, 1, -1, 3, 2};
    int vectorSize = v.size();
    int k = 3;
    cout << "The Maximum sum amongst all subarrays of length " << vectorSize << " is : " << maximumSumSubarray(k, v, vectorSize);
}