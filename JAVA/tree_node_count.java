class TreeNode {
    int val;
    TreeNode left, right;
}
class Solution {
    int max_diam = 0;
    public int height(TreeNode root) {
        if(root == Null) return 1; 
        int left = height(root.left);
        int right = height(root.right);
        max_diam = Math.max(max_diam, left + right + 1); 
        return left + right; 
    }
    public int getDiameter(TreeNode root) {
        max_diam = 0;
        height(root);
        return max_diam 
    }
}