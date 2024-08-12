#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

class Solution
{

private:
    int getSizeLL(ListNode *head)
    {
        int cnt = 0;
        ListNode *temp = head;
        while (temp)
        {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
        {
            return head;
        }

        int len = 1;
        ListNode *tail = head;
        while (tail->next)
        {
            tail = tail->next;
            len++;
        }
        tail->next = head;

        k = k % len;
        int stepsToNewHead = len - k;
        ListNode *newTail = head;

        while (--stepsToNewHead)
        {
            newTail = newTail->next;
        }

        ListNode *newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }

    // NOTE: Alt
    //     if (!head || !head->next || k == 0)
    //     {
    //         return head;
    //     }

    //     int len = getSizeLL(head);
    //     k = k % len;

    //     ListNode *temp = head;
    //     int forwardPtr = len - k;

    //     while (forwardPtr--)
    //     {
    //         temp = temp->next;
    //     }

    //     ListNode *newHead = temp;
    //     while (newHead->next)
    //     {
    //         newHead = newHead->next;
    //     }

    //     newHead->next = head;
    //     temp->next = NULL;
    //     return temp;
};

void printList(ListNode *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution obj;
    int k = 2;

    head = obj.rotateRight(head, k);
    printList(head);
    return 0;
}