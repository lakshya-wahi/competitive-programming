#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n, m;
        cin >> n >> m;
        vector<long long> seq(n), mods(n);
        for (auto &e : seq) cin >> e;
        for (int i = 0; i < n; i++) mods[i] = seq[i] % m;

        if (m == 1) { cout << 0; continue; }

        sort(mods.begin(), mods.end());
        vector<long long> es(2 * n), sum(2 * n + 1, 0);
        for (int i = 0; i < n; i++) es[i] = mods[i], es[i + n] = mods[i] + m;

        for (int i = 0; i < 2 * n; i++) sum[i + 1] = sum[i] + es[i];

        long long minCst = LLONG_MAX;
        for (int si = 0; si < n; si++) {
            int mi = si + (n / 2);
            long long mv = es[mi], lc = mv * (mi - si) - (sum[mi] - sum[si]);
            long long rc = (sum[si + n] - sum[mi + 1]) - mv * (si + n - mi - 1);
            minCst = min(minCst, lc + rc);
        }

        cout << minCst << endl;
    }
}
