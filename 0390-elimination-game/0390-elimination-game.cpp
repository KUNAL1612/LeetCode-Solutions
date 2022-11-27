class Solution {
public:
    // at every step, we look at 2^k furhter than the head
    int lastRemaining(int n) {
        int head = 1, incre = 1;
        bool left = true;
        while(n>1){
            if(left) head += incre;
            else{
                if(n%2 == 1) head += incre; // if even number, then element after head will be deleted but it would stay
            }
            left = !left;
            incre *= 2; // always moving left by 2^k at kth move
            n/=2;
        }
        return head;
    }
};