class Solution
{
    public:
        int minTimeToType(string word)
        {
            int ans = word.size(), point = 'a';
            for (auto x: word)
            {
                ans += min(abs(x - point), 26 - abs(point - x));
                point = x;
            }
            return ans;
        }
};