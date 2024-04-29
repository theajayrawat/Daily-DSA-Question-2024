// https://geeksforgeeks.org/problems/remove-every-kth-node/1
// TC: O(N)
// SC: O(1)

class Solution {
    public:
    Node* deleteK(Node *head,int k){
      //Your code here
        if(k==1)
            return NULL;
        int i=1;
        Node* cur=head;
        while(cur!=NULL && cur->next!=NULL)
        {
            if(i==k-1)
            {
                cur->next=cur->next->next;
                cur=cur->next; //if we update cur here then no need to set i to 0.
                i=1; // set i to 1 since cur is moved.
                
            }
            else
            {
               cur=cur->next;
               i++;
            }
        }
        return head;
    }
};
