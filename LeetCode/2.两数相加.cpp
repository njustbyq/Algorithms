/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/* 链表 + 高精度加法模拟
 * dummy设置为头节点，从头节点下一个节点开始才存储数据。
 * 用sum代表l1和l2两个链表相对应的数字的和的进位，
 * 若l2和l2都已经遍历完全则判断sum是否为0，若sum不为0则代表还有进位没有被表示。
 * 创建节点为sum % 10取余数，进位则用 / 取整判断进位。
 * 时间复杂度: O(max(l1, l2))
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;
        int sum = 0;
        while(l1 || l2 || sum) {
            sum += (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            tail -> next = new ListNode(sum % 10);
            sum /= 10;
            tail = tail -> next;
        }
        return dummy.next;
    }
};
// @lc code=end

