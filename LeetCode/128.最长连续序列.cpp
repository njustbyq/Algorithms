/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start

/*
 * Solution 1: HashTable: (key, len)
 * Case 1: no neighbor
 * h[key] = 1
 * 
 * Case 2: has a single neighbor, extend 
 *   l = h[key +- 1]
 *   h[key +- 1] = h[key] = l + 1
 * 
 * Case 3: has 2 neighbors, a bridge
 *   l = h[key - 1]
 *   r = h[key + 1]
 *   t = l + r + 1
 *   h[key - l] = h[key + r] = t 
 */
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int , int> h;
        for (int num: nums) {
            if(h.count(num)) continue;

            auto it_l = h.find(num - 1);
            auto it_r = h.find(num + 1);
            int l = it_l != h.end() ? it_l->second : 0;
            int r = it_r != h.end() ? it_r->second : 0;
            if (l > 0 && r > 0)
                h[num] = h[num - l] = h[num + r] = l + r + 1;
            else if (l > 0)
                h[num] = h[num - l] = l + 1;
            else if (r > 0)
                h[num] = h[num + r] = r + 1;
            else
                h[num] = 1;
        }
        int ans = 0;
        for(const auto& kv : h)
            ans = max(ans, kv.second);
        return ans;
    }
};
// @lc code=end

