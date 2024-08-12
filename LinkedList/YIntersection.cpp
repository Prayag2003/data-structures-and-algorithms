#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL, *curr = head, *front = head;
    while (curr)
    {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
    }
    return prev;
}

ListNode *getIntersection(ListNode *l1, ListNode *l2)
{
    ListNode *first = reverseLL(l1);
    ListNode *second = reverseLL(l2);
    ListNode *meetPoint = NULL;
    ListNode *prev = NULL;

    while (first && second)
    {
        prev = first;
        if (first->data != second->data)
        {
            return prev;
        }
        first = first->next;
        second = second->next;
    }
}

int main()
{
}