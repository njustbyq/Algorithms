/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
 * 当叶子结点时, 判断值是否为targetSum
 * 当普通结点时, 进行递归判断减去当前结点时左右子树是否存在targetSum
 */

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return false; 
        if(root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        int new_sum = targetSum - root->val;
        return hasPathSum(root->left, new_sum) || hasPathSum(root->right, new_sum);
    }
};
// @lc code=end

