// O(n * k)
#include <iostream>
#define ll long long
using namespace std;
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
int n , k;
int a[21] , b[21];
ll dp[N] , sum[N];
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= k; i++) cin >> a[i] >> b[i];
    dp[1] = 1;
    sum[1] = 1;
    for (int i = 2; i <= n; i++){
        for (int j = 1; j <= k; j++)
            dp[i] = (dp[i] + sum[max(i - a[j],0)] - sum[max(i - b[j] - 1,0)] + mod + mod) % mod;
        sum[i] = (sum[i - 1] + dp[i]) % mod;
    }
    cout << dp[n];
    return 0;
}
