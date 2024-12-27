#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    long long g, s;
    cin >> g >> s;
    vector<array<int, 4>> edges(m);
    for (int i = 0; i < m; ++i)
    {
        int u, v, gi, si;
        cin >> u >> v >> gi >> si;
        edges[i] = {gi, si, u, v};
    }
    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1), size(n + 1, 1);
    set<pair<int, int>> adj[n + 1];
    iota(parent.begin(), parent.end(), 0);
    int components = n;

    function<int(int)> find = [&](int u)
    {
        if (parent[u] == u)
            return u;
        return parent[u] = find(parent[u]);
    };

    auto merge = [&](int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return false;
        if (size[u] < size[v])
            swap(u, v);
        size[u] += size[v];
        parent[v] = u;
        --components;
        return true;
    };

    long long ans = LLONG_MAX;
    multiset<int> Silvers;
    for (auto &edge : edges)
    {
        int gi = edge[0], si = edge[1], u = edge[2], v = edge[3];
        if (u == v)
            continue;

        if (merge(u, v))
        {
            Silvers.emplace(si);
            adj[u].emplace(v, si);
            adj[v].emplace(u, si);
            if (components == 1)
            {
                ans = min(ans, *Silvers.rbegin() * s + gi * g);
            }
            continue;
        }

        multiset<array<int, 3>, greater<>> path;
        function<void(int, int)> dfs = [&](int a, int p)
        {
            if (a == v)
            {
                if ((*path.begin())[0] > si)
                {
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

            for (auto &edge : adj[a])
            {
                if (edge.first == p)
                    continue;
                path.insert({edge.second, edge.first, a});
                dfs(edge.first, a);
                path.erase({edge.second, edge.first, a});
            }
        };

        if (components == 1)
        {
            ans = min(ans, *Silvers.rbegin() * s + gi * g);
        }
    }
    cout << ans;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
