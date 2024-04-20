// https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1
// TC: O(N)
// SC: O(1)

class Solution{
    public:
    //arr1,arr2 : the arrays
    // n, m: size of arrays
    //Function to return a list containing the union of the two arrays. 
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
         int i=0,j=0;
         vector<int>ans;
        while(i<n || j<m){
            if((j==m && i<n) || (i<n && arr1[i]<=arr2[j])){
                ans.push_back(arr1[i]);
            }else{
                ans.push_back(arr2[j]);
            }
            while(i<n && arr1[i]<=ans.back())i++;
            while(j<m && arr2[j]<=ans.back())j++;
        }
        return ans;
    }
};