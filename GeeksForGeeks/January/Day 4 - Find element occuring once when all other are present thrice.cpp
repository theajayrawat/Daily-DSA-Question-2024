// https://www.geeksforgeeks.org/problems/find-element-occuring-once-when-all-other-are-present-thrice/1
// TC: O(N)
// SC: O(1)

class Solution {
  public:
    int singleElement(int arr[] ,int N) {
        // code here
        int ans=0;
        for(int i=0; i<=32; i++){
            int bit = 1<<i;
            int sum=0;
            
            for(int j=0; j<N; j++){
                if((arr[j]&bit)){
                    sum++;
                }
            }
            
            if(sum%3){
                ans = ans | bit;
            }
        }
        return ans;
    }
};
