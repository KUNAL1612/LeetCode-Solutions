class Solution {
public:
    int flag[1000][1000];
bool findSolution(string s1,int i,string s2,int j,string s3,int k){
    if(!(s1[i] || s2[j] || s3[k]))
        return 1;
    if(!s3[k])
        return 0;
    if(flag[i][j]==-1)
        return 0;
    else if(flag[i][j]==1)
        return 1;
    else{
        
        int val;
        val = (( s1[i]==s3[k] && findSolution(s1,i+1,s2,j,s3,k+1)) || ( s2[j]==s3[k] && findSolution(s1,i,s2,j+1,s3,k+1)));
        if(val==0)
            flag[i][j]=-1;
        else
            flag[i][j]=1;
        //cout<<"Flag "<<flag<<endl;
        return val;
    }
}
bool isInterleave(string s1, string s2, string s3) {
   return findSolution(s1,0,s2,0,s3,0);
}
};