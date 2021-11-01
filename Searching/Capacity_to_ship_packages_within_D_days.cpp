//Leetcode 1011
bool isFeasible(vector < int > & weights, int mid, int days) {
    int k = 1;
    int sum = 0;
    for (int i = 0; i < weights.size(); i++) {
        if (sum + weights[i] > mid) {
            sum = 0;
            k++;
        }
        sum += weights[i];
    }
    if (k <= days) return true;
    else return false;
}
int shipWithinDays(vector < int > & weights, int days) {
    int maxm = * max_element(weights.begin(), weights.end());
    int sum = 0;
    for (int i: weights) sum += i;
    int i = maxm;
    int j = sum;
    while (i < j) {
        int mid = (i + j) >> 1;
        if (isFeasible(weights, mid, days)) {
            j = mid;
        } else {
            i = mid + 1;
        }
    }
    return j;
}
