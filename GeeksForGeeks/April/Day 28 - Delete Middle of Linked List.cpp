// https://www.geeksforgeeks.org/problems/delete-middle-of-linked-list/1
// TC: O(N)
// SC: O(1)

class Solution{
    public:
    Node* deleteMid(Node* head)
    {
        // Your Code Here
          Node *temp = head;
        Node *slow = head;
        Node *fast = head;
        if(head->next == NULL || head == NULL)
            return NULL;     
        while(slow && fast->next && fast->next->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(fast->next == NULL)
        {
            temp->next = slow->next;
            free(slow);
        }
        if(fast->next && fast->next->next == NULL)
        {
            temp = slow->next;
            slow->next = slow->next->next;
            free(temp);
        }
        return head;
    }
};


