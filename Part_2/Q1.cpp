#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    sort(a, a + n);
    sort(b, b + m);
    int j = n - 1, ans = 0;
    for (int i = m - 1; i >= 0; --i)
    {
        while (j >= 0 && a[j] > b[i])
            --j;
        if (j >= 0)
        {
            --j;
            ++ans;
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
