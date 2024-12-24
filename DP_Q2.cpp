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


void solve(string s) {
    int n = (int)s.size();
    if(s.find('w') != -1 || s.find('m') != -1)
        return void(cout << "0\n");
    vector<int>dp(n + 1, -1);
    auto add = [&](int a, int b){
        int ret = a + b;
        if(ret >= mod)
            ret -= mod;
        return ret;
    };
    function<int(int)>rec = [&](int i){
        if(i == n) return 1;
        int& ret = dp[i];
        if(~ret) return ret;
        ret = rec(i + 1);
        if(i + 1 < n && s[i] == s[i + 1] && (s[i] == 'u' || s[i] == 'n'))
            ret = add(ret, rec(i + 2));
        return ret;
    };
    cout << rec(0) << ' ';
    vector<int>iterativeDp(n + 1);
    s = '#' + s;
    iterativeDp[0] = 1;
    for(int i{1}; i <= n; ++i){
        iterativeDp[i] = iterativeDp[i - 1];
        if(i > 1 && s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u'))
            iterativeDp[i] = add(iterativeDp[i], iterativeDp[i - 2]);
    }
    cout << iterativeDp.back() << '\n';
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
//    while (t--)
//        solve();
    string s;
    while (cin >> s) solve(s);
    return 0;
}
