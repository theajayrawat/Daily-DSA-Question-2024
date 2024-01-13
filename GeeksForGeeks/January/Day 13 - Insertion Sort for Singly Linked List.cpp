// https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1
// SC: O(N^2)
// TC: O(1) 

/*Link list node
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        //code here
        if (!head_ref || !head_ref->next) {
            return head_ref;
        }
        Node* temp = head_ref;
        Node* prev = temp;
        Node* curr = temp->next;
        Node* nxt = temp->next->next;
        
        while(curr){
            if(curr->data<prev->data){
                prev->next = nxt;
                Node* prev_t = NULL;
                Node* nxt_t = temp;
                while(nxt_t){
                    if(nxt_t->data>=curr->data){
                        if(prev_t!=NULL) prev_t->next = curr;
                        curr->next = nxt_t;
                        break;
                    }
                    prev_t = nxt_t;
                    nxt_t = nxt_t->next;
                }
                if(prev_t == NULL) temp = curr;
            }
            else{
                prev = curr;
            }
            curr = nxt;
            if(nxt) nxt = nxt->next;
        }
        return temp;
        
    }
    
};