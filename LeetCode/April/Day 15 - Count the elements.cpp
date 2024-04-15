// https://www.geeksforgeeks.org/problems/count-the-elements1529/1
// TC: O(N)
// SC: O(N)

class Solution {
  public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query,
                              int q) {
          //find max element from a or b                          
       int maxi=max(*max_element(a.begin(),a.end()),*max_element(b.begin(),b.end()));
       
       //count frequency of the element of array b
       vector<int>count(maxi+1,0);
       for(int i=0;i<b.size();i++){
            count[b[i]]++;
       }
       //calculate cumulative sum
       for(int i=1;i<=maxi;i++){
           count[i]=count[i]+count[i-1];
       }
      //  push count[a[query[i]]] in  ans
       vector<int>ans;
       for(int i=0;i<q;i++){
           ans.push_back(count[a[query[i]]]);
       }
       return ans;
    }
};
