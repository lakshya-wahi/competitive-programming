#include<bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    
    vector<long long> grass(n);
    for (int i = 0; i < n; i++) {
        cin >> grass[i];
    }
    
    long long sprays = 0, level;
    for (int i = 0; i < n; i++) {
        if (grass[i] != 0) {
            sprays += abs(grass[i]);
            if (grass[i] > 0) {
                level = (-1) * (n - i);
            } else {
                level = n - i;
            }
            
            
            for (int j = n - 1; j >= i; j--) {
                grass[j] += level * abs(grass[i]);
                if (level < 0) {
                    level++;
                } else {
                    level--;
                }
            }
        }
    }
    
    cout << sprays << endl;
    
}
