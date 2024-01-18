// https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1
// TC: O(N)
// SC: O(N)

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
        // add code here.
        stack<int>st;
        while(k){
            st.push(q.front());
            q.pop();
            k--;
        }
        

        int n=q.size();
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        
        while(n){
            int val=q.front();
            q.pop();
            q.push(val);
            n--;
        }
        
        return q;
    }
};

