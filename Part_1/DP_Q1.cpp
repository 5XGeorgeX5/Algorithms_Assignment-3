#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    bitset<500 * 100 + 1> dp;
    dp.set(0);
    int sum = 0;
    while (n--)
    {
        int a;
        cin >> a;
        sum += a;
        dp |= (dp << a);
    }
    int ans = INT_MAX;
    for (int i = 0; i < sum; ++i)
    {
        if (dp[i])
            ans = min(ans, abs(sum - 2 * i));
    }
    cout << ans << '\n';
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
