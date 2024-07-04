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
    ListNode* mergeNodes(ListNode* head) {
        if(head->next == nullptr) {
            return 0;
        }
        head = head->next;
        struct ListNode* temp = head;   
        struct ListNode* traverse = temp->next; 

        while (temp->next != nullptr) {
            if (traverse->val != 0) {
                temp->val += traverse->val;
                traverse = traverse->next;
            } else {
                temp->next = traverse->next; 
                if(temp->next == nullptr) {
                    return head;
                }
                temp = traverse->next;
                traverse = temp->next;
            }
        }

        return 0;
    }
};