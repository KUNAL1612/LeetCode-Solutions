// class Solution {
// public:
//     // int evaluate(char operation, int x, int y){
//     //     if(operation == '+')
//     // }
//     int calculateHelper(string s, int& index) {
//         if(index==s.size()){
//             return 0;
//         }
//         stack<int> st;
//         // int length = s.length();
//         // if (length == 0) return 0;
//         int currentNumber = 0, result = 0;
//         char sign = '+';
//         while(index<s.size() && s[index]!=')'){
//             char currentChar = s[index];
//             if(currentChar == '('){
//                 currentNumber = calculateHelper(s, index+1);
//             }
//             else if (isdigit(currentChar)) {
//                 currentNumber = (currentNumber * 10) + (currentChar - '0');
//             }
//             else if (!isdigit(currentChar) && !iswspace(currentChar) || i == length - 1) {
//                 if (sign == '+' || sign == '-') {
//                     lastNumber = (sign == '+') ? st.push(currentNumber) : -currentNumber;
//                 } else if (sign == '*') {
//                     int temp = st.top();
//                     st.pop();
//                     st.push(temp*currNum)
//                 } else if (sign == '/') {
//                     int temp = st.top();
//                     st.pop();
//                     st.push(temp*currNum)
//                 }
//                 sign = currentChar;
//                 currentNumber = 0;
//             }
//             index++;
//         }
        
//         while(!st.empty()){
//             result+=st.top();
//             st.pop();
//         }
        
//         return result;
//     }
//     int calculate(string s) {
//         return calculateHelper(s, 0)
//     }
// };


class Solution {
private:
    int evaluate(char op, int x, int y) {
        if (op == '+') {
            return x ;
        } else if (op == '-') {
            return -x ;
        } else if (op == '*') {
            return x * y;
        }
        
        return x / y;
    }
    
    int solve(std::string& s, int& i) {
        std::stack<int> stack;
        int curr = 0;
        char previousOperator = '+';
        
        while (i < s.length()) {
            char c = s[i];
            if (c == '(') {
                i++;
                curr = solve(s, i);
            } else if (std::isdigit(c)) {
                curr = curr * 10 + (c - '0');
            } else {
                if (previousOperator == '*' || previousOperator == '/') {
                    int temp = stack.top();
                    stack.pop();
                    stack.push(evaluate(previousOperator, temp, curr));
                    
                } else {
                    stack.push(evaluate(previousOperator, curr, 0));
                }
                
                if (c == ')') {
                    break;
                }
                
                curr = 0;
                previousOperator = c;
            }
            
            i++;
        }
        
        int ans = 0;
        while (!stack.empty()) {
            ans += stack.top();
            stack.pop();
        }
        
        return ans;
    }
    
public:
    int calculate(std::string s) {
        s += '@'; // Adding a delimiter at the end to indicate the end of the string
        int i = 0;
        return solve(s, i);
    }
};