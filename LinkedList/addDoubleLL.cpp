#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

void addNode(Node *head, int pos, int data)
{
    Node *temp = head;
    for (int i = 1; i <= pos; ++i)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}