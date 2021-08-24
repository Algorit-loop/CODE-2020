// O(max(a_i) / 3 + nlog(n))
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int lim_pr = 1e8;
const int N = 1e5 + 1;
int lp[lim_pr/3 + 1],pr[5761459],cnt = 0;
int a[N],n;
void sieve(int lim){
    for (int i = 6; i <= lim; i += 6){
        if (lp[(i - 1)/3] == 0) lp[(i - 1)/3] = pr[++cnt] = i - 1;
        if (lp[(i + 1)/3] == 0) lp[(i + 1)/3] = pr[++cnt] = i + 1;
        int j = 1;
        while (j <= cnt && pr[j] <= lp[(i - 1)/3] && pr[j] * (i - 1) <= lim){
            lp[((i - 1) * pr[j])/3] = pr[j];
            j++;
        }
        j = 1;
        while (j <= cnt && pr[j] <= lp[(i + 1)/3] && pr[j] * (i + 1) <= lim){
            lp[((i + 1) * pr[j])/3] = pr[j];
            j++;
        }
    }
}
ll slu(int x){
    ll res = 1 , d = 0;
    while (x % 2 == 0 && x > 1){
        d++;
        x >>= 1;
    }
    res = res * (d + 1);
    d = 0;
    while (x % 3 == 0 && x > 1){
        d++;
        x /= 3;
    }
    res = res * (d + 1);
    while (x > 1){
        d = 0;
        int temp = lp[x / 3];
        while (x % temp == 0){
            d++;
            x /= temp;
        }
        res = res * (d + 1);
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL);
    int yeah = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i] , yeah = max(yeah,a[i]);
    sieve(yeah + 1);
    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = ans + 1LL * slu(a[i]) * a[i];
    cout << ans;
    return 0;
}
