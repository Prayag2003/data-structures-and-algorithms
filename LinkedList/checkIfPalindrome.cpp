#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *findMiddle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

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

bool checkIfPalindrome(ListNode *head)
{
    if (!head || !head->next)
        return true;

    ListNode *middle = findMiddle(head);
    ListNode *last = reverseLL(middle);
    ListNode *headCopy = head;
    ListNode *secondHalfCopy = last;

    while (secondHalfCopy)
    {
        if (headCopy->data != secondHalfCopy->data)
        {
            return false;
        }
        headCopy = headCopy->next;
        secondHalfCopy = secondHalfCopy->next;
    }
    reverseLL(secondHalfCopy);
    return true;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    head->next = second;

    ListNode *third = new ListNode(2);
    second->next = third;

    ListNode *fourth = new ListNode(1);
    third->next = fourth;

    fourth->next = NULL;

    // ListNode *fifth = new ListNode(3);
    // fourth->next = fifth;

    // ListNode *sixth = new ListNode(2);
    // fifth->next = sixth;

    // ListNode *seventh = new ListNode(1);
    // sixth->next = seventh;

    cout << checkIfPalindrome(head);
}