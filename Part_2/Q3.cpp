#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> parent(n + 1), size(n + 1, 1);
    iota(parent.begin(), parent.end(), 0);

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
        return true;
    };
    // suppose m is the number of edges;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        ++u, ++v;
        merge(u, v);
    }
    int a, b;
    cin >> a >> b;
    ++a, ++b;
    if (find(a) == find(b))
        cout << "true\n";
    else
        cout << "false\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
