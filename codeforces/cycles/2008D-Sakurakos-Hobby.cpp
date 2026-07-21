// RATING: 1100


#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        int n; cin >> n;
        
        vector<int> p(n + 1);
        for (int i = 1; i <= n; i++) cin >> p[i];
        
        string s; cin >> s;
        s = "0" + s;
        
        vector<int> F(n + 1, 0);
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; ++i) {
            if (!visited[i]) {
                vector<int> cycle;
                int current = i;
                int black_count = 0;
    
                while (!visited[current]) {
                    visited[current] = true;
                    cycle.push_back(current);
                    if (s[current] == '0') {
                        black_count++;
                    }
                    current = p[current];
                }
                for (int index = 0; index < cycle.size(); index++)  F[cycle[index]] = black_count;
            }
        }
        
        for (int i = 1; i <= n; i++) {
            cout << F[i] << " ";
        }
        cout << endl;
    }
}
