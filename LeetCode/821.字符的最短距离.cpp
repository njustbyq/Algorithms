/*
 * @lc app=leetcode.cn id=821 lang=cpp
 *
 * [821] 字符的最短距离
 */

// @lc code=start

/*
 * 最短距离：分别从头和尾两边考虑，两个循环取最小值即可。(在碰到第一个相等元素前先赋最大值)
 */
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> ans;
        int len = s.size();

        int count = s.length();
        for (auto S : s) {
            if (S == c) count = 0;
            else count++;
            ans.push_back(count);
        }

        for (int i = len - 1; i >= 0; i--) {
            if (s[i] == c) count = 0;
            else count++;
            ans[i] = min(ans[i], count);
        }
        return ans;
    }
};
// @lc code=end

