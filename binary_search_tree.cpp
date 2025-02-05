// Q-2 : Binary Search Tree

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *newNode(int val)
{
    TreeNode *node = new TreeNode;
    node->val = val;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

int findKthLargestUtil(TreeNode *root, int &k)
{
    if (root == nullptr)
    {
        return -1;
    }

    int rightResult = findKthLargestUtil(root->right, k);
    if (rightResult != -1)
    {
        return rightResult;
    }

    k--;
    if (k == 0)
    {
        return root->val;
    }

    int leftResult = findKthLargestUtil(root->left, k);
    return leftResult;
}

int findKthLargest(TreeNode *root, int k)
{
    return findKthLargestUtil(root, k);
}

int main()
{
    TreeNode *root = newNode(8);
    root->left = newNode(5);
    root->right = newNode(10);
    root->left->left = newNode(3);
    root->left->right = newNode(7);
    root->right->right = newNode(12);

    cout << "3rd largest: " << findKthLargest(root, 3) << "\n";
    cout << "1st largest: " << findKthLargest(root, 1) << "\n";
    cout << "4th largest: " << findKthLargest(root, 4) << "\n";

    return 0;
}
