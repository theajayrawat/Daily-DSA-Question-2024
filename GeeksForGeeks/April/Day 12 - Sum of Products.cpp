// https://www.geeksforgeeks.org/problems/sum-of-products5049/1
// TC: O(N)
// SC: O(1)

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        // code here
        long long ans = 0;
         for(int i = 0;i<64;i++){
         //first find how many sets bits on ith positon
         long long set = 0;
         for(int j = 0;j<n;j++){
             (((arr[j] >> i) &1) == 1) ? set+=1 : set;  
         }
         
        long long tCom = set*(set-1)/2;
        ans += pow(2,i)*tCom;
     }
     return ans;
    }
};

