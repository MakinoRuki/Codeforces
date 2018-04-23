#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int na = -2000000000;
int n;
ll pb, pr, pp;
ll mr, mb;
int main() {
    cin>>n;
    ll ans = 0LL;
    pb = na, pr = na, pp = na;
    ll mr = 0LL, mb = 0LL;
    for (int i = 0; i < n; ++i) {
        ll x;
        string c;
        cin>>x>>c;
        if (c[0] == 'B' || c[0] == 'P') {
            if (pb != na) {
                ans += x - pb;
                mb = max(mb, x - pb);
            }
            pb = x;
        }
        if (c[0] == 'R' || c[0] == 'P') {
            if (pr != na) {
                ans += x - pr;
                mr = max(mr, x - pr);
            }
            pr = x;
        }
        if (c[0] == 'P') {
            if (pp != na) {
                ans += min(0LL, x - pp - mr - mb);
            }
            mr = 0, mb = 0;
            pp = x;
        }
    }
    cout<<ans<<endl;
    return 0;
}
