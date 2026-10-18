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
        stack<int> s;
        ListNode *curr = head;
        while (curr) {
            s.push(curr->val);
            curr = curr->next;
        }
        // s contains list in reverse order
        curr = head;
        while (curr) {
            curr->val = s.top();
            s.pop();
            curr = curr->next;
        }
        return head;
    }
};
