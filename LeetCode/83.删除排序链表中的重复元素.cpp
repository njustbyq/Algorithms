/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
/**
 * while循环判断当前节点的val是否与当前节点的下一个节点的val相同
 * 相同则当前节点的next指针指向下一节点的下一节点, 否则cur向后移一个节点
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *cur = head;
        while(cur != NULL) {
            ListNode *rear = cur->next;
            if (rear == NULL) return head;
            if (cur->val == rear->val) {
                cur->next = rear->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};
// @lc code=end

