class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        
        vector<vector<string>>res;
        int n = transactions.size();
        
        for (int i = 0; i < n; i++) {
            stringstream ss(transactions[i]);
            string str;
            vector<string>v;
            while (getline(ss, str, ','))
                v.push_back(str);
            res.push_back(v);
        }
        
        vector<bool>store(n, false);
        for (int i = 0; i < n; i++) {
            if (stoi(res[i][2]) > 1000)
                store[i] = true;
            for (int j = i+1; j < n; j++) {
                if (res[i][0] == res[j][0] && res[i][3] != res[j][3]
                            && abs(stoi(res[i][1])-stoi(res[j][1])) <= 60) { //O(n^2) to check for all transactions after this. If set to true already no need to check I guess.
                    store[i] = true;
                    store[j] = true;
                }
            }
        }
        
        vector<string>ans;
        for (int i = 0; i < n; i++)
            if (store[i]) // to store this transaction 
                ans.push_back(transactions[i]);
        
        return ans;
    }
};