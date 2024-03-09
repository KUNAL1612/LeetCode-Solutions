class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        
        stack<int>st;
        vector<int>result;
        
        for(int i=heights.size()-1;i>=0;i--)
        {
            int count=0;
            while(st.size()&&heights[st.top()]<heights[i])
            {
                st.pop();
                count++;
            }
            int ans=count+(st.size()>0);
            
            result.push_back(ans);
            st.push(i);
        }
        
        reverse(result.begin(),result.end());
        return result;        
    }
};