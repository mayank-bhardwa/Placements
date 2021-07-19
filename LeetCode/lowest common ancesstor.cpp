#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    stack<TreeNode *> s;
    s.push(root);
    TreeNode *mn = new TreeNode(INT32_MAX), *temp;
    int v = 0;
    while (!s.empty())
    {
        temp = s.top();
        s.pop();
        if (temp->left != nullptr)
            s.push(temp->left);
        if (temp->right != nullptr)
            s.push(temp->right);

        if ((temp == p || temp == q) && v == 0)
            ++v;
        else if ((temp == p || temp == q) && v == 1)
            return mn;

        if (temp->val < mn->val)
        {
            free(mn);
            mn = temp;
        }
    }

    return mn;
}

TreeNode *insert(TreeNode *root, int val)
{
    if (root == nullptr)
        return new TreeNode(val);

    if (root->val > val)
        root->left = insert(root->left, val);
    else if (root->val < val)
        root->right = insert(root->right, val);
    return root;
}

TreeNode *find(TreeNode *root, int val)
{
    if (root->val == val)
        return root;
    else if (root->val > val)
        return find(root->left, val);
    else
        return find(root->right, val);
}

int main()
{
    TreeNode *root = nullptr;
    int val[] = {6, 2, 8, 0, 4, 7, 9, 3, 5};
    for (int i : val)
        root = insert(root, i);
    TreeNode *p = find(root, 2); //2
    TreeNode *q = find(root, 8); //8
    TreeNode *result = lowestCommonAncestor(root, p, q);
    cout << result->val;
    return 0;
}