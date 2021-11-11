/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start

/*
 * 注意先要将x的值赋给别的变量，
 * 否则最后一步将x与num进行必须时一定会报错
 * 
 */

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        int t = x;
        long num = 0;
        while(t > 0) {
            num = num * 10 + t % 10;
            t /= 10;
        }
        return num == x;
    }
};
// @lc code=end

