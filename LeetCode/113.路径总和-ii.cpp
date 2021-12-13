/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
 * curr ———— 记录当前符合条件的数组
 * 其他同112
 */

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> curr;
        pathSum(root, targetSum, curr, ans);
        return ans;
    }
private:
    void pathSum(TreeNode* root, int sum, vector<int>& curr, vector<vector<int>>& ans) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
            if(root->val == sum) {
               curr.push_back(root->val);
               ans.push_back(curr);
               curr.pop_back();
            }
            return;
        }

        curr.push_back(root->val);
        int new_sum = sum - root->val;
        pathSum(root->left, new_sum, curr, ans);
        pathSum(root->right, new_sum, curr, ans);
        curr.pop_back();
    }
};
// @lc code=end

