// https://leetcode.com/problems/first-unique-character-in-a-string/
// TC: O(N)
// SC: O(1)

class Solution{
    public:
        void insertNode(Node* prev, int data){
            Node* newNode=new Node(data);
            Node* tmp=prev->next;
            prev->next=newNode;
            newNode->next=tmp;
        }
        Node *sortedInsert(Node* head, int data){
           if(!head){
               head=new Node(data);
               head->next=head;
               return head;
           }
           Node *curr=head;
           while(curr){
               if(head->data>data){
                   insertNode(head, data);
                   swap(head->data, head->next->data);
                   break;
               }
               if(curr->next->data>=data){
                   insertNode(curr, data);
                   break;
               }
               curr=curr->next;
               if(curr->next==head){
                   insertNode(curr, data);
                   break;
               }
           }
           return head;
        }
};
