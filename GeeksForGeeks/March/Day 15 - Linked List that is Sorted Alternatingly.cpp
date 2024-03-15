// https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1
// TC: O(NlogN)
// SC: O(N)

class Solution
{
    public:
    // your task is to complete this function
    void sort(Node **head)
    {
         // Code here
        if (head == nullptr || *head == nullptr) {
            return;
        }
        
        vector<int> data_vec;
        Node* curr = *head;
        while (curr != nullptr) {
            data_vec.push_back(curr->data);
            curr = curr->next;
        }
        
    
         std::sort(data_vec.begin(), data_vec.end());
        
       
        curr = *head;
        for (int i = 0; i < data_vec.size(); ++i) {
            curr->data = data_vec[i];
            curr = curr->next;
        }
         
         
    }
};