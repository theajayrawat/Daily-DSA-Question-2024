// https://www.geeksforgeeks.org/problems/remove-k-digits/1
// TC: O(N)
// SC: O(N)

class Solution {
  public:
    string removeKdigits(string S, int K) {
        string ans="";
        for(char ch:S){
            while(ans.size() && ans.back()>ch  && K){
                ans.pop_back();
                K--;
            }
            if(ans.size() || ch!='0'){
                ans.push_back(ch);
            }
        }
        while(ans.size() && K){
            ans.pop_back();
            K--;
            
        }
        if(ans==""){
            return "0";
        }
        return ans;
    }
};

