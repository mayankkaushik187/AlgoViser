#include <iostream>
#include <vector>
using namespace std;

void freq_in_an_array(vector<int> &v, int n)
{
    int freq = 1;
    int i = 1;

    while (i < n)
    {
        while (i < n && v[i] == v[i - 1])
        {
            freq++;
            i++;
        }
        cout << v[i - 1] << " " << freq << endl;
        i++;
        freq = 1;
    }
    if (n == 1 || v[n - 1] != v[n - 2])
    {
        cout << v[n - 1] << " " << 1 << endl;
    }
}

int main()
{
    vector<int> v = {40, 40, 40, 50, 50};
    int n = v.size();
    freq_in_an_array(v, n);
    return 0;
}