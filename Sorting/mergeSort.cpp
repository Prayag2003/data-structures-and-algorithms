#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;

    // index for the temporary array
    int k = 0;

    vector<int> b(right - left + 1);

    while (i <= mid && j <= right)
    {
        if (arr[i] > arr[j])
        {
            b[k++] = arr[j++];
        }
        else
        {
            b[k++] = arr[i++];
        }
    }

    // NOTE: Right array got exhausted
    while (i <= mid)
    {
        b[k++] = arr[i++];
    }

    // NOTE: Left array got exhausted
    while (j <= right)
    {
        b[k++] = arr[j++];
    }

    // NOTE: Copy the b array into A
    for (int i = left; i <= right; ++i)
    {
        // Index `i - left` to access the correct element in `b`
        arr[i] = b[i - left];
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    // atleast 2 elements are present
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main()
{
    vector<int> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int left = 0, right = arr.size() - 1;
    mergeSort(arr, left, right);

    for (auto i : arr)
        cout << i << " ";
}