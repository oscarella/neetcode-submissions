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
    ListNode* reverseList(ListNode* head) {
        // Recursive sol
        if (!head || !(head->next)) return head;
        ListNode *reversed = reverseList(head->next); // head of reversed list
        ListNode *curr = reversed;
        while(curr->next) {
            curr = curr->next;
        }
        curr->next = head;
        head->next = nullptr;
        return reversed;
    }
};
