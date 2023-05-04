#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long k, s;
    cin >> k >> s;
    long long cn = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = 0; j <= k; j++)
        {
            long long curr = i + j;
            if (0 <= s - curr and s - curr <= k)
                cn++;
        }
    }
    cout << cn << endl;
}
