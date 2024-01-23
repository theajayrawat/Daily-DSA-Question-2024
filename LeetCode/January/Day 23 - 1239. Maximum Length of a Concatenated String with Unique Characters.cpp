// https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
// TC: O(2^N)
// SC: O(N)

class Solution {
public:
    int maxLength(vector<string>& arr) {
        int maxLength=0;
        solve(arr,maxLength,0,0);
        return maxLength;
    }
    void solve(vector<string>& arr,int &maxLength, int currString,int index ){
        if(index==arr.size()){
            int count = 0;
            for (int i = 0; i < 26; ++i) {
                if ((currString & (1 << i)) != 0) {
                    count++;
                }
            }
            maxLength = max(maxLength, count);
            return;
        }

        int newString=currString;
        bool isValid=true;


        for(int i=0;i<arr[index].size();i++){
            int bits=1<<(arr[index][i]-'a');
            if((bits & newString)==0){
                newString|=bits;
            }else{
                isValid=false;
                break;
            }
        }

        if(isValid){
            solve(arr,maxLength,newString,index+1);
        }

        solve(arr,maxLength,currString,index+1);
    }
};





