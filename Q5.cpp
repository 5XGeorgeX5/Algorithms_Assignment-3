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
    vector<array<int,3>> edges(m);
    for(auto& e: edges) cin >> e[2] >> e[1] >> e[0];
    sort(edges.begin(), edges.end());

    vector<int>par(n + 1), size(n + 1, 1), cnt(m);
    iota(par.begin(), par.end(), 0);

    function<int(int)> find = [&](int u){
        if(u == par[u])
            return u;
        return par[u] = find(par[u]);
    };

    auto merge = [&](int u, int v){
        u = find(u);
        v = find(v);
        if(u == v)
            return false;
        if(size[u] < size[v])
            swap(u, v);
        size[u] += size[v];
        par[v] = u;
        return true;
    };
    vector<pair<int,int>>adj[n + 1];
    for(auto& e: edges){
        if(merge(e[1], e[2])){
            adj[e[2]].emplace_back(e[1], e[0]);
            adj[e[1]].emplace_back(e[2], e[0]);
        }
    }
    function<int(int, int)> dfs = [&](int u, int p){
        int c{1};
        for(auto& v: adj[u])if(v.first != p){
            int c2 = dfs(v.first, u);
            c += c2;
            cnt[v.second] += c2 * (n - c2);
        }
        return c;
    };
    dfs(1, -1);
    for(int i{}; ; ++i){
        if(i + 1 >= (int)cnt.size()){
            if(!cnt[i]) break;
            cnt.emplace_back();
        }
        cnt[i + 1] += cnt[i] >> 1;
        cnt[i] = cnt[i] & 1;
    }
    while (!cnt.empty() && !cnt.back()) cnt.pop_back();
    reverse(cnt.begin(), cnt.end());
    for(auto& i: cnt) cout << i;
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
