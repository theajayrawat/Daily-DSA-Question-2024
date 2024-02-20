// https://www.geeksforgeeks.org/problems/does-array-represent-heap4345/1
// TC: O(N)
// SC: O(1)

class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        // Your code goes here
          for(int i=0;i<n/2;i++){
            int leftChild=2*i+1;
            int rightChild=2*i+2;
            if(arr[i] < arr[leftChild] || arr[i]<arr[rightChild]){
                return false;
            }
        }
        return true;
    }
};

