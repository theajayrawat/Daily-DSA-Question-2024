// https://leetcode.com/problems/daily-temperatures/
// T.C : O(N)
// S.C : O(N)

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        for(int i=0;i<temperatures.size();i++){
            while(!st.empty() && temperatures[st.top()]<temperatures[i]){
                temperatures[st.top()]=i-st.top();
                st.pop(); 
            }
            st.push(i);
        }

        while(!st.empty()){
            temperatures[st.top()]=0;
            st.pop();
        }

        return temperatures;
    }
};

