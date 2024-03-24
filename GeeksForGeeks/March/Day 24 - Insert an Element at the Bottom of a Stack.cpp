// https://www.geeksforgeeks.org/problems/insert-an-element-at-the-bottom-of-a-stack/1
// TC: O(N)
// SC: O(N)

class Solution{
public:
    stack<int> insertAtBottom(stack<int> st,int x){
        vector<int>v;
        while(!st.empty()){
            v.push_back(st.top());
            st.pop();
        }
        st.push(x);
        
        for(int i=v.size()-1;i>=0;i--){
            st.push(v[i]);
        }
        
        return st;
    }
};