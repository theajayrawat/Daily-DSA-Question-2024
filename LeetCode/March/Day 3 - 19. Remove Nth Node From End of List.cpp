// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int nodeLength(ListNode* head)
    {
        int len=0;

        while(head)
        {
            head=head->next;
            len++;
        }

        return len;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=nodeLength(head);
        ListNode* temp=head;

        //head remove
        if(len==n)
        {
            temp=temp->next;
            return temp;
        }

        //tail remove
        if(n==1){
            len=len-2;
            while(len--)
                temp=temp->next;

            temp->next=NULL;
            return head;
        }

        //other node 
        len=len-n-1;
        while(len--)
            temp=temp->next;

        ListNode*del=temp->next;
        temp->next=temp->next->next;

        delete(del);
        return head;
        
    }
};

