class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main() {
    Solution sol;
    sol.canWinNim(4);
}