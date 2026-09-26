class KthLargest {
public:
    priority_queue<int> maxPq; 
    int num; 
    KthLargest(int k, vector<int>& nums) {
        num = k; 
        for(int i = 0; i < nums.size(); i++)
        {
            maxPq.push(nums[i]); 
        }
    }
    
    int add(int val) {
        vector<int> vals_removed; 
        maxPq.push(val); 
        for(int i = 1; i < num; i++)
        {
            vals_removed.push_back(maxPq.top()); 
            maxPq.pop(); 
        }
        int saved = maxPq.top(); 
        for(int i = 0; i < vals_removed.size(); i++)
        {
            maxPq.push(vals_removed[i]); 
        }
        return saved; 
    }
};
