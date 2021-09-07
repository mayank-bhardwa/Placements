#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#define deb(x) cout << #x << " " << x->val << endl;
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = NULL;
    }
};

class Solution
{
    struct comparator
    {
        bool operator()(ListNode *a, ListNode *b)
        {
            return a->val > b->val;
        }
    };

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, comparator> q;
        for (auto i : lists)
            if (i)
                q.push(i);

        if (q.empty())
            return nullptr;

        ListNode *start = q.top();
        ListNode *end = start;
        if (end->next != nullptr)
            q.push(end->next);
        q.pop();

        while (!q.empty())
        {
            end->next = q.top();
            end = end->next;
            if (end->next != nullptr)
                q.push(end->next);
            q.pop();
        }
        return start;
    }
};

void printList(ListNode *Listnode)
{
    while (Listnode != NULL)
    {
        printf("%d ", Listnode->val);
        Listnode = Listnode->next;
    }
    printf("\n");
}

void push(struct ListNode **head_ref, int new_val)
{
    ListNode *new_Listnode = new ListNode(new_val);
    new_Listnode->next = (*head_ref);
    (*head_ref) = new_Listnode;
}

int main()
{
    int n, m, val;
    cin >> n;
    vector<ListNode *> lists(n, nullptr);
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        while (m--)
        {
            cin >> val;
            push(&lists[i], val);
        }
    }

    Solution ob;

    printList(ob.mergeKLists(lists));

    return 0;
}