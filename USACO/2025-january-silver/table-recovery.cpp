#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> t, nm;
vector<int> c, pa, fr;
vector<pair<int,int>> P;

int fp(int x) {
    return pa[x] == x ? x : pa[x] = fp(pa[x]);
}

void un(int x, int y) {
    x = fp(x); 
    y = fp(y);
    if (x != y) pa[y] = x;
}

int f2(int a, int b) {
    int rA = P[a].first, cA = P[a].second;
    int rB = P[b].first, cB = P[b].second;
    return (rA < rB || (rA == rB && cA < cB)) ? a : b;
}

bool chv(const vector<vector<int>> &X) {
    vector<int> s(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) s[i] += X[i][j];
    }
    sort(s.begin(), s.end());
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1] + n) return false;
    }
    return true;
}

vector<int> rt;

bool dfs(int i, vector<int> &as) {
    if (i == (int)rt.size()) {
        vector<vector<int>> R(n, vector<int>(n));
        for (int r = 0; r < n; r++) {
            for (int c2 = 0; c2 < n; c2++) {
                int v = t[r][c2], g = fp(v);
                int bb = as[g];
                R[r][c2] = nm[bb][v];
            }
        }
        if (chv(R)) {
            for (int r = 0; r < n; r++) {
                for (int c2 = 0; c2 < n; c2++) {
                    cout << (c2 ? " " : "") << R[r][c2];
                }
                cout << "\n";
            }
            return true;
        }
        return false;
    }
    int g = rt[i];
    if (fr[g] != -1) {
        as[g] = fr[g];
        if (dfs(i + 1, as)) return true;
    } else {
        for (int b = 0; b < 2; b++) {
            as[g] = b;
            if (dfs(i + 1, as)) return true;
        }
        as[g] = -1;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    m = n * 2;
    t.assign(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    c.assign(m + 1, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[t[i][j]]++;
        }
    }
    P.assign(m + 1, make_pair(-1, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int v = t[i][j];
            if (P[v].first < 0) P[v] = make_pair(i, j);
        }
    }
    nm.assign(2, vector<int>(m + 1, 0));
    vector<vector<int>> g;
    for (int i = 1; i <= n; i++) {
        int s1 = 0, s2 = 0;
        for (int v = 1; v <= m; v++) {
            if (c[v] == i) {
                if (!s1) s1 = v; 
                else s2 = v;
            }
        }
        int o1 = i + 1, o2 = m + 2 - o1;
        int ff = f2(s1, s2), sc = (s1 == ff ? s2 : s1);
        nm[0][ff] = o1;  nm[0][sc] = o2;
        nm[1][ff] = o2;  nm[1][sc] = o1;
        g.push_back({ff, sc});
    }
    pa.resize(m + 1);
    for (int i = 1; i <= m; i++) pa[i] = i;
    for (auto &x : g) un(x[0], x[1]);
    fr.assign(m + 1, -1);
    vector<int> s;
    for (int i = 2; i <= m; i++) {
        if (nm[0][i] == nm[1][i]) s.push_back(i);
    }
    for (auto &x : s) {
        fr[fp(x)] = 1;
    }
    set<int> st;
    for (int i = 1; i <= m; i++) {
        st.insert(fp(i));
    }
    rt.assign(st.begin(), st.end());
    vector<int> as(m + 1, -1);
    dfs(0, as);
}
