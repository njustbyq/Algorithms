/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start

/*
 *【遍历unordered_map】
 * unordered_map<key, T>::iterator it; 
 * (*it).first;     //the key value
 * (*it).second;    //the mapped value
 * for(unordered_map<key, T>::iterator iter=mp.begin();iter!=end();iter++)
 * cout << "key value is" << iter->first << "the mapped value is" << iter->second
 * 也可以这样:
 * for(auto& v: mp)
 *  print v.first and v.second
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> ans;
        for(int i = 0; i < nums.size(); i++) {
            ans[nums[i]]++;
        }
        for(auto& n : ans) {
            if(n.second == 1) {
                return n.first;
            }
        }
        return 0;
    }
};
// @lc code=end

