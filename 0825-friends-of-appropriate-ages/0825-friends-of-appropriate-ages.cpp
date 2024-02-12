// class Solution {

// public:
//     int numFriendRequests(vector<int>& ages) {
//         sort(ages.begin(), ages.end());
//         int n = ages.size(), count = 0;
//         for (int i = n - 1; i >= 0; i--) {
//             int val = 0.5 * ages[i] + 7; // this is the treshold of age that will send a friend request to ages[i]
//             int index = upper_bound(ages.begin(), ages.end(), val) - ages.begin();
//             int count_of_indices_with_same_age_as_currrent = 1, prev = i;
//             while (i - 1 >= 0 && ages[i] == ages[i - 1]) {
//                 // if there are multiple of the same ages, then we 
//                 c++;
//                 i--;
//             }
//             if (index >= prev) continue;
//             count += (prev - index) * c;
//         }
//         return count;
//     }
// };


// class Solution {
// public:
//     int numFriendRequests(std::vector<int>& ages) {
//         int requests = 0;
//         std::unordered_map<int, int> ageCounts;
//         for (int age : ages) {
//             ageCounts[age]++;
//         }

//         std::vector<int> ageCountSums(121, 0);
//         for (int i = 1; i <= 120; ++i) {
//             ageCountSums[i] = ageCountSums[i - 1] + ageCounts[i]; // cumulative sum
//         }

//         for (int i = 15; i <= 120; ++i) {
//             requests += (ageCounts[i] * (ageCountSums[i - 1] - ageCountSums[i / 2 + 7]) 
//                         + ageCounts[i] * (ageCounts[i] - 1));
//         }
        
//         return requests;
//     }
// };



// I guess in theory the following is constant time, so is at least objectively better. But in a weird scenario where the ages have a greater range than 1 to 121, it would not scale well

class Solution {
public:
    bool isPossible(int x,int y) {
        if((y <= 0.5*x + 7) || (y > x) || (y > 100 && x < 100))
            return false;
        return true;
    }
    int numFriendRequests(vector<int>& ages) {
        vector<int> mp(121,0);
        for(int i = 0;i < ages.size();i++)
            mp[ages[i]]++;

        int ans = 0;
        for(int i = 1;i < 121;i++) {
            if(mp[i] == 0)
                continue;
            for(int j = 1;j < 121;j++) {
                if(isPossible(i,j)) {
                    if(i == j)
                        ans += mp[i]*(mp[i] - 1); // if they are the same then just multiply with i-1
                    else
                        ans += mp[i]*mp[j];
                }
            }
        }
        return ans;
    }
};





// n log n 
// split the array into pre 100 and post 100
