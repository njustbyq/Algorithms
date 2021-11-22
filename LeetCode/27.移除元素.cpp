/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

/*
 * 当nums[i]与给定的值相等时，递增i以跳过该元素。
 * 只要nums[i] != val, 我们就复制nums[i]到nums[count]
 * 并同时递增两个索引。重复这一过程直到i到达数组末尾。
 * 该数组的新长度为count。
 */
// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[count++] = nums[i]; 
            }
        }
        return count;
    }
};
// @lc code=end

