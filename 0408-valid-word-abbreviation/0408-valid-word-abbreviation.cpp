class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int posWord = 0, posAbbr = 0, temp = 0;
        // posWord and posAbbr are the two pointers on the two strings
        while(posWord < word.size() && posAbbr < abbr.size()) {
            while(posWord < word.size() && posAbbr < abbr.size() &&
                  isalpha(word[posWord]) && isalpha(abbr[posAbbr])) {
                if(word[posWord] != abbr[posAbbr]) // comparing the positions at posWord and posAbbr from the two strings
                    return false;
                ++posWord, ++posAbbr;
            }
            while(posAbbr < abbr.size() && isdigit(abbr[posAbbr])) {
                if(abbr[posAbbr] == '0' && (posAbbr == 0 || not isdigit(abbr[posAbbr - 1])))
                    return false;
                temp = temp * 10 + abbr[posAbbr] - '0';
                ++posAbbr;
            }
            if(temp > word.size() - posWord) return false; // we are moving it further than we can
            else posWord += temp; // this is the odd scenario where
            temp = 0;
        }
        return posWord == word.size() && posAbbr == abbr.size();
    }
};
