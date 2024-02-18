class Solution {
private:
    std::vector<int> array;
    std::vector<int> original;
    std::mt19937 rand_gen; // Mersenne Twister random number generator

    int randRange(int min, int max) {
        std::uniform_int_distribution<int> distribution(min, max - 1);
        return distribution(rand_gen);
    }

    void swapAt(int i, int j) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

public:
    Solution(std::vector<int>& nums) : array(nums), original(nums), rand_gen(std::random_device{}()) {}

    std::vector<int> reset() {
        array = original;
        return original;
    }

    std::vector<int> shuffle() {
        for (int i = 0; i < array.size(); i++) {
            swapAt(i, randRange(i, array.size()));
        }
        return array;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */