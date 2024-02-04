class Solution {
public:
    unordered_map<string, set<string>> adj;
    
    void dfs(unordered_set<string>& visited, string email, vector<string>& emails)
    {
        if (visited.find(email) != visited.end())
            return;
        
        visited.insert(email);
        emails.push_back(email);
        
        // Do DFS with all the possible edges. Create clusters of linked emails (linked aka with same names).
        int relatedEmailsCount = adj[email].size();
        
        // Visit all the neighbors using the emails set
        for (auto iter = adj[email].begin(); iter != adj[email].end(); ++iter)
            dfs(visited, *iter, emails);        
    }
	
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) 
    {
        unordered_map<string, string> emailToNameMap;
        vector<vector<string>> result;
        
        // Build adjacency matrix with mail ids
        int accountsSize = accounts.size();
        
        for (int i = 0; i < accountsSize; ++i)
        {
            int mailsCount = accounts[i].size();
            for (int j = 1; j < mailsCount; ++j)
            {
                // add edges (if i == j self edge)
                adj[accounts[i][1]].insert(accounts[i][j]);
                adj[accounts[i][j]].insert(accounts[i][1]);
                
                // add name to the map of email to name 
                emailToNameMap[accounts[i][j]] = accounts[i][0];
           }
        }
        
        unordered_set<string> visited;
        for (int i = 0; i < accountsSize; ++i) 
        {
            int mailsCount = accounts[i].size();
            for (int j = 1; j < mailsCount; ++j)
                if (visited.find(accounts[i][j]) == visited.end())
                {
                    // Do DFS to find all the related emails of a person
                    vector<string> emails;
                    dfs(visited, accounts[i][j], emails);
                    
                    // sort the emails
                    sort(emails.begin(), emails.end());
                    
                    // Add the account name to the beginning of the emails list
                    emails.insert(emails.begin(), emailToNameMap[accounts[i][j]]);
                    
                    // Push the account to the result
                    result.push_back(emails);
                }
        }
    
        return result;
    }
};