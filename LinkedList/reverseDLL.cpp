#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

Node *reverseDLL(Node *head)
{
    Node *prev = NULL, *curr = head;

    while (curr)
    {
        Node *front = curr->next;
        curr->next = prev;
        curr->prev = front;

        prev = curr;
        curr = front;
    }

    return prev;
}