// RATING: 1300

#include <bits/stdc++.h>

using namespace std;

string toBinaryString(long long n) {
    if (n == 0) {
        return "0";
    }
    
    string binary;
    while (n > 0) {
        binary += (n % 2 == 0 ? '0' : '1');
        n /= 2;
    }

    reverse(binary.begin(), binary.end());
    
    return binary;
}

long long binaryStringToInt(const string &binary) {
    long long result = 0;
    long long length = binary.size();
    
    for (long long i = 0; i < length; ++i) {
        if (binary[length - 1 - i] == '1') {
            result += (1LL << i); // Using bitwise shift for power of two
        }
    }
    
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    
    int t;
    cin >> t;
    
    while (t--) {
        long long n;
        cin >> n;
        
        vector<long long> seq = {n};
        
        string binary = toBinaryString(n);
        
        for (long long i = binary.size() - 1; i >= 0; i--) {
            if (binary[i] == '1') {
                string diff = binary.substr(0, i) + '0' + binary.substr(i + 1);
                long long newNum = binaryStringToInt(diff);
                if (newNum > 0) {
                    seq.push_back(newNum);
                }
            }
        }
        
        cout << seq.size() << endl;
        for (long long i = seq.size() - 1; i >= 0; i--) {
            cout << seq[i] << " ";
        }
        cout << endl;
    }
}
