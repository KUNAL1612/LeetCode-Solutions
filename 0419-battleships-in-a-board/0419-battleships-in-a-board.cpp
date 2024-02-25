class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = m ? board[0].size() : 0, battleships = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X') {
                    if ((!i || board[i - 1][j] == '.') && (!j || board[i][j - 1] == '.')) {
                        battleships++;
                    }
                }
            }
        }
        return battleships;
    }
};

// basically checking for top left ships and top left only