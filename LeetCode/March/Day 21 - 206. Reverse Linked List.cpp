// https://leetcode.com/problems/reverse-linked-list/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL||head->next==NULL)
            return head;

        ListNode* nnode = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return nnode;

    }
};