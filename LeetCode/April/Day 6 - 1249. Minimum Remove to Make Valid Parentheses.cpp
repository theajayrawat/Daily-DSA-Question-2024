// https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
// TC: O(N)
// SC: O(N)

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<pair<int,int>>st;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push({s[i],i});
            else if(!st.empty()&&s[i]==')'&&st.top().first=='(')st.pop();
            else if(s[i]==')') st.push({s[i],i});
        }

        vector<int>v(s.size(),-1);
        while(!st.empty()){
            v[st.top().second]=st.top().second;
            st.pop();
        }
        string str;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('||s[i]==')'){
                if(v[i]==-1)str+=s[i];
            }
            else str+=s[i];
        }
        return str;
    }
};