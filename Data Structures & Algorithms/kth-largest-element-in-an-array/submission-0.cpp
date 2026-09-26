class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //this time we're going to use a min heap, and then I don't think it matter
        //if we use a min heap, we still have to add everything to the heap and remove it
        //if we use the min heap and add to the heap, if the element is less than max, we can include
        //otherwise, we can add the min
        priority_queue<int, vector<int>, greater<int>> min_heap; 
        for(int i = 0; i < k; i++)
        {
            min_heap.push(nums[i]); 
        }
        for(int i = k; i < nums.size(); i++)
        {
            if(nums[i] > min_heap.top())
            {
                min_heap.pop(); 
                min_heap.push(nums[i]); 
            }
        }
    
        return min_heap.top(); 
    }
};
