class Solution {
public:
    bool static comp(pair<int,double>&a, pair<int,double>&b)
    {
        return a.first > b.first;
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
    
        vector<pair<int,double>> vec;

        for(int i=0; i<position.size(); i++)
        {
            double tmp = (double)(target-position[i]) /speed[i];

            vec.push_back({position[i], tmp});
        }

        sort(vec.begin(), vec.end(), comp);
        
        

        double time = 0, res = 0;

        for(auto x: vec)
        {
            if(x.second > time)
            {
                time = x.second;
                res++;
            }
        }

        return res;

    }
};