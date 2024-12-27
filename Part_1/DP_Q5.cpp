#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int dp[11];
    int a[n];
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = i - 1; j >= 0; --j)
        {
            if (a[j] < a[i])
                dp[i] = max(dp[i], 1 + dp[j]);
        }
    }
    cout << *max_element(dp, dp + n);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
