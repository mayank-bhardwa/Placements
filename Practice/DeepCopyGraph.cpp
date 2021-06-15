#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

Node *buildGraph()
{
    Node *node1 = new Node();
    node1->val = 1;
    Node *node2 = new Node();
    node2->val = 2;
    Node *node3 = new Node();
    node3->val = 3;
    Node *node4 = new Node();
    node4->val = 4;
    vector<Node *> v;
    v.push_back(node2);
    v.push_back(node4);
    node1->neighbors = v;
    v.clear();
    v.push_back(node1);
    v.push_back(node3);
    node2->neighbors = v;
    v.clear();
    v.push_back(node2);
    v.push_back(node4);
    node3->neighbors = v;
    v.clear();
    v.push_back(node3);
    v.push_back(node1);
    node4->neighbors = v;
    return node1;
}

unordered_set<Node *> visited;
void print(Node *root)
{
    visited.emplace(root);
    cout << root->val << " ";
    for (auto i : root->neighbors)
    {
        if (visited.find(i) == visited.end())
        {
            print(i);
        }
    }
}

unordered_map<int, Node *> m;
Node *clone(Node *root)
{
    if (root == NULL)
        return nullptr;
    Node *temp = new Node(root->val);
    m[root->val] = temp;

    for (auto i : root->neighbors)
    {
        if (m.find(i->val) == m.end())
        {
            Node *u = clone(i);
            temp->neighbors.emplace_back(u);
        }
        else
        {
            temp->neighbors.emplace_back(m[i->val]);
        }
    }
    return temp;
}

int main(int argc, char const *argv[])
{
    Node *root = buildGraph();
    print(root);
    cout << "\n";

    Node *deep_copy = clone(root);
    print(deep_copy);

    return 0;
}