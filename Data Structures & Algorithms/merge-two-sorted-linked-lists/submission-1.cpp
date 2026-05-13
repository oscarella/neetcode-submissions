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

// RECURSIVE SOLUTION

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // Base Case
        if (!list1 && !list2) return nullptr;
        else if (!list1) return list2;
        else if (!list2) return list1;
        // Non-Base Case
        if (list1->val < list2->val) {
            ListNode *sortedList = mergeTwoLists(list1->next, list2);
            list1->next = sortedList;
            return list1;
        } else {
            ListNode *sortedList = mergeTwoLists(list1, list2->next);
            list2->next = sortedList;
            return list2;
        }
    }
};
