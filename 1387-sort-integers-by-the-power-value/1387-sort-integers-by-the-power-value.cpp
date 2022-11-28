class Solution {
public:
    int getKth(int lo, int hi, int k) {
        vector<int> power(1001, 0);
        power[2] = 1;
        power[3] = 7;
        power[5] = 5;
        
        for (int i=2; i<=500; i++) {
            if (power[i] != 0) {
                power[i*2] = power[i]+1;
            }
        }
        for (int i=lo; i<=hi; i++) {
            int p = 0;
            int j=i;
            while((j != 1) && ((j>1000) || (power[j] == 0))) {
                if (j%2 == 0) {
                    j /= 2;
                } else {
                    j = (j*3) + 1;
                }
                p++;
            }
            power[i] = p+power[j]; 
        }
        vector<pair<int,int>> powerAndValue;
        for (int i=lo; i<=hi; i++) {
            powerAndValue.push_back({power[i], i});
        }
        sort(begin(powerAndValue), end(powerAndValue));
        auto itr =  begin(powerAndValue)+k-1;
        return itr->second;
    }
};