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
    cin >> m >> n;
    vector<int>frq(26), lst(26, -n);
    for(int i{}; i < m; ++i){
        char c;
        cin >> c;
        ++frq[c - 'A'];
    }
    vector<int>v(26);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j){
       return frq[i] > frq[j];
    });
    // max ans <= n * m
    int ans{1}, cnt{};
    while (cnt < m){
        int nxt = -1;
        for(auto& c: v){
            if(!frq[c]) continue;
            if(ans - lst[c] > n){
                nxt = c;
                --frq[c];
                ++cnt;
                lst[c] = ans;
                break;
            }
        }
        if(~nxt)cout << char(nxt + 'A') << '\n';
        else cout << "Idle\n";
        ++ans;
    }
    cout << ans - 1;
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
