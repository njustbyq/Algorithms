/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
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
 * 树是递归调用的数据结构。三种情况:
 * 1.两棵树都为空则为True
 * 2.两棵树一颗为空一颗不为空则返回False
 * 最后一种则递归调用函数判断树的每一个结点是否结构相同值相同
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if(!p || !q)
            return false;
        if(p->val != q->val)
            return false;
        
        return isSameTree(p->left, q->left)
               && isSameTree(p->right, q->right);
    }
};
// @lc code=end

