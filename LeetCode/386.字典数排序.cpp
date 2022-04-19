/*
 * @lc app=leetcode.cn id=386 lang=cpp
 *
 * [386] 字典数排序
 */

// @lc code=start

/*  下图即为本题需要遍历的树
 *  0
 *  |
 *  -----------------------------------
 *  |       |       |       | | | | | |
 *  1       2       3       4 5 6 7 8 9
 *  |       |       |       | | | | | |
 *  10~19   20~29   30~39   ............
 *  先序遍历(DFS)
 *  最多有9种开头，分别为1~9
 *  首先把1开头的传进去，添加到vector中，
 *  接着对1*10=10，把10传进去，输出10~19（假设n>19）
 *  然后把10*10=100，把100传进去，假如大于n了，自动退回
 *  接着把2~9的数字传进去
 *  返回vector   
 * 
 */
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        //开头从1开始
        for (int i = 1; i <= 9; i++) {
            dfs(n, i, res);
        }
        return res;
    }

    void dfs(int n, int t, vector<int>& res) {
        //如果t > n, 直接结束递归
        if (t > n) {
            return;
        }

        res.push_back(t);
        t *= 10;
        //1之后是11～19
        for (int i = 0; i < 10; i++) {
            //1之后传入10, 从10开始分别传入10～19
            dfs(n, t + i, res);
        }
    }
};
// @lc code=end

