#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left, *right;
};
int max_diam = 0;
int height(TreeNode* root) {
    if(root == Null) return 1; 
    int left = height(root->left);
    int right = height(root->right);
    max_diam = max(max_diam, left + right + 1); 
    return left + right; 
} 
int getDiameter(TreeNode* root) {
    max_diam = 0;
    height(root);
    return max_diam 
}