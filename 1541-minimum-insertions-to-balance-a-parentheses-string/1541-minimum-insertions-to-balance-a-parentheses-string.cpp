class Solution {
public:
        int minInsertions(string s) {
        int res = 0, right = 0;
        for (char &c: s) {
            if (c == '(') { //everytime we see an opening bracket, all open brackets before it needs to be closed
                if (right % 2 > 0) { // we already have right number of brackets requires, but if they are odd numbers, it means that I need another left bracket
                    right--;
                    res++;
                }
                right += 2; // this is for the current opening bracket
            } else { // closing bracket case
                right--; // we found a closing brakcet so no need to add this
                if (right < 0) { 
                    right += 2;
                    res++;
                }
            }
        }
        return right + res;
    }
};


// Example 1: Consider ((()(,n= 5 ,i=0,1...4
// i=0, we have ( it means we need two right parenthesis (they are in pair) so.. right+=2 => res =0, right =2
// i=1, again we have ( it means we need two right parenthesis (they are in pair) so.. right+=2 => res =0, right =4
// i=2, again we have ( it means we need two right parenthesis (they are in pair) so.. right+=2 => res =0, right =6
// i=3, we have ) we subtract one from right. so.. right-- => res =0, right =5
// i=4, we have ( but here right is odd so we need to make it even with right-- and increment res++ => res =1, right =4. Also, as we have got a left parenthesis then we need two right parenthesis (they are in pair) so.. right+=2 => res =1, right =6

// finally ans is res + right => 1 +6 == 7




