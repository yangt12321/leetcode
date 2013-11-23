/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.
For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle. 
*/
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle) {
        int m = triangle.size();
        vector<int> dp(m, INT_MAX);   //store the current minimum sum in each position
        dp[0] = 0;
        for(int i=0; i<m; ++i) {	  //traverse each row	
            for(int j=i; j>0; --j) 
                dp[j] = triangle[i][j] + min(dp[j-1], dp[j]);  //update 
            dp[0] += triangle[i][0];
        }
        for(int i=1; i<m; ++i)
            if(dp[i] < dp[0]) 
                dp[0] = dp[i];
        return dp[0];
    }
};
