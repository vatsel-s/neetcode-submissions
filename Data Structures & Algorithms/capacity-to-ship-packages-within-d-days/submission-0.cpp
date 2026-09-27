class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //least possible weight to deliver them over in this many days
        //what's the maximum of the weight capacity that could be used
        //that's just going to be all of them summed up
        //the minimum is 0, or also the sum of weights/days
        int total_sum = 0; 
        int max_value = 0; 
        for(int i = 0; i < weights.size(); i++)
        {
            total_sum += weights[i]; 
            if(weights[i] > max_value)
            {
                max_value = weights[i]; 
            }
        }
        int left = max_value; 
        int right = total_sum; 
        while(left < right)
        {
            //now we have to simulate everything
            int med = (left + right)/2; 
            int day_count = 0; 
            int current_sum = 0; 
            for(int i = 0; i < weights.size(); i++)
            {
                if(current_sum + weights[i] > med)
                {
                    current_sum = 0; 
                    day_count++; 
                }
                current_sum += weights[i]; 
            }
            if(current_sum > 0)
            {
                day_count++; 
            }
            cout << med << " " << day_count << " " << left << " " << right << endl; 
            if(day_count <= days)
            {
                right = med; 
            }
            else
            {
                left = med + 1; 
            }
        }
        return left; 
    }
};