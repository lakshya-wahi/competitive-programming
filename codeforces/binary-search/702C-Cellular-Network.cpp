// RATING: 1500

#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int n, m;
    cin >> n >> m;
    
    long long a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    
    set<long long> unique_b;
    for (int i = 0; i < m; i++) {
        long long x;
        cin >> x;
        unique_b.insert(x);
    }
    
    vector<long long> b(unique_b.begin(), unique_b.end());
    
    int city = 0, tower = 0;
    long long r = 0;
    while (city < n) {
        
        while (tower < b.size() - 1 && abs(a[city] - b[tower]) > abs(a[city] - b[tower + 1])) {
            tower++;
        } 
        r = max(r, abs(a[city] - b[tower]));
        city++;
        if (city == n) {
            break;
        }
        
        
    }
    
    cout << r << endl;
}
