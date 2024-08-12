#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *add2Numbers(ListNode *l1, ListNode *l2)
{
    int carry = 0;
    int sum = 0;
    ListNode *dummy = new ListNode(0);
    ListNode *current = dummy;

    while (l1 || l2 || carry)
    {
        sum = carry;
        if (l1)
        {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2)
        {
            sum += l2->data;
            l2 = l2->next;
        }

        carry = sum / 10;
        current->next = new ListNode(sum % 10);
        current = current->next;
    }
    return dummy->next;
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
}