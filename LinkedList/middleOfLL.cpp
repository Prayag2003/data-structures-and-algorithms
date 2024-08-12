#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *middleOfListNode(ListNode *head)
{
    if (!head)
        return nullptr;
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
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

    cout << middleOfListNode(head)->data;
}