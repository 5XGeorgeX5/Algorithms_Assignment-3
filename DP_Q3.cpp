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
    int k, m;
    cin >> k >> m;
    vector<vector<int>> dp(2, vector<int>(k + 1));
    for (int i{}; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        for (int j{}; j <= k; ++j) {
            dp[i & 1][j] = max(dp[i & 1][j], dp[!(i & 1)][j]);
            if(j + a <= k)
                dp[i & 1][j + a] = max(dp[i & 1][j + a], dp[!(i & 1)][j] + b);
        }
        dp[!(i & 1)].assign(k + 1, 0);
    }
    cout << "Hey stupid robber, you can get ";
    cout << *max_element(dp[!(m & 1)].begin(), dp[!(m & 1)].end()) << '\n';
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
