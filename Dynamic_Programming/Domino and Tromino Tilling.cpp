class Solution {
public:
 // Creds : YehudisK Leetcode
  /*
    In any iteration, our empty slots in the board can look in two ways:
Either it's a full rectangle or it's a rectangle with one more square sticking out.

We define two functions:
D[i] = The number of ways to fill a full rectangle in the size of i * 2.
T[i] = The number of ways to fill a rectangle of size i * 2 + one square sticking out.

D[i]:
We have a rectangle.
We have 3 options:

put one domino vertically on the side, leaving us with a full rectangle of size i-1 - D[i-1].
put two dominoes on the side, leaving us with a full rectangle of size i-2 - D[i-2].
Put a tromino on the side - leaving us with a rectangle of size i-2 plus another sticking out square - T[i-2].
There are two directions to put the tromino, so we have 2 * T[i-2].
Conclusion - D[i] = D[i-1] + D[1-2] + 2 * T[i-2].

T[i]:
We have a rectangle with a square sticking out, it doesn't matter if on the top row or bottom.
We have two options:

Put a domino horizontally in the sticking out square, leaving us again with a sticking out square on the other row - T[i-1].
Put a tromino completing the extra square, leaving us with a full rectangle - D[i-1].
Conclusion - T[i] = T[i-1] + D[i-1].
  
  */
    int numTilings(int n) {
        if (n < 3) return n;
        
        int mod = pow(10, 9) + 7;
        vector<long> D(n+1, 0), T(n+1, 0);
        D[0] = 0, D[1] = 1, D[2] = 2;
        T[0] = 0, T[1] = 1, T[2] = 2;
        
        for (int i = 3; i <= n; i++) {
            D[i] = (D[i-1] + D[i-2] + 2*T[i-2]) % mod;
            T[i] = (T[i-1] + D[i-1]) % mod;
        }
        
        return D[n];
    }
};
