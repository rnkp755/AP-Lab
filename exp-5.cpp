// Problem 1: Same Tree
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL)  return true;
        if(p == NULL || q == NULL)  return false;
        if(p -> val != q -> val)  return false;
        return isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};

// Problem 2: Symmetric Tree
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if(p == null && q == null)  return true;
        if(p == null || q == null)  return false;

        if(p.val != q.val)  return false;
        return (isSameTree(p.left,q.left) && isSameTree(p.right,q.right));
    }
    public TreeNode invertTree(TreeNode root) {
        if(root == null)    return root;

        TreeNode l = root.left;
        root.left = invertTree(root.right);
        root.right = invertTree(l);

        return root;
    }
    public boolean isSymmetric(TreeNode root) {
        if(root == null)    return true;
        return isSameTree(root.left,invertTree(root.right));
    }
}

// Problem 3: Balanced Binary Tree
class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL)    return 0;
        return (1 + max(height(root -> left), height(root -> right)));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL)    return true;
        if(abs(height(root -> left) - abs(height(root -> right))) > 1) return false;
        return (isBalanced(root -> left) && isBalanced(root -> right));
    }
};
