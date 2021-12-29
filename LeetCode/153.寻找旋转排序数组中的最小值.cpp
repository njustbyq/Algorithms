/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start

/*
 * Solution: Divide and Conquer
 * findMin(array):
 *   if is_sorted(array):
 *      return array[0]
 *   return min(findMin(array[0 : mid]),
 *              findMin(array[mid : n]))
 * 
 * is_sorted(array):
 *   return array[0] < array[n - 1]
 * 
 * Time Complexity:
 * T(n) = O(1) + T(n / 2) = O(logn)
 * O(1) is the time complexity of finding the min element in a sorted array.
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMin(nums, 0, nums.size() - 1);
    }
private:
    int findMin(const vector<int>& num, int l, int r) {
        // only 1 or 2 elements
        if(l + 1 >= r) return min(num[l], num[r]);

        //Sorted
        if(num[l] < num[r]) return num[l];

        int mid = l + (r - l) / 2;

        return min(findMin(num, l, mid - 1),
                   findMin(num, mid, r));
    }
};
// @lc code=end

