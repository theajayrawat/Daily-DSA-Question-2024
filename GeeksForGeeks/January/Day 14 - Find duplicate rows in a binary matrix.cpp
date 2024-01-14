// https://www.geeksforgeeks.org/problems/find-duplicate-rows-in-a-binary-matrix/1
// SC: O(N)
// TC: O(N) 

class Solution
{   
    public:
    vector<int> repeatedRows(vector<vector<int>> &matrix, int M, int N) 
    { 
        // Your code here
        set<string> s;
        vector<int>p;
        for(int i=0;i<M;i++){
            string res="";
            for(int j=0;j<N;j++){
                res+=to_string(matrix[i][j]);
            }
            if(s.find(res)!=s.end()){
                p.push_back(i);
            }else{
                s.insert(res);
            }
            res="";
        }
        return p;
      
    } 
};
