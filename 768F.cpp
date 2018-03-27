#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#define N 200005
using namespace std;
typedef long long ll;
ll mod = 1000000007LL;
int f, w, h;
ll fac[N];
ll getrev(ll x) {
    ll res = 1LL;
    ll pw = mod - 2LL;
    while(pw) {
        if (pw & 1) res = res * x % mod;
        x = x * x % mod;
        pw /= 2;
    }
    return res;
}
ll getcomb(ll n, ll m) {
    if (n < 0 && m < 0) {
        return n == m;
    }
    if (n < 0 || m < 0 || n < m) return 0LL;
    return fac[n] * getrev(fac[m]) % mod * getrev(fac[n - m]) % mod;
}
int main() {
    cin>>f>>w>>h;
    ll p = 0LL, q = 0LL;
    fac[0] = 1LL;
    for (int i = 1; i <= f + w; ++i) {
        fac[i] = fac[i - 1] * (ll)i % mod;
    }
    for (int fn = 0; fn <= f; ++fn) {
        for (int wn = fn - 1; wn <= fn + 1; ++wn) {
            ll nq = getcomb(f - 1, fn - 1) * getcomb(w - 1, wn - 1) % mod;
            if (wn == fn) nq = nq * 2LL % mod;
            ll np = getcomb(f - 1, fn - 1) * getcomb(w - (ll)h * (ll)wn - 1, wn - 1) % mod;
            if (wn == fn) np = np * 2LL % mod;
            p = (p + np) % mod;
            q = (q + nq) % mod;
        }
    }
    ll ans = p * getrev(q) % mod;
    cout<<ans<<endl;
    return 0;
}
