// https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1
// TC: O(N)
// SC: O(N)

class Solution{
  public:
    // your task is to complete this function
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        // Code here
        unordered_set<int> st;
        struct Node* temp1 = head1;
        struct Node* temp2 = head2;
        int ans = 0;
        
        while(temp1) {
            st.insert(temp1->data);
            temp1 = temp1->next;
        }
        
        while(temp2) {
            int rem = x - temp2->data;
            if(st.count(rem) > 0) ans++;
            
            temp2 = temp2->next;
        }
        
        return ans;
    }
};
