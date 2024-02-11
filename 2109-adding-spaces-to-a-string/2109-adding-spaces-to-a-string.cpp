class Solution {
public:
    
    string addSpaces( string& s,  vector<int>& spaces) {
    // Create a new string to store the result
    string result;
    
    // Initialize a pointer to keep track of the current index in the original string
    int ptr = 0;
    
    // Iterate through each character in the original string
    for (int i = 0; i < s.length(); ++i) {
        // Check if the current index matches any of the indices in the spaces array
        if (ptr < spaces.size() && i == spaces[ptr]) {
            // Add a space before the current character
            result += ' ';
            // Increment the pointer to move to the next index in the spaces array
            ptr++;
        }
        // Add the current character to the result string
        result += s[i];
    }
    
    // If there are remaining indices in the spaces array, add spaces to the end of the string
    while (ptr < spaces.size()) {
        result += ' ';
        ptr++;
    }
    
    // Return the modified string with spaces added
    return result;
}
};