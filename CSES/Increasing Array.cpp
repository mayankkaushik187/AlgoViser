#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 10000007
int main()
{
    // added the two lines below
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    ll n;
    cin >> n;
 
    ll moves = 0;
    vector<ll> arr(n);
 
    for (ll i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (ll i = 1; i < n; i++)
    {
        if (arr[i] - arr[i - 1] < 0)
        {
            moves += arr[i - 1] - arr[i];
            arr[i] = arr[i - 1];
        }
    }
    cout << moves << "\n";
 
    return 0;
}
