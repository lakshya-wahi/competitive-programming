#include<bits/stdc++.h>

using namespace std;

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    cin >> n >> s;
    
    vector<int> q(n), v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> q[i] >> v[i];
    }

    int targetsBroken = 0;
    int position = s - 1, jumpPower = 1;
    bool direction = true;
    
    while (position >= 0 && position < n) {
        if (q[position] == 0) {
            jumpPower += v[position];
            direction = !direction;
        } else if (q[position] == 1 && v[position] <= jumpPower) {
            targetsBroken++;
            q[position] = 2;
        }
        position += (direction ? jumpPower : -jumpPower);
    }
    
    cout << targetsBroken << '\n';
}
