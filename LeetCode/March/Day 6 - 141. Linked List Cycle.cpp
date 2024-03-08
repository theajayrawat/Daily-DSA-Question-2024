// https://leetcode.com/problems/linked-list-cycle/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    bool hasCycle(ListNode *head) {
        int val=1e5+1;
        while(head)
        {
            if(head->val == val) return true;
            head->val = val;
            head = head->next;
        }
        return false;
    }
};

