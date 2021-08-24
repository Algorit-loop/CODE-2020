// O(sqrt(n))
#include <iostream>
#include <math.h>
#define ll long long
using namespace std;
ll Spur(ll x){
    ll res = 0 , tmp = sqrt(x);
    for (int i = 1; i <= tmp; i++){
        res = res + x / i;
    }
    res = res * 2 - (tmp * tmp);
    return res;
}
ll Divisor(ll x){
    ll res = 0;
    for (int i = 1; 1LL * i * i <= x; i++)
        if (x % i == 0) res = res + 1 + (i != x / i);
    return res;
}
ll n;
int main()
{
    cin >> n;
    cout << Spur(n) - Divisor(n);
    return 0;
}
