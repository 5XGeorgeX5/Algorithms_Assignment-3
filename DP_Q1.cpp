#include <bits/stdc++.h>

#define ll long long
#define all(s) s.begin(), s.end()
#define rall(s) s.rbegin(), s.rend()
#define sz(s) (int)s.size()
#define F first
#define S second
#define ones(x) __builtin_popcountll(x)
#define ld  double

using namespace std;
const ll nx = 2e3 + 22, oo = 1e18;
const int mod = 1e9 + 7, N = 2e5 + 13;


void solve() {
    int n;
    cin >> n;
    bitset<500 * 100 + 1>dp;
    dp.set(0);
    int sum{};
    while (n--){
        int a;
        cin >> a;
        sum += a;
        dp |= (dp << a);
    }
    int ans = INT_MAX;
    for(int i{}; i < sum; ++i){
        if(dp[i])
            ans = min(ans, abs(sum - 2 * i));
    }
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
