// RATING: 1400

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; long long k;
    cin >> n >> k;
    
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    sort(a.begin(), a.end());
    
    int m = n / 2; 
    long long current_val = a[m];
    
    for (int i = m + 1; i < n; i++) {
        long long diff = a[i] - current_val; 
        long long required = diff * (i - m); 
        
        if (required <= k) {
            k -= required;
            current_val = a[i];
        } else {
            current_val += k / (i - m);
            k = 0;
            break;
        }
    }

    if (k > 0) {
        current_val += k / (n - m);
    }

    cout << current_val << endl;
}
