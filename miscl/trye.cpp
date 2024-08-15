#include <bits/stdc++.h>
using namespace std;
int sumofdigits(int n)
    {
        int sum = 0;
        while (n != 0) {
            sum = sum + n % 10;
            n = n / 10;
        }
        return sum;
    }
int main()
{
    int n;
    cout<<"Enter number :";
    cin>>n;
    cout <<"Sum of digits of "<<n<<": "<<sumofdigits(n);
    return 0;
}
