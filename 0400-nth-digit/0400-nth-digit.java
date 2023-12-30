import java.util.*;

class Solution {

    // 1-9       = 1  9
    // 10-99     = 2  90
    // 100-999   = 3  900
    // 1000-9999 = 4  9000

    // n = 5000
    // n -= 9 + 90*2 +900*3 -= 2889
    // n = 2111
    // 2111 / 4 = 527 skip
    // n = 2111 % 4 = 3
    // n = 3 at 1527  = 15(2)7 => ANS: 2

    public int findNthDigit(int n) {
        int len = 1;
        long count = 9;
        int start = 1;

        while (n > len * count) {
            n -= len * count;
            len += 1;
            count *= 10;
            start *= 10;
        }

        start += (n - 1) / len;
        String s = Integer.toString(start);
        return Character.getNumericValue(s.charAt((n - 1) % len));
    }


}