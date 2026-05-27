class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int ind1 = 0; 
        int ind2 = 0; 
        vector<int> nums_copy(nums1); 
        //if we add from nums2, we'd basically have to move everything forward
        while(ind1 < m && ind2 < n)
        {
            if(nums_copy[ind1] < nums2[ind2])
            {
                nums1[ind1 + ind2] = nums_copy[ind1]; 
                ind1++; 
            }
            else
            {
                nums1[ind1 + ind2] = nums2[ind2]; 
                ind2++; 
            }
        }
        for(int i = ind1; i < m; i++)
        {
            nums1[n + i] = nums_copy[i]; 
        }
        for(int i = ind2; i < n; i++)
        {
            nums1[m + i] = nums2[i]; 
        }
    }
};