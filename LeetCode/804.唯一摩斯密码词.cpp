/*
 * @lc app=leetcode.cn id=804 lang=cpp
 *
 * [804] 唯一摩斯密码词
 */

// @lc code=start

/*
 * 
 */
const static string MORSE[] = {
        ".-","-...","-.-.","-..",".","..-.","--.",
        "....","..",".---","-.-",".-..","--","-.",
        "---",".--.","--.-",".-.","...","-","..-",
        "...-",".--","-..-","-.--","--.."
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> seen;
        for (auto word : words) {
            string code;
            for (auto c : word) {
                code.append(MORSE[c - 'a']);
            }
            seen.emplace(code);
        }
        return seen.size();
    }
};
// @lc code=end

