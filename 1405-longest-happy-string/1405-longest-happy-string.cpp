class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> pq;
        
        if(a > 0)
            pq.push({a, 'a'});
        if( b > 0)
            pq.push({b, 'b'});
        if(c > 0)
            pq.push({c, 'c'});
    
        char prev1 = '#';
        char prev2 = '#';
        
        while(!pq.empty())
        {
            auto [cnt1, ch1] = pq.top();
            pq.pop();
            if(ch1 == prev1 && ch1 == prev2)
            {
                // we need second most popular character
                if(pq.empty())
                {
                    return res;
                }
                auto [cnt2, ch2] = pq.top();
                pq.pop();
                prev1 = prev2;
                prev2 = ch2;
                res += ch2;
                if(--cnt2 > 0)
                {
                    pq.push(make_pair(cnt2,ch2));
                }
                pq.push(make_pair(cnt1,ch1));
            }
            else
            {
                prev1 = prev2;
                prev2 = ch1;
                res += ch1;
                if(--cnt1 > 0)
                {
                    pq.push(make_pair(cnt1,ch1));
                }
            }
        }
        return res;
    }
};