// https://www.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1
// TC: O(N)
// SC: O(1)


class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     Node * reverse(Node *head){
        Node * prev = NULL;
        Node * curr = head;
        
        while(curr){
            Node * n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* num1, struct Node* num2)
    {
        // code here
        if(!num1) return num2;
        if(!num2) return num1;
        if(!num1 && !num2) return NULL;
        
        Node* l1 = reverse(num1);
        Node* l2 = reverse(num2);
        
        Node* dummy=new Node(-1);
        Node* temp=dummy;
        int carry=0;

        while(l1 || l2 || carry)
        {
            int a = l1==NULL?0:l1->data;
            int b = l2==NULL?0:l2->data;
            int sum = a + b + carry;
            carry = sum/10;

            Node* node=new Node(sum%10);
            temp->next=node;
            temp=temp->next;

            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
        }

        Node* curr = reverse(dummy->next);
          while(curr && curr->data == 0 && curr->next){
            curr = curr->next;
        }
        return curr;
    }
};