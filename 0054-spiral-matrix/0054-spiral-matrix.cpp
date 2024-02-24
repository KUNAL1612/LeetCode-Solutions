class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
		// return empty vector if passed matrix is empty
        if(matrix.empty())
            return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> v;
        int count = m*n;
		// initialize boundaries
        int left = 0, right = n-1, top = 0, bottom = m-1, i, j;
		// since there are only 'count' elements so whenever the remaining number of elements
		// become 0, break out from the complete loop or return the processed vector
        while(count > 0)
        {
			// for top row traversal from left to right
            for(j = left; j <= right; ++j)
            {
                v.push_back(matrix[top][j]);
                count--;
                if(count == 0)
                    return v;
            }
            right--;
            j -= 2;
			
			// for right most column traversal from top to bottom
            for(i = top+1; i <= bottom; ++i)
            {
                v.push_back(matrix[i][right+1]);
                count--;
                if(count == 0)
                    return v;
            }
            bottom--;
            i -= 2;
			
			// for bottom row traversal from right to left
            for(; j >= left; --j)
            {
                v.push_back(matrix[bottom+1][j]);
                count--;
                if(!count)
                    return v;
            }
            left++;
			
			// for left most column traversal from bottom to top
            for(; i > top; --i)
            {
                v.push_back(matrix[i][left-1]);
                count--;
                if(!count)
                    return v;
            }
            top++;
        }
        return v;
    }
};