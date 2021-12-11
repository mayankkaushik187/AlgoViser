class Solution {
public:
    const int mod = 1e9 + 7;
    int nthMagicalNumber(int N, int A, int B) {
        long LCM = lcm(A, B), L = min(A, B), R = N*L, mid, ans;
        auto magicNumbersLessEqual = [&](long x) { return (x/A) + (x/B) - (x/LCM); };
        while(L <= R) {
            mid = L + (R-L) / 2;
            if(magicNumbersLessEqual(mid) < N) L = mid + 1;   // magical numbers <= mid are less than required, so discard search space to left of mid
            else R = mid - 1, ans = mid;                      // mark mid as the potential answer & search in [L, mid-1]
        }
        return ans % mod;
        
    }
};
