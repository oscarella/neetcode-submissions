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

class Solution {
public:
    // RECURSIVE function
    ListNode* reverseList(ListNode* head) {
        ListNode *i = nullptr;

        while (head) {
            ListNode *tmp = head->next;
            head->next = i;
            i = head;
            head = tmp;
        }

        if (i) return i;
        else return nullptr;
    }
};
