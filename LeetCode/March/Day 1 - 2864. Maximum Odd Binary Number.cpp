// https://leetcode.com/problems/maximum-odd-binary-number/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int oneCount=0;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='1')
                oneCount++;
        }
        
        string ans="";
        
        for(int i=0;i<n-1;i++){
            if(oneCount>1){
                ans+='1';
                oneCount--;
            }   
            else
                ans+='0';
        }
             
        return ans+'1';
    }
};

