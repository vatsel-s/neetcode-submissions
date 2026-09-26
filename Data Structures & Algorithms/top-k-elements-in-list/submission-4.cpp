class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count; 
        for(int i = 0; i < nums.size(); i++)
        {
            count[nums[i]]+=1; 
        }
        priority_queue<pair<int, int>> maxPQ; 
        for(auto it = count.begin(); it != count.end(); it++)
        {
            pair<int, int> curr(it->second, it->first); 
            maxPQ.push(curr); 
        }
        vector<int> output; 
        for(int i = 0; i < k; i++)
        {
            output.push_back(maxPQ.top().second); 
            maxPQ.pop(); 
        }
        return output; 
    }
};
