/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start

/*
 * Solution : HashTable
 * 先扫描第一个元素, 然后在字符串中搜索最后一个该元素出现的位置.
 * 再在区间中扫描, 若有元素的最后一个出现位置超过原先的区间则更新区间范围
 * Time: O(n^2)
 * Space: O(26 / 128)
 * 128 refers to 128 ASCII
 */
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last_index(128, 0);
        for (int i = 0; i < s.size(); i++) {
            last_index[s[i]] = i;
        }
        vector<int> ans;
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); i++) {
            end = max(end, last_index[s[i]]);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return ans;
    }
};
// @lc code=end

