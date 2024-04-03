class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(board, i, j, 0, word)){
                    return true;
                }
            }
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i,int j, int k, string& word){
        //kth word
        if(k==word.size()){
            return true;
        }
        int m=board.size();
        int n=board[0].size();
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]!=word[k]){
            return false;
        }
        k++;
        char temp=board[i][j]; 
        board[i][j]='.'; // how we keep track of visited
        bool ans=dfs(board,i+1,j,k,word) || dfs(board,i-1,j,k,word) || dfs(board,i,j+1,k,word) || dfs(board,i,j-1,k,word);
        board[i][j]=temp;
        return ans;
    }
};