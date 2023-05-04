#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    int n, z;
    cin >> n >> z;

    vector<int> a(n);
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    int num_unique = freq.size();

    if (num_unique == n) {
        cout << "YES Good" << endl;
    } else if (num_unique == 2) {
        cout << "YES Bad" << endl;
    } else {
        cout << "NO Average" << endl;
    }

    return 0;
}
