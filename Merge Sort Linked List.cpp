#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define deb(x) cout << #x << " " << x->data << endl;
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
    void midNode(Node *head, Node **head1, Node **head2)
    {
        Node *slow = head, *fast = head->next;
        while (fast != nullptr)
        {
            fast = fast->next;
            if (fast != nullptr)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }

        *head1 = head;
        *head2 = slow->next;
        slow->next = nullptr;
    }

    Node *Merge(Node *head1, Node *head2)
    {
        if (head1 == nullptr)
            return head2;
        if (head2 == nullptr)
            return head1;

        Node *start, *end;
        if (head1->data <= head2->data)
        {
            start = head1;
            head1 = head1->next;
        }
        else
        {
            start = head2;
            head2 = head2->next;
        }
        end = start;

        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data <= head2->data)
            {
                end->next = head1;
                head1 = head1->next;
            }
            else
            {
                end->next = head2;
                head2 = head2->next;
            }
            end = end->next;
        }

        if (head1 != nullptr)
            end->next = head1;
        else if (head2 != nullptr)
            end->next = head2;

        return start;
    }

public:
    Node *mergeSort(Node *head)
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        Node *head1, *head2;
        midNode(head, &head1, &head2);
        head1 = mergeSort(head1);
        head2 = mergeSort(head2);
        return Merge(head1, head2);
    }
};

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node **head_ref, int new_data)
{
    Node *new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    long test;
    cin >> test;
    while (test--)
    {
        struct Node *a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}