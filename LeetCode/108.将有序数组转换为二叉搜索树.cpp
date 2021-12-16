/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
 * Solution: Recursion / Diveide and Conquer
 * BST: 
 * vals(root.left) <= root.val <= vals(root.right)
 * Height balanced:
 * Node(root.left) - Node(root.right) <= 1
 * def build(arr, l, r)
 *     if l > r: return None
 *     m = l + (r - l) / 2
 *     root = TreeNode(arr[m])
 *     root.left = build(arr, l, m - 1)
 *     root.right = build(arr, m + 1, r)
 *     return root
 * 
 * T(n) = 2 * T(n /2) + O(1)
 * Time Complexity: O(n) / Space Complexity: O(logn)
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }
private:
    TreeNode* buildBST(const vector<int>& nums, int l, int r) {
        if(l > r) return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* root = new TreeNode(nums[m]);
        root->left = buildBST(nums, l, m - 1);
        root->right = buildBST(nums, m + 1, r);
        return root;
    }
};
// @lc code=end

