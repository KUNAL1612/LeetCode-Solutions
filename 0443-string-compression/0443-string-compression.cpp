class Solution {
public:
    int compress(vector<char>& chars) {
        int c = 1, index = 1, n = chars.size();
        for(int i=0; i<n; i++)
        {
            if (i == n-1 || chars[i] != chars[i+1]) // char changes
            {
                if (c!=1)
                {
                    auto cs = std::to_string(c);
                    for(int i=0; i<cs.size(); i++)
                        chars[index++] = cs[i];
                }
                if (i != n-1)
                    chars[index++] = chars[i+1];
                c = 1;
            }
            else
                c++;
        }
        return index;
    }
};