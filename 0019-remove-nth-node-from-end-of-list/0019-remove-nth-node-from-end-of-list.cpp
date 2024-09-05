class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;  // Dummy node points to the head
        ListNode* fast = start;
        ListNode* slow = start;

        // Move fast pointer n+1 steps ahead
        for(int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move fast to the end, maintaining the gap
        while(fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // Skip the desired node
        slow->next = slow->next->next;

        // Return the head, which might be a new head if the first node was removed
        return start->next;
    }
};
