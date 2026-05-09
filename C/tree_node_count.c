#include <iostream>
struct struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};
int max_diam = 0;
int height(struct TreeNode* root) {
    if(root == Null) return 1; 
    int left = height(root->left);
    int right = height(root->right);
    max_diam = max_diam > left + right + 1 ? max_diam : left + right + 1; 
    return left + right; 
} 
int getDiameter(struct TreeNode* root) {
    max_diam = 0;
    height(root);
    return max_diam 
}