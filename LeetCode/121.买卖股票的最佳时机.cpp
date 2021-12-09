/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start

/*
 * Definition: max_profit = max{price[j] - price[i]}, 0 <= i < j <= n - 1
 * Solution 1: Brute Force (TLE)
 * Enumerate all pairs of (i, j)
 * Time Complexity: O(n^2)
 * 
 * Observation:
 * Buy:  prices[i]: min{prices[k]}, k <= i
 * Sell: prices[j]: max{prices[k]}, k >= j
 * 
 * Solution 2: DP
 * Keeping tracking the min price so far
 * L[i] : lowest price up to i-th day
 * P[i] : max profit up to i-th day
 * P[i] = max(P[i - 1], price[i] - L[i])
 * buy at the lowest price and sell at i-th day
 * max_profit = P[n - 1]
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = prices.size();
        if(n < 1) return 0;
        vector<int> min_prices(n);
        vector<int> max_profit(n);
        min_prices[0] = prices[0];
        max_profit[0] = 0;
        for(int i = 1; i < n; i++) {
            min_prices[i] = min(min_prices[i - 1], prices[i]);

            max_profit[i] = max(max_profit[i - 1], prices[i] - min_prices[i - 1]);
        }
        return max_profit[n - 1];
    }
};
// @lc code=end

