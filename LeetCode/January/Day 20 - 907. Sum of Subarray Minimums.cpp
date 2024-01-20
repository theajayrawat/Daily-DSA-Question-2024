// https://leetcode.com/problems/sum-of-subarray-minimums/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int base=1e9+7;
         int n=arr.size();
          stack<int>st;
        vector<int>next(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&&arr[i]<=arr[st.top()]){
                next[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            next[st.top()]=n;
            st.pop();
        }
    
         vector<int>prev(n);
         for(int i=n-1;i>=0;i--){
            while(!st.empty()&& arr[i]< arr[st.top()]){
                prev[st.top()]= i;
                st.pop();
            }
            st.push(i);
        }
          while(!st.empty()){
            prev[st.top()]=-1;
            st.pop();
        }
      
         long res=0;
        for(int i=0;i<arr.size();i++){ 
           res=(long)res%base+(long)((i-prev[i])*(next[i]-i)*(long)arr[i]);
        }
        return res;
    }
};

