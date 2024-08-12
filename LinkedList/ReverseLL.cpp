#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *reverseLL(ListNode *head)
{
    ListNode *prev = NULL, *temp = head, *front = head;

    while (temp)
    {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

void printLL(ListNode *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    head->next = second;

    ListNode *third = new ListNode(3);
    second->next = third;

    printLL(head);
    ListNode *revHead = reverseLL(head);
    printLL(revHead);
}
