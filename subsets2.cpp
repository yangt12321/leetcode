/*
Subsets IIJun 25 '124769 / 13419

Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

    Elements in a subset must be in non-descending order.
    The solution set must not contain duplicate subsets.

For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/
class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        vector<vector<int> > rst(1);
        sort(S.begin(), S.end());
        int lastlen = -1;
        for(int i=0; i<S.size(); ++i) {
            int curlen = rst.size();     //current size 
            int j = 0;                   //position of element which will be copied and inserted
            if(i>0 && S[i]==S[i-1]) j = lastlen;  //handle the duplicate situation, eg., 0 1 2 2 when i=3, we've got [],[1],[2],[12],then j should start from position 2
            for(; j<curlen; ++j) {
                rst.push_back(rst[j]);
                rst.back().push_back(S[i]);
            }
            lastlen = curlen;
        }
        return rst;
    }
};
