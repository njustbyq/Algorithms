/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int min;
        for (int i = 0; i < nums.size(); i++) {
            if (min > nums[i]) {
                min = nums[i];
            }
        }
        return min;
    }
};
// @lc code=end

