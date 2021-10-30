//Leetcode 365
class Solution {
    public:
        int gcd(int a, int b) {
            while (b != 0) {
                int temp = b;
                b = a % b;
                a = temp;
            }
            return a;
        }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        //Since the target capacity should be there in the two jugs either by adding both of em or even when considering single jugs 
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        if (jug2Capacity == targetCapacity or jug1Capacity == targetCapacity or jug1Capacity + jug2Capacity == targetCapacity) return true;

        return targetCapacity % gcd(jug1Capacity, jug2Capacity) == 0;
    }
};
