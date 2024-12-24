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

int dp[31][31][1003];

void solve() {
    int t, w;
    cin >> t >> w;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &i: v) cin >> i.first >> i.second;
    for (int i{}; i <= n; ++i)
        for (int j{}; j <= n; ++j)
            for (int k{}; k <= t; ++k)
                dp[i][j][k] = -1;
    v.emplace_back(0, 0);
    function<int(int, int, int)> rec = [&](int i, int lst, int rem) -> int {
        if (i == n)
            return 0;
        auto &ret = dp[i][lst][rem];
        if (~ret)
            return ret;
        ret = rec(i + 1, lst, rem);
        int cost = 3 * w * v[i].first;
        if (cost <= rem)
            ret = max(ret, rec(i + 1, i, rem - cost) + v[i].second);
        return ret;
    };
    cout << rec(0, n, t) << '\n';
    vector<pair<int,int>>ans;
    function<void(int, int, int)> build = [&](int i, int lst, int rem){
        if(i == n)
            return;
        int optimal = rec(i, lst, rem);
        if(optimal == rec(i + 1, lst, rem)){
            build(i + 1, lst, rem);
            return;
        }
        int cost = 3 * w * v[i].first;
        if(cost <= rem && rec(i + 1, i, rem - cost) + v[i].second == optimal){
            ans.emplace_back(v[i]);
            build(i + 1, i, rem - cost);
        }
    };
    build(0, n, t);
    cout << ans.size() << '\n';
    for(auto& i: ans){
        cout << i.first << ' ' << i.second << '\n';
    }
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
//    cin >> t;
    while (t--)
        solve();
    return 0;
}
