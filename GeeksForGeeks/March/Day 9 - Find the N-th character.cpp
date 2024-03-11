// https://www.geeksforgeeks.org/problems/find-the-n-th-character5925/1
// TC: O(r*s)
// SC: O(1)

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        while(r--){
            string res = "";
            for(char ch : s){
                if(ch == '1'){
                    res += "10";
                }
                else{
                    res += "01";
                }
            }
            s = res.substr(0,n+1);
        }
        return s[n];
    }
};