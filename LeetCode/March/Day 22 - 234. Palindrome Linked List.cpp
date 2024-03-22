// https://leetcode.com/problems/palindrome-linked-list/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode*prev=NULL;
        ListNode*curr=head;

        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }

    ListNode* middleNode(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast&&fast->next){
              fast=fast->next->next;
              slow=slow->next;
        }
        return slow;
    }

    bool isPalindrome(ListNode* head) {
        ListNode*temp = middleNode(head);
        temp = reverseList(temp);
        while(temp)
        {
            if(head->val!=temp->val)
                return false;
            head=head->next;
            temp=temp->next;
        }
        
        return true;
    }
