#include <iostream>
using namespace std;
//ss = segment start , se = segment end , si = root node
int CST(int ss, int se, int si, int arr[], int tree[])
{
    if (ss = se)
    {
        tree[si] = arr[ss];
        return arr[ss];
    }

    int mid = ss + (se - ss) / 2;
    int nodeVal = CST(ss, mid, 2 * si + 1, arr, tree) + CST(mid + 1, se, 2 * si + 2, arr, tree);
    tree[si] = nodeVal;
    return tree[si];
}

int main()
{
    int arr[] = {10, 20, 30, 40}, n = 4;

    int tree[4 * n];
    cout << CST(0, n - 1, 0, arr, tree) << endl;

    return 0;
}