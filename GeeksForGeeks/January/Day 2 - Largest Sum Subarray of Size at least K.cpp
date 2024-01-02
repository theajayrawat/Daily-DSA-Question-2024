// https://www.geeksforgeeks.org/problems/largest-sum-subarray-of-size-at-least-k3121/1
// TC: O(N)
// SC: O(N)

class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        long long int ans=LLONG_MIN;
        long long int maxSum[n]; //store maximum sum at index;
        
        //Kadane algo
        long long int csum=a[0];
        maxSum[0]=csum;
        for(long long int i=1;i<n;i++){
            if(csum>0){
                csum+=a[i];
            }else{
                csum=a[i];
            }
            maxSum[i]=csum;
        }
        
        long long int exactK=0;
        for(long long int i=0;i<k;i++){
          exactK+=a[i];
        }
        
        if(ans<exactK){
            ans=exactK;
        }
            
            
        for(long long int i=k;i<n;i++){
             exactK+=a[i]-a[i-k];
            if(exactK>ans){
                ans=exactK;
            }
            
            long long int moreThanK=maxSum[i-k]+exactK;
            if(moreThanK>ans){
                ans=moreThanK;
            }
            
        }
        
        
        return ans;
    }
};
