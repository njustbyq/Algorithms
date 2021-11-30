/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 */

// @lc code=start

/*
 * 常规思路: 循环32次，依次判断每一位的值
 */

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for(int i = 0; i < 32; i++) {
            if(n % 2 == 1) {
                count++;
            }
            n /= 2;
        }
        return count;
    }
};
// @lc code=end

