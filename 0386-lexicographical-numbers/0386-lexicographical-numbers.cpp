class Solution {
public:
    vector<int> answer;
    int max_value;
    unordered_set<int> seen;
    void backtracking(int curr_num){
        if(curr_num>max_value || seen.find(curr_num)!=seen.end()){
            return;
        }
        seen.insert(curr_num);
        
        
        answer.push_back(curr_num);
        for(int i=0;i<=9;i++){
            backtracking(curr_num*10 + i);
        }
        
    }
    
    vector<int> lexicalOrder(int n) {
        max_value = n;
        for(int i=1;i<=9;i++){
            backtracking(i);
        }   
        return answer;
    }
};