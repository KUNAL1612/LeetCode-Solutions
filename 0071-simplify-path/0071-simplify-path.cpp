class Solution {
public:
    string simplifyPath(string path) {
        deque<string> q1;
        istringstream pss(path);
        vector<string> commands;
        string p;
        while(getline(pss,p,'/')){
            commands.push_back(p);
        }
        
        for(auto command:commands){
            if(command.size()!=0){
                if(command==".."){
                    if(!q1.empty()){
                        q1.pop_back();    
                    }
                }
                else if (command=="."){
                    continue;
                }
                else{
                    q1.push_back(command);
                }
            }
        }
        
        string ans;
        
        while(!q1.empty()){
            ans+='/';    
            ans+=q1.front();
            q1.pop_front();
        }
        
        return ans.size()==0?"/":ans;
    }
};

   