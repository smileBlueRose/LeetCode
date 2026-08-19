#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* sortedArrayToBST(int* nums, int size) {
    if (size == 0) return NULL;

    struct TreeNode* tree = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    int mid = size / 2;

    tree->val = nums[mid];
    tree->left = sortedArrayToBST(nums, mid);
    tree->right = sortedArrayToBST(nums + mid + 1, size - mid - 1);
    return tree;
}
