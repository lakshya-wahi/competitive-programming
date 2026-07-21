// RATING: 1500

#include <bits/stdc++.h>

using namespace std;

int countTriplets(int n, int x) {
    int count = 0;

    for (int a = 1; a <= x; ++a) {
        int max_b = min(x - a, (n / a));
        
        for (int b = 1; b <= max_b; ++b) {
            int max_c_sum = x - a - b;
            int max_c_value = (n - a * b) / (a + b);
            
            int max_c = min(max_c_sum, max_c_value);
            
            if (max_c >= 1) {
                count += max_c;
            }
        }
    }
    
    return count;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, x;
        cin >> n >> x;
    
        int result = countTriplets(n, x);
        cout << result << endl;
    }
}
