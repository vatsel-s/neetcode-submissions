class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trusting(n); 
        vector<int> trusted(n);
        for(int i = 0; i < trust.size(); i++)
        {
            vector<int> curr = trust[i]; 
            trusting[curr[0] - 1]+=1; 
            trusted[curr[1] - 1]+=1; 
        } 
        for(int i = 0; i < n; i++)
        {
            if(trusting[i] == 0 && trusted[i] == n-1)
            {
                return i + 1; 
            }
        }
        return -1; 
    }
};