// https://www.geeksforgeeks.org/problems/implement-atoi/1
// TC: O(N)
// SC: O(1)

class Solution{
  public:
    /*You are required to complete this method */
    int atoi(string s) {
        //Your code here
        int result = 0;
        int sing= 1;
        
      
        if(s.empty()){
            return -1;
        }
        
    
        char val = s[0];
        if(val == '-'){
            sing= -1;
        }
        else if(val>='0' && val<='9'){
            result = val - '0';
        }
        else{
            return -1;
        }
        
        for(int i=1;i<s.length();i++){
            val = s[i];
            if(val>='0' && val <='9'){
                result = result *10 + (val-'0');
            }
            else{
                return -1;
            }
        }
        
        return sing *  result;
    }
};