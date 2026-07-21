// RATING: 1800

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        long long a[n];
        bool good = true, ww = false;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] > 1) {
                ww = true;
            } 
            if (a[i] == 1 && ww == true) {
                good = false;
            }
        }
        
        long long b[n];
        for (int i = 0; i < n; i++) {
            b[i] = 1;
        }
        
        if (good) {
            long long count = 0;
            int prevNumJustice = 0;
            for (int i = 1; i < n; i++) {
                int numJustice = ceil(prevNumJustice + log2(log(a[i - 1])/log(a[i])));
                prevNumJustice = max(0, numJustice);
                count += max(0, numJustice);
            }
            cout << count << endl;
        } else {
            cout << -1 << endl;
        }
    }
}
