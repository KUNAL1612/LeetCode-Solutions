class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count_zeros = 0;
        int count_ones  = 0;
        for(auto student:students){
            student == 0? count_zeros++ : count_ones++;
        }
        for(auto sandwich:sandwiches){
            //can someone eat this sandwich
            if(sandwich == 0){
                if(count_zeros>0){
                    count_zeros--;
                    continue;
                }
                else{
                    break;
                }
            }
            else{
                if(count_ones>0){
                    count_ones--;
                    continue;
                }
                else{
                    break;
                }
            }
        }
        return count_zeros + count_ones;
    }
};