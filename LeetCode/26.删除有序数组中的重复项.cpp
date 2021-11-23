/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start

/*
 * 因为第一个数字是一定要保留的，所以count从1开始。
 * 比较前后两个数字，若相同则直接略过，
 * 若不相同则将其添加进原来的nums数组，最后返回count.
 */
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int count = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i - 1] != nums[i]) {
                nums[count++] = nums[i];
            }
        }
        return count;
    }
};
// @lc code=end

