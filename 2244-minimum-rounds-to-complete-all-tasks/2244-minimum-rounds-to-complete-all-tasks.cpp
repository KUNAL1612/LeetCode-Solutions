class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> counts;
        for(auto task:tasks){
            counts[task]++;
        }
        
        int result = 0;
        int remaining_tasks = tasks.size();
        for(auto elem:counts){
            if(elem.second == 1){
                return -1;
            }
            if(elem.second%3 == 0){
                result += elem.second/3;
                
            }
            else if(elem.second%3 == 1){
                result += (elem.second - 1)/3 ;
                result++;
            }
            else if(elem.second%3 == 2){
                result += elem.second/3;
                result++;
            }
            
        }
        return result;
    }
};