/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
/**
 * Solution:
 * 1.借助一个辅助队列
 * 2.先将二叉树的根节点入队
 * 3.队列不为空，开始循环，队头节点出队
 * 4.访问出队结点，若有左子树，则左子树根节点入队；
 *   若有右子树，则右子树根节点入队
 * 5.循环重复3，4直至队列为空
*/
class Solution {
public:
    void levelOrder(TreeNode* root, std::vector<vector<int>> &v) {
        if(!root) {
            return;
        }
        queue<TreeNode*> Q;
        Q.push(root);
        while(!Q.empty()) {
            std::vector<int> res;
            int len = Q.size();
            for (int i = 0; i < len; i++) {
                root = Q.front();
                Q.pop();
                res.push_back(root->val);
                if(root->left) {
                    Q.push(root->left);
                } 
                if(root->right) {
                    Q.push(root->right);
                }
            }
            v.push_back(res);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        std::vector<vector<int>> v;
        levelOrder(root, v);
        return v;
    }
};
// @lc code=end

