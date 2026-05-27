class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency; 
        for(int i = 0; i < nums.size(); i++)
        {
            frequency[nums[i]]++; 
        }
        unordered_map<int, int> freqToNum; 
        for(auto iter = frequency.begin(); iter != frequency.end(); iter++)
        {
            freqToNum[iter->second] = iter->first; 
        }
        vector<vector<int>> buckets(nums.size() + 1); 
        for(auto iter = frequency.begin(); iter != frequency.end(); iter++)
        {
            buckets[iter->second].push_back(iter->first); 
        }
        vector<int> result; 
        int counter = 0; 
        for(int i = buckets.size() - 1; i >= 0; i--)
        {
            for(int j = 0; j < buckets[i].size(); j++)
            {
                result.push_back(buckets[i][j]); 
                counter++; 
            }
            if(counter >= k)
            {
                return result; 
            }
        }
        return result; 

    }
};
