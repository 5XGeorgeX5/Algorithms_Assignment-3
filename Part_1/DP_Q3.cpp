#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int maxWeight, m;
    cin >> maxWeight >> m;
    vector<vector<int>> dp(2, vector<int>(maxWeight + 1));
    for (int i = 0; i < m; ++i)
    {
        int last = i & 1;
        int weight, value;
        cin >> weight >> value;
        for (int j = 0; j <= maxWeight; ++j)
        {
            dp[last][j] = max(dp[last][j], dp[!last][j]);
            if (j + weight <= maxWeight)
                dp[i & 1][j + weight] = max(dp[i & 1][j + weight], dp[!last][j] + value);
        }
        dp[!last].assign(maxWeight + 1, 0);
    }
    cout << "Hey stupid robber, you can get ";
    cout << *max_element(dp[!(m & 1)].begin(), dp[!(m & 1)].end()) << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
