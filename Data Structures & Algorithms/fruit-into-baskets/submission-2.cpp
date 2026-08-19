class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        //we want the max amount of fruit that can be picked across these two things
        //ideally, we want to make some sort of map, with a total count as well, we iterate through the array and then 
        //if we arrive to a new. fruit, what happens?, we have to include this new fruit and then the fruit which was taken most recently

        int first_fruit = fruits[0]; 
        int second_fruit = -1; 
        int last_first_ind = 0; 
        int last_second_ind = -1; 
        int count = 1; 
        int max_count = 1; 
        int start_ind = 1; 
        //let's go ahead and find the second fruit
        for(unsigned int i = 1; i < fruits.size(); i++)
        {
            if(fruits[i] != first_fruit)
            {
                second_fruit = fruits[i];
                start_ind = i;  
                last_second_ind = i; 
                break; 
            }
            else
            {
                count += 1; 
                last_first_ind = i; 
                if(count > max_count)
                {
                    max_count = count; 
                }
            }
        }
        if(second_fruit == -1)
        {
            return max_count; 
        }

        for(unsigned int i = start_ind; i < fruits.size(); i++)
        {
            if(fruits[i] == first_fruit || fruits[i] == second_fruit)
            {
                if(fruits[i] == first_fruit)
                {
                    last_first_ind = i; 
                }
                if(fruits[i] == second_fruit)
                {
                    last_second_ind = i; 
                }
            }
            else
            {
                count = i - min(last_first_ind, last_second_ind) - 1; 
                if(last_first_ind > last_second_ind)
                {
                    second_fruit = fruits[i]; 
                    last_second_ind = i; 
                }
                else
                {
                    first_fruit = fruits[i]; 
                    last_first_ind = i; 
                }
            }
            count += 1; 
            if(count > max_count)
            {
                max_count = count; 
            }
        }
        return max_count; 
    }
};