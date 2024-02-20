// https://www.geeksforgeeks.org/problems/word-break1352/1
// TC: O(N^2)
// SC: O(N)

class Solution
{
public:
    bool solve(set<string>&st, string A, int index){
        if(index==A.size())
            return true;
        
        string str;
        bool ans=false;
        for(int j=index;j<A.size();j++){
            str+=A[j];
            if(st.find(str)!=st.end()){
                ans|=solve(st,A,j+1);
            }
        }
        
        return ans;
    }
    int wordBreak(string A, vector<string> &B) {
        //code here
        set<string>st;
        
        for(int i=0;i<B.size();i++){
            st.insert(B[i]);
        }
        
        return solve(st,A,0);
        
    }
};