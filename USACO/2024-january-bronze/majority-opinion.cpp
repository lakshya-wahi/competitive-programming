#include<bits/stdc++.h>

using namespace std;

inline bool canConvert(const vector<int>& hays, int hay) {
    if (hays[0] == hay && hays[1] == hay) {
        return true;
    }
    for (int i = 2; i < hays.size(); i++) {
        if (hays[i] == hay && (hays[i - 1] == hay || hays[i - 2] == hay)) {
            return true;
        }
    }
    return false;
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> hay(n);
        set<int> uniqueHays;
        int count = 0;

        for (int i = 0; i < n; i++) {
            int y;
            cin >> y;
            
            hay[i] = y;  
            if (hay[i - 1] == hay[i] || hay[i - 2] == hay[i]) {
                uniqueHays.insert(hay[i]);
                count++;
            }
        }
        
        if (uniqueHays.empty()) {
            cout << "-1";
        } else {
            auto it = uniqueHays.begin();
            while (it != --uniqueHays.end()) {
                cout << *it << ' ';
                ++it;
            }
            cout << *it;  // Print the last element without the space
        }
        
        cout << '\n';
    }
}
