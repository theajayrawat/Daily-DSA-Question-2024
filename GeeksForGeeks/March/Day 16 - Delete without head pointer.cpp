// https://www.geeksforgeeks.org/problems/delete-without-head-pointer/1
// TC: O(1)
// SC: O(1)

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
       // Your code here
        Node* temp=del_node->next;
       del_node->data=del_node->next->data;
       del_node->next=del_node->next->next;
       delete(temp);
    }

};