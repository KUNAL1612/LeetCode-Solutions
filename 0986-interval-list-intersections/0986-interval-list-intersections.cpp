class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int lenA=A.size();   
        int lenB=B.size();
        if(lenA==0 || lenB==0){
            return ans;
        }
        int i=0;
        int j=0;
        while(i<lenA && j<lenB){
            int low=max(A[i][0],B[j][0]);
            int hi=min(A[i][1],B[j][1]);
            if(low<=hi){
                // add code here to check if this intersection has anything common with previous interesection. If so, byump both of those by 1
                vector<int> newa{low,hi};
                ans.push_back(newa);
            }
            if(A[i][1]<B[j][1]){
                i++;
            }
            else{
                j++;
            }
            
        }
        return ans;
    }
};


//