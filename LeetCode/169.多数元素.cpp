/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start

/*
 * 思路: 位操作
 * int类型总共32位，若某一个数字超过半数的数组
 * 则该数字的每一bit上的1也会超过数组总数的一半
 * &操作，｜操作用于提取和过滤信息
 */

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        const int n = nums.size();
        int majority = 0;
        for (int i = 0; i < 32; i++) {
            int mask = 1 << i;
            int count = 0;
            for (auto& num : nums) {
                if (num & mask) {
                    count++;
                }
            }
            if (count > n / 2) majority |= mask;
        }
        return majority;
    }
};
// @lc code=end

