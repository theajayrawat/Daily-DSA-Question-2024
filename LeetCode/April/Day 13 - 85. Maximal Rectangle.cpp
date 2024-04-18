// https://leetcode.com/problems/maximal-rectangle/
// TC: O(N^3)
// SC: O(N)

class Solution {
public:
 int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
          stack<int>st;
        vector<int>next(n);
        for(int i=0;i<n;i++){
            while(!st.empty()&& heights[i]< heights[st.top()]){
                next[st.top()]= i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            next[st.top()]=n;
            st.pop();
        }
        
         vector<int>prev(n);
         for(int i=n-1;i>=0;i--){
            while(!st.empty()&& heights[i]< heights[st.top()]){
                prev[st.top()]= i;
                st.pop();
            }
            st.push(i);
        }
          while(!st.empty()){
            prev[st.top()]=-1;
            st.pop();
        }
        int max_ans=INT_MIN;
        for(int i=0;i<n;i++)max_ans=max(max_ans,heights[i]*(next[i]-prev[i]-1));
        return max_ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>M(n,vector<int>(m,0));
         for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(matrix[i][j]=='1')M[i][j]=1;
            }
         }
        int area = largestRectangleArea(M[0]);
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(M[i][j]==1)
                    M[i][j] = M[i][j] + M[i-1][j];
                else
                    M[i][j] = 0;
            }
            area = max(area, largestRectangleArea(M[i]));
            
        }
        return area;
    }
};