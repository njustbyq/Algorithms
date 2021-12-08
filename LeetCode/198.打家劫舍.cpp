/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start

/*
 * Solution 1: Recursion + Memorization
 * For a given house i, we have two options:
 * 1. Take the money if we didn't robber house i - 1
 * 2. Skip it
 * 
 * rob = max(rob(n - 2) + money[i], rob(n - 1))
 * Time complexity: O(n), Space complexity: O(n)
 * 
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = nums.size();
        m_ = vector<int>(n, -1);
        return rob(nums, n - 1);
    }
private:
    int rob(const vector<int>& nums, int i) {
        if(i < 0) return 0;
        if(m_[i] >= 0) return m_[i];
        return m_[i] = max(rob(nums, i - 2) + nums[i],
                           rob(nums, i - 1));
    }

    vector<int> m_;
};
/*
* Solution 2: DP
 * dp[i]: Max money after "visiting" house[i]
 * dp[i]: max(dp[i - 2] + money[i], dp[i - 1])
 * Time complexity: O(n), Space complexity: O(n) -> O(1)
 */
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            dp[i] = max((i > 1 ? dp[i - 2] : 0) + nums[i],
                       ((i > 0 ? dp[i - 1] : 0));
            return dp.back();
        }
    }
};
// @lc code=end

