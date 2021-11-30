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
    vector<ll> arr(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> arr[i];
    }
    ll sumAct = (n * (n + 1)) / 2;
 
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        sum += arr[i];
    }
 
    cout << sumAct - sum << endl;
 
    return 0;
}
