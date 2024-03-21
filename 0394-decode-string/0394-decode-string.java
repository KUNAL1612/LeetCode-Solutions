
class Solution {
    public String decodeString(String s) {
        Stack<String> sta = new Stack<>();
        sta.push("");
        Stack<Integer> repeat = new Stack<>();
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            if (Character.isAlphabetic(s.charAt(i))) {
                sta.push(sta.pop() + s.charAt(i));
            } else if (Character.isDigit(s.charAt(i))) {
                int num = 0;
                while (Character.isDigit(s.charAt(i))) {
                    num *= 10;
                    num += s.charAt(i) - '0';
                    ++i;
                }
                
                repeat.push(num);
                sta.push("");
            } else if (s.charAt(i) == ']') {
                int num = repeat.pop();
                String tmp = sta.pop();
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < num; ++j) {
                    sb.append(tmp);
                }
                sta.push(sta.pop() + sb.toString());
            }
        }
        return sta.pop();
    }
}
