// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// TC: O(N)
// SC: O(1)

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int previousDevice=0;
        int ans=0;

        for(int i=0;i<bank.size();i++){
            int currDevice=0;
            for(int j=0;j<bank[0].size();j++){
                if(bank[i][j]=='1')
                    currDevice++;
            }

            if(currDevice && previousDevice ){
                ans+=currDevice*previousDevice;
            }
            if(currDevice){
                previousDevice=currDevice;
            }
        }

        return ans;
    }
};