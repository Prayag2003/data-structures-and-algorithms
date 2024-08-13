#include <bits/stdc++.h>
using namespace std;

int main()
{
    string query = "What is the capital of India?";
    istringstream ss(query);
    string val;
    while (ss >> val)
    {
        cout << val + '|';
    }
}