// RATING: 1200

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    
    while (t--) {
        int x, y, z;
        cin >> x >> y >> z;
        
        long long k;
        cin >> k;
        
        long long maxNum = 0;
        for (int a = 1; a <= x; a++) {
            for (int b = 1; b <= y; b++) {
                if (k % (a * b) == 0) {
                    long long c = k / (a * b);
                    if ((x - a + 1) * (y - b + 1) * (z - c + 1) > maxNum) {
                        maxNum = (x - a + 1) * (y - b + 1) * (z - c + 1);
                    }
                }
            }
        }
        
        cout << maxNum << endl;
    }
}
