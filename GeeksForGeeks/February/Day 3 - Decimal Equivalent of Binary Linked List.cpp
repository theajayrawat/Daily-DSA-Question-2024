// https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1
// TC: O(N)
// SC: O(1)

class Solution
{
    public:
        // Should return decimal equivalent modulo 1000000007 of binary linked list 
        long long unsigned int decimalValue(Node *head)
        {
           // Your Code Here
           long long unsigned int ans=0;
           Node *ptr=head;
           while(ptr!=NULL){
               ans = (ans*2+ptr->data)%1000000007;
               ptr=ptr->next;
           }
           return ans;
        }
};
