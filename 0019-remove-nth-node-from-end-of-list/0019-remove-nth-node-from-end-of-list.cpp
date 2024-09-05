class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0;
        ListNode *temp = head;
        while(temp != nullptr){
            cnt++;
            temp = temp ->next;
        }
        if(n==cnt){
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }
        if(cnt < n) {
            return head; // Handle case where n is greater than list length
        }
        
        ListNode* cur = head;
        int c2 = 0;
        while (c2 < (cnt - n - 1)) {
            c2++;
            cur = cur->next;
        }
        
        ListNode* del = cur->next;
        cur->next = cur->next->next;
        delete del;
        return head;
    }
};
