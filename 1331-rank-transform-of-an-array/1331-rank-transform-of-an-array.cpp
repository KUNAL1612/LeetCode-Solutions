class Solution {
public:
//     vector<int> arrayRankTransform(vector<int>& arr) {
//         vector<int>ans;
//         set<int>st;
//         unordered_map<int,int>m;
//         for(auto x:arr)
//             st.insert(x);

//         int c=0;
//         for(auto x:st)
//         {
//             c++;
//             m[x]=c;
//         }    
//         for(auto x:arr)
//             ans.push_back(m[x]);

//          return ans;   

//     }
    
    
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sortedArr(arr.begin(), arr.end());
        sort(sortedArr.begin(), sortedArr.end());
        map<int, int> rankMap;
        int rank = 1;
        for (int num : sortedArr) {
            if (rankMap.find(num) == rankMap.end()) {
                rankMap[num] = rank++;
            }
        }
        vector<int> result;
        for (int num : arr) {
            result.push_back(rankMap[num]);
        }
        return result;
    }
};

//The rank of each element is the number of elements smaller than it in the sorted array plus one. -> binary search 
// use a different array to sort into. 