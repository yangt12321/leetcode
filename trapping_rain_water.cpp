/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
For example,
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6. 
*/
class Solution {
public:
    int trap(int A[], int n) {
        int rst = 0;
        if(n<3) return rst;
        vector<int> tHigh(A, A+n);
        for(int i=1; i<n-1; ++i)                        //find the highest bar in the left
            tHigh[i] = max(tHigh[i-1], A[i]);
        for(int i=n-2; i>0; --i) {                      //find the highest bar in the right
            tHigh[i] = max(tHigh[i+1], A[i]);
            rst += max(min(tHigh[i-1], tHigh[i+1])-A[i], 0);  //volume this bar can hold
        }
        return rst;
    }
};
