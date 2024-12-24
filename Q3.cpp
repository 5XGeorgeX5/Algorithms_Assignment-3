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


int solve() {
    int n, m;
    cin >> n >> m;

    vector<int> par(n + 1), size(n + 1, 1);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int u) {
        if (par[u] == u) return u;
        return par[u] = find(par[u]);
    };

    auto merge = [&](int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (size[u] < size[v])
            swap(u, v);
        size[u] += size[v];
        par[v] = u;
        return true;
    };
    // suppose m is the number of edges;
    while (m--) {
        int u, v;
        cin >> u >> v;
        ++u,++v;
        merge(u, v);
    }
    int a, b;
    cin >> a >> b;
    ++a, ++b;
    return find(a) == find(b);
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
        cout << solve();
    return 0;
}
