#include <bits/stdc++.h>
using namespace std;

int dp[31][1003];

void solve()
{
    int t, w;
    cin >> t >> w;
    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    for (auto &i : v)
        cin >> i.first >> i.second;
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= t; ++j)
            dp[i][j] = -1;

    function<int(int, int)> getMax = [&](int i, int rem) -> int
    {
        if (i == n)
            return 0;
        auto &ret = dp[i][rem];
        if (~ret)
            return ret;
        ret = getMax(i + 1, rem);
        int cost = 3 * w * v[i].first;
        if (cost <= rem)
            ret = max(ret, getMax(i + 1, rem - cost) + v[i].second);
        return ret;
    };
    cout << getMax(0, t) << '\n';
    vector<pair<int, int>> ans;
    function<void(int, int)> build = [&](int i, int rem)
    {
        if (i == n)
            return;
        int optimal = getMax(i, rem);
        if (optimal == getMax(i + 1, rem))
        {
            build(i + 1, rem);
            return;
        }
        int cost = 3 * w * v[i].first;
        if (cost <= rem && getMax(i + 1, rem - cost) + v[i].second == optimal)
        {
            ans.emplace_back(v[i]);
            build(i + 1, rem - cost);
        }
    };
    build(0, t);
    cout << ans.size() << '\n';
    for (auto &i : ans)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
