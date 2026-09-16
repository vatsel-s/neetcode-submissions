class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int sum = 0; 
        int max = 0;
        for(unsigned int i = 0; i < piles.size(); i++)
        {
            if(piles[i] > max)
            {
                max = piles[i]; 
            }
            sum += piles[i]; 
        }
        int left = sum/h; 
        if(sum%h > 0)
        {
            left += 1; 
        }
        int right = max; 

        while(left < right)
        {
            int med = (left + right)/2; 
            int count = 0; 
            for(unsigned int i = 0; i < piles.size(); i++)
            {
                count += piles[i]/med; 
                if(piles[i]%med > 0)
                {
                    count += 1; 
                }
            }
            if(count > h)
            {
                left = med + 1; 
            }
            else 
            {
                right = med; 
            }
        }
        return left; 
    }
};
