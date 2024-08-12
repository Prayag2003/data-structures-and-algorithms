#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

bool detectLoop(LinkedList *head)
{
    if (!head)
        return false;

    LinkedList *slow = head, *fast = head;
    while (fast && fast->next)
    {
        if (slow == fast)
            return 1;
        slow = slow->next;
        fast = fast->next->next;
    }
    return 0;
}

int main()
{
    LinkedList *head = new LinkedList(1);
    LinkedList *second = new LinkedList(2);
    head->next = second;

    LinkedList *third = new LinkedList(3);
    second->next = third;

    LinkedList *fourth = new LinkedList(4);
    third->next = fourth;

    fourth->next = second; // loop

    cout << detectLoop(head);
}