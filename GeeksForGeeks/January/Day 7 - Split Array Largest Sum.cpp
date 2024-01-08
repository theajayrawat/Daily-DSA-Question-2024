// https://www.geeksforgeeks.org/problems/split-array-largest-sum--141634/1
// SC: O(N*log(sum(arr[])))
// TC: O(1)

class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
         int start=0;
        int end=0;

        for(int i=0;i<N;i++){
            start=max(start,arr[i]);
            end+=arr[i];
        }

        while(start<=end){
            int mid=start+(end-start)/2;

            int sum=0;
            int piece=1;
            for(int i=0;i<N;i++){
                if(sum+arr[i]>mid){
                    piece++;
                    sum=arr[i];
                }
                else{
                    sum+=arr[i];
                }
            }
            if(piece>K)start=mid+1;
            else end=mid-1;
        }
        return start;
    }
};