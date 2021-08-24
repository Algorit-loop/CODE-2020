// O(nlog(n))
#include <iostream>
#include <bitset>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
const ll base = 311;
const ll mod = 1e9 + 7;
class Rolling_Hash{
private :
    ll hr[N] , power[N];
public :
    void Built(int &n,const string &s){
        power[0] = 1;
        for (int i = 1; i <= n; i++) power[i] = (power[i - 1] * base) % mod;
        hr[0] = 0;
        for (int i = 1; i <= n; i++) hr[i] = (hr[i - 1] * base + s[i] - 'A' + 1) % mod;
    }
    ll GetHash(int x,int y){
        return (hr[y] - hr[x - 1] * power[y - x + 1] + mod * mod) % mod;
    }
};
bitset <1000000010> bit;
int n;
string s;
int main()
{
    cin >> n >> s;
    s = "@" + s;
    Rolling_Hash A;
    A.Built(n,s);
    int L = 1 , R = n;
    while (L <= R){
        int mid = (L + R) >> 1;
        bool check = true;
        for (int i = 1; i <= n - mid + 1; i++)
            if (bit[A.GetHash(i,i + mid - 1)]){
                check = false;
                break;
            }
            else bit[A.GetHash(i,i + mid - 1)] = true;
        for (int i = 1; i <= n - mid + 1; i++)
            bit[A.GetHash(i,i + mid - 1)] = false;
        if (check)
            R = mid - 1;
        else
            L = mid + 1;
    }
    cout << L;
    return 0;
}
