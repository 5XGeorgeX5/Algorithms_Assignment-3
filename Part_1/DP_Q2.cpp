#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int addModed(int a, int b)
{
    int ret = a + b;
    if (ret >= mod)
        ret -= mod;
    return ret;
}

void solve(string s)
{
    int n = (int)s.size();
    if (s.find('w') != -1 || s.find('m') != -1)
        return void(cout << "0\n");

    vector<int> iterativeDp(n + 1);
    s = '#' + s;
    iterativeDp[0] = 1;
    for (int i = 1; i <= n; ++i)
    {
        iterativeDp[i] = iterativeDp[i - 1];
        if (i > 1 && s[i] == s[i - 1] && (s[i] == 'n' || s[i] == 'u'))
            iterativeDp[i] = addModed(iterativeDp[i], iterativeDp[i - 2]);
    }
    cout << iterativeDp.back() << '\n';
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    solve(s);
    return 0;
}
