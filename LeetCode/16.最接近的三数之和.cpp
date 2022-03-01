/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
/**
 * 排序 + 双指针
 * 对nums数组排序, 使用前指针指向start = i + 1, 后指针指向end = nums.length - 1
 * 根据sum的结果判断sum与目标target的距离, 若更接近target更新res
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return -1;
        sort(nums.begin(), nums.end());
        int diff = INT_MAX;
        int res = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (abs(sum - target) < diff) {
                    diff = abs(sum - target);
                    res = sum;
                }
                // 双指针更新
                if (target == sum) {
                    return sum;
                } else if (sum > target) {
                    right--;
                } else if (sum < target) {
                    left++;
                }
            }
        }
        return res;
    }
};
