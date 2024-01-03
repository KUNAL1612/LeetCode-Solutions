class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int maxLen = 0;
        vector<int> freq(26,0);
        
        for(int i=0, j=0; j<s.size(); j++)
        {
            freq[s[j]-'A']++; // taking current element
            while(!isValid(freq,k)) // more than k changes needed
            {
                freq[s[i++] - 'A']--; // freq is for current window only
            }// once we exit this loop, the window is valid
            maxLen = max(maxLen, j - i + 1); // now we can take max valid
        }
        return maxLen;
    }
    
    bool isValid(vector<int>& freq, int k)
    {
        int sum = 0;
        int maxFreq = 0;
        
        for(int i=0; i<26; i++)
        {
            sum += freq[i];
            maxFreq = max(maxFreq, freq[i]);
        }
        return sum - maxFreq <= k; // total number of characters in substring - freq of most popular charaacter in substring
    }
};
