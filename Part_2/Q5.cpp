#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto &e : edges)
        cin >> e[2] >> e[1] >> e[0];
    sort(edges.begin(), edges.end());

    vector<int> parent(n + 1), size(n + 1, 1), count(m);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int u)
    {
        if (u == parent[u])
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
        return true;
    };
    vector<pair<int, int>> adj[n + 1];
    for (auto &e : edges)
    {
        if (merge(e[1], e[2]))
        {
            adj[e[2]].emplace_back(e[1], e[0]);
            adj[e[1]].emplace_back(e[2], e[0]);
        }
    }
    function<int(int, int)> dfs = [&](int u, int p)
    {
        int c{1};
        for (auto &v : adj[u])
            if (v.first != p)
            {
                int c2 = dfs(v.first, u);
                c += c2;
                count[v.second] += c2 * (n - c2);
            }
        return c;
    };
    dfs(1, -1);
    for (int i = 0;; ++i)
    {
        if (i + 1 >= (int)count.size())
        {
            if (!count[i])
                break;
            count.emplace_back();
        }
        count[i + 1] += count[i] >> 1;
        count[i] = count[i] & 1;
    }
    while (!count.empty() && !count.back())
        count.pop_back();
    reverse(count.begin(), count.end());
    for (auto &i : count)
        cout << i;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
