#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> revArr1(vector<int> &v, int n)
{
    //using  for loop
    for (int i = n - 1, j = 0; i >= 0 && i >= n / 2; i--, j++)
    {
        swap(v[i], v[j]);
    }
    return v;
}
vector<int> revArr2(vector<int> &v, int n)
{
    //using  while loop
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        swap(v[start], v[end]);
        start++;
        end--;
    }
    return v;
}

int main()
{

    vector<int> v = {1, 2, 4, 5, 6, 7};
    int n = v.size();

    v = revArr2(v, n);
    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    return 0;
}

//   j        //i
// 1  3  5  7  3
// 1  3  5  7  3  7

//o/p==> 3  7  5  3  1