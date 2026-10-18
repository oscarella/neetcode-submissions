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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list2) return list1;
        if (!list1) return list2;
        // Guaranteed that list1 and list2 both have at least one node
        ListNode *listOnePtr = list1;
        ListNode *listTwoPtr = list2;
        ListNode *head;
        if (listOnePtr->val < listTwoPtr->val) {
            head = listOnePtr;
            listOnePtr = listOnePtr->next;
        } else {
            head = listTwoPtr;
            listTwoPtr = listTwoPtr->next;
        }
        
        ListNode *curr = head;
        while (listOnePtr || listTwoPtr) {
            if (listOnePtr == nullptr) {
                curr->next = listTwoPtr;
                break;
            } else if (listTwoPtr == nullptr) {
                curr->next = listOnePtr;
                break;
            } else {
                if (listOnePtr->val < listTwoPtr->val) {
                    curr->next = listOnePtr;
                    curr = curr->next;
                    listOnePtr = listOnePtr->next;
                } else {
                    curr->next = listTwoPtr;
                    curr = curr->next;
                    listTwoPtr = listTwoPtr->next;
                }
            }
        }
        return head;
    }
};
