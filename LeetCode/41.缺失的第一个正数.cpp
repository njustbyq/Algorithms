/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

/*
 * Solution: Bucket Sort;
 * 即: 每个元素应该在其所在的位置
 * nums[i] - 1表示该元素应该所在的位置
 * 最大缺失的正数即为nums[i]!=i+1的数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size() == 0) return 1;
        for(int i = 0; i < nums.size(); i++) {
            while(nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                int temp = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = temp;
            }
        }
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
}; 
// @lc code=end

