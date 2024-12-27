#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int gap, m;
    cin >> m >> gap;
    vector<int> frq(26), last(26, -gap);
    for (int i = 0; i < m; ++i)
    {
        char c;
        cin >> c;
        ++frq[c - 'A'];
    }
    vector<int> v(26);
    iota(v.begin(), v.end(), 0);
    sort(v.begin(), v.end(), [&](int i, int j)
         { return frq[i] > frq[j]; });
    int ans = 1, count = 0;
    while (count < m)
    {
        int next = -1;
        for (auto &c : v)
        {
            if (!frq[c])
                continue;
            if (ans - last[c] > gap)
            {
                next = c;
                --frq[c];
                ++count;
                last[c] = ans;
                break;
            }
        }
        ++ans;
    }
    cout << ans - 1;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}
