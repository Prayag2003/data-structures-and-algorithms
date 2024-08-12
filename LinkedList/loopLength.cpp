#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

int findLengthOfLoop(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int len = 1;
            ListNode *curr = fast;
            while (curr->next != slow)
            {
                len++;
                curr = curr->next;
            }
            return len;
        }
    }

    return 0;
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

    cout << findLengthOfLoop(head);
}