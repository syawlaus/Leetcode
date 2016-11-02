#include <frequently-used-code-snippets.h>

int COOR_A;
int COOR_B;
int COOR_C;
int COOR_D;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B);
        int area2 = (G - E) * (H - F);
        //int overlapArea = computeOverlapArea(A, B, C, D, E, F, G, H);
        int overlapArea = computeOverlapArea2(A, B, C, D, E, F, G, H);
        return area1 + area2 - overlapArea;
    }

private:
    int computeOverlapArea2(int A, int B, int C, int D, int E, int F, int G, int H) {
        int M = MAX_TWO(A, E);
        int N = MAX_TWO(B, F);
        int O = MIN_TWO(C, G);
        int P = MIN_TWO(D, H);

        if (M <= O && N <= P) {     // 是合法矩形
            return (O - M) * (P - N);
        }
        return 0;
    }

    int computeOverlapArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        // 把 ABCD 保存到全局变量里
        COOR_A = A;
        COOR_B = B;
        COOR_C = C;
        COOR_D = D;
        
        int M = 0;
        int N = 0;
        int O = 0;
        int P = 0;

        // 4
        if (isInArea4(E, F)) {
            // 4.2
            if (isInArea2(G, H)) {
                M = A;
                N = F;
                O = G;
                P = D;
            }
            // 4.3
            else if (isInArea3(G, H)) {
                M = A;
                N = F;
                O = C;
                P = D;
            }
            // 4.5
            else if (isInArea5(G, H)) {
                M = A;
                N = F;
                O = G;
                P = H;
            }
            // 4.6
            else if (isInArea6(G, H)) {
                M = A;
                N = F;
                O = C;
                P = H;
            }
        }
        // 5
        else if (isInArea5(E, F)) {
            // 5.2
            if (isInArea2(G, H)) {
                M = E;
                N = F;
                O = G;
                P = D;
            }
            // 5.3
            else if (isInArea3(G, H)) {
                M = E;
                N = F;
                O = C;
                P = D;
            }
            // 5.5
            else if (isInArea5(G, H)) {
                M = E;
                N = F;
                O = G;
                P = H;
            }
            // 5.6
            else if (isInArea6(G, H)) {
                M = E;
                N = F;
                O = C;
                P = H;
            }
        }
        // 7
        else if (isInArea7(E, F)) {
            // 7.2
            if (isInArea2(G, H)) {
                M = A;
                N = B;
                O = G;
                P = D;
            }
            // 7.3
            else if (isInArea3(G, H)) {
                M = A;
                N = B;
                O = C;
                P = D;
            }
            // 7.5
            else if (isInArea5(G, H)) {
                M = A;
                N = B;
                O = G;
                P = H;
            }
            // 7.6
            else if (isInArea6(G, H)) {
                M = A;
                N = B;
                O = C;
                P = H;
            }
        }
        // 8
        else if (isInArea8(E, F)) {
            // 8.2
            if (isInArea2(G, H)) {
                M = E;
                N = B;
                O = G;
                P = D;
            }
            // 8.3
            else if (isInArea3(G, H)) {
                M = E;
                N = B;
                O = C;
                P = D;
            }
            // 8.5
            else if (isInArea5(G, H)) {
                M = E;
                N = B;
                O = G;
                P = H;
            }
            // 8.6
            else if (isInArea6(G, H)) {
                M = E;
                N = B;
                O = C;
                P = H;
            }
        }

        return (O - M) * (P - N);
    }

    bool isInArea2(int x, int y) {
        return (COOR_A <= x && x <= COOR_C && COOR_D <= y);
    }

    bool isInArea3(int x, int y) {
        return (COOR_C <= x && COOR_D <= y);
    }

    bool isInArea4(int x, int y) {
        return (x <= COOR_A && COOR_B <= y && y <= COOR_D);
    }

    bool isInArea5(int x, int y) {
        return (COOR_A <= x && x <= COOR_C && COOR_B <= y && y <= COOR_D);
    }

    bool isInArea6(int x, int y) {
        return (COOR_C <= x && COOR_B <= y && y <= COOR_D);
    }
    
    bool isInArea7(int x, int y) {
        return (x <= COOR_A && y <= COOR_B);
    }

    bool isInArea8(int x, int y) {
        return (COOR_A <= x && x <= COOR_C && y <= COOR_B);
    }
};

int main() {
    Solution sol;
    cout << sol.computeArea(-3, 0, 3, 4, 0, -1, 9, 2) << endl;
    cout << sol.computeArea(0, 0, 0, 0, -1, -1, 1, 1) << endl;
    cout << sol.computeArea(-2, -2, 2, 2, -1, -1, 1, 1) << endl;
    cout << sol.computeArea(-2, -2, 2, 2, -3, -3, -1, -1) << endl;
}