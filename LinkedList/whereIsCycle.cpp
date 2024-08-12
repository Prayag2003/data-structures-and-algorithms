#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *findLoopsLocation(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    ListNode *start = head;
    while (start != slow)
    {
        start = start->next;
        slow = slow->next;
    }
    return start;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    head->next = second;

    ListNode *third = new ListNode(3);
    second->next = third;

    ListNode *fourth = new ListNode(4);
    third->next = fourth;

    fourth->next = second; // loop

    cout << findLoopsLocation(head)->data;
}