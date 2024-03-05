// https://www.geeksforgeeks.org/problems/need-some-change/1
// TC: O(N)
// SC: O(1)

class Solution{
  public:
    void swapElements(int arr[], int n){
        
        // Your code here
           
        for (int i=0;i+2<n;i++)
        {  
            swap(arr[i],arr[i+2]);
        }
        
    }
};

