#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    for (long long i = 0; i < n; i++) cin >> a[i];
    for (long long i = 0; i < n; i++) cin >> b[i];

    long long v = 0;
    for (auto z : a) v = (v << 1) ^ (z + 9999991);

    vector<long long> t(n + 1, 0);
    for (long long i = 0; i < n; i++) t[i + 1] = t[i] + (a[i] == b[i]);

    long long res = 0, len = t.size() - 1;
    for (long long i = 1; i < len; i++) res += (t[i] - t[0]) * (len - i);
    for (long long i = len - 2; i >= 0; i--) res += (t[len] - t[i + 1]) * (i + 1);

    unordered_map<long long, vector<long long>> m1, m2;
    for (long long i = 0; i < n; i++) m1[b[i]].push_back(min(i + 1, n - i));

    for (auto &kv : m1) {
        auto &l = kv.second;
        sort(l.begin(), l.end());
        vector<long long> s(1, 0);
        for (auto &v : l) s.push_back(s.back() + v);
        m2[kv.first] = move(s);
    }

    for (long long i = 0; i < n; i++) {
        long long sp = a[i];
        auto it = m1.find(sp);
        if (it == m1.end()) continue;
        const auto &d = it->second;
        const auto &su = m2.at(sp);
        long long l = min(i + 1, n - i), idx = upper_bound(d.begin(), d.end(), l) - d.begin();
        long long larger = d.size() - idx;
        res += larger * l + su[idx];
    }

    cout << res;
}
