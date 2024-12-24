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
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for(auto& i: a) cin >> i;
    for(auto& i: b) cin >> i;
    sort(a, a + n);
    sort(b, b + m);
    int j = n - 1, ans{};
    for(int i{m - 1}; ~i; --i){
        while (j >= 0 && a[j] > b[i])--j;
        if(j >= 0){
            --j;
            ++ans;
        }
    }
    cout << ans;
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
