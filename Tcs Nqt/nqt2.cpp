#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canPackAllStones(const vector<int>& stones, int numBoxes, int bc) {
    int cw = 0;
    int currentBoxCount = 1;

    for (int sw : stones) {
        if (sw > bc) {
            return false;
        }

        if (cw + sw > bc) {
            cw = sw;
            currentBoxCount++;
        } else {
            cw += sw;
        }

        if (currentBoxCount > numBoxes) {
            return false;
        }
    }

    return true;
}

int minimumBoxesRequired(const vector<int>& stones, int bc) {
    int n = stones.size();
    int low = 1;
    int high = n;

    while (low < high) {
        int mid = (low + high) / 2;

        if (canPackAllStones(stones, mid, bc)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}

int main() {
    int n;
    cin >> n;

    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }

    int bc;
    cin >> bc;

    int minBoxes = minimumBoxesRequired(stones, bc);
    cout << minBoxes << endl;

    return 0;
}
