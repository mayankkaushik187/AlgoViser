#include <iostream>
#include <vector>
using namespace std;

int water(vector<int> &v, int n)
{
    // 7 5 4 3 6
    int left = 0;
    int right = n - 1;
    int left_max = 0;
    int right_max = 0;
    int water = 0; // 1 2 3 4 1
    while (left < right)
    {
        left_max = max(left_max, v[left]);
        right_max = max(right_max, v[right]);
        if (left_max < right_max)
        {
            water += left_max - v[left];

            left++;
        }
        else
        {
            water += right_max - v[right];

            right--;
        }
    }
    return water;
}

int main()
{
    vector<int> v = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = v.size();
    cout << "The max water is " << water(v, n);
    return 0;
}