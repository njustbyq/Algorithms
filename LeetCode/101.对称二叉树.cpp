/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
 * Recursion:
 * 送两棵树进入isMirror判断函数，讨论如下情况:
 * 左右子树为空，则返回true;
 * 若左右子树不为空则判断值是否相同。然后递归判断左边的左边等于右边的右边，
 * 左边的右边等于右边的左边即可
 */

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        if(left == NULL && right == NULL) {
            return true;
        }else if(left != NULL && right != NULL && left->val == right->val) {
            return isMirror(left->left, right->right) && isMirror(left->right, right->left);
        }
        return false;
    }
};
// @lc code=end

