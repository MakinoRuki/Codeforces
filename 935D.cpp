#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 100005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int n, m;
vector<ll> a, b;
ll getrev(ll x) {
    ll res = 1LL;
    ll b = mod - 2;
    while(b) {
        if (b & 1) res = res * x % mod;
        x = x * x % mod;
        b /= 2;
    }
    return res;
}
int main() {
    cin>>n>>m;
    ll ch;
    for (int i = 0; i < n; ++i) {
        cin>>ch;
        a.push_back(ch);
    }
    for (int i = 0; i < n; ++i) {
        cin>>ch;
        b.push_back(ch);
    }
    ll accu = 1LL;
    ll ans = 0LL;
    for (int i = 0; i < n; ++i) {
        if (a[i] && b[i]) {
            if (a[i] > b[i]) {
                ans = (ans + accu) % mod;
                break;
            } else if (a[i] < b[i]) {
                break;
            }
        } else {
            if (!a[i] && !b[i]) {
                ans = (ans + (m - 1) * getrev(2 * m) % mod * accu % mod) % mod;
                accu = accu * getrev(m) % mod;
            } else if (!a[i]) {
                ans = (ans + (m - b[i]) * getrev(m) % mod * accu % mod) % mod;
                accu = accu * getrev(m) % mod;
            } else {
                ans = (ans + (a[i] - 1) * getrev(m) % mod * accu % mod) % mod;
                accu = accu * getrev(m) % mod;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
