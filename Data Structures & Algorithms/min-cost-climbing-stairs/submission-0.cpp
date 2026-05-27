class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> result(cost.size() + 1); 
        result[0] = cost[0]; 
        result[1] = cost[1]; 
        for(int i = 2; i < result.size(); i++)
        {
            result[i] = min(result[i-1] + cost[i], result[i-2] + cost[i]); 
        }
        return result[result.size() -1]; 
    }
};
