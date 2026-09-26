class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //array of prefix sums
        int total_count = 0; 
        vector<int> prefix_sums;
        unordered_map<int, vector<int>> sum_locations; 
        prefix_sums.push_back(nums[0]);  
        sum_locations[nums[0]].push_back(0); 
        for(int i = 1; i < nums.size(); i++)
        {
            prefix_sums.push_back(prefix_sums[i - 1] + nums[i]);
            sum_locations[prefix_sums[i]].push_back(i);  
            cout << prefix_sums[i] << " "; 
        }
        cout << "\n" << endl; 
        //then do we iterate through the values, if we go somewhere and find a value that's less than it, we add it to the previous array
        for(int i = 0; i < prefix_sums.size(); i++)
        {
            int diff = prefix_sums[i] - k; 
            if(diff == 0)
            {
                total_count++; 
            }
            if(sum_locations.contains(diff))
            {
                vector<int> diffs = sum_locations[diff]; 
                for(int j = 0; j < diffs.size(); j++)
                {
                    if(diffs[j] < i)
                    {
                        cout << j << " " << i << " " << prefix_sums[j] << " " << prefix_sums[i] << " " << diff << endl; 
                        total_count++; 
                    }
                }
            }
        }
        return total_count; 
    }
};