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
    ll g, s;
    cin >> g >> s;
    vector<array<int, 4>> edges(m);
    for (int i{}; i < m; ++i) {
        int u, v, gi, si;
        cin >> u >> v >> gi >> si;
        edges[i] = {gi, si, u, v};
    }
    sort(edges.begin(), edges.end());
    
    vector<int> par(n + 1), size(n + 1, 1);
    set<pair<int, int>> adj[n + 1];
    iota(par.begin(), par.end(), 0);
    int components = n;
    
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
        --components;
        return true;
    };
    
    ll ans = LLONG_MAX;
    multiset<int> Silvers;
    for (auto &edge: edges) {
        int gi = edge[0], si = edge[1], u = edge[2], v = edge[3];
        if (u == v) continue;
        
        if (merge(u, v)) {
            Silvers.emplace(si);
            adj[u].emplace(v, si);
            adj[v].emplace(u, si);
            if (components == 1) {
                ans = min(ans, *Silvers.rbegin() * s + gi * g);
            }
            continue;
        }
        
        multiset<array<int, 3>, greater<>> path;
        function<void(int, int)> dfs = [&](int a, int p) {
            if (a == v) {
                if ((*path.begin())[0] > si) {
                    int x = (*path.begin())[1];
                    int y = (*path.begin())[2];
                    int w = (*path.begin())[0];
                    adj[x].erase({y, w});
                    adj[y].erase({x, y});
                    adj[u].emplace(v, si);
                    adj[v].emplace(u, si);
                    Silvers.erase(Silvers.find(w));
                    Silvers.emplace(si);
                }
                return;
            }
            
            for (auto &edge: adj[a]) {
                if (edge.F == p) continue;
                path.insert({edge.second, edge.first, a});
                dfs(edge.first, a);
                path.erase({edge.second, edge.first, a});
            }
        };
        
        if (components == 1) {
            ans = min(ans, *Silvers.rbegin() * s + gi * g);
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
