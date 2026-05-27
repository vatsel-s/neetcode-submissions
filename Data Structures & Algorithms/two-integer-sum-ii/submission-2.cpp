class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first_index = 0; 
        int last_index = numbers.size() -1; 
        while(first_index < last_index)
        {
            if(numbers[first_index] + numbers[last_index] == target)
            {
                vector<int> result = {first_index + 1, last_index + 1}; 
                return result; 
            }
            else if(numbers[first_index] + numbers[last_index] > target)
            {
                last_index--; 
            }
            else if(numbers[first_index] + numbers[last_index] < target)
            {
                first_index++; 
            }
        }
    }
};
