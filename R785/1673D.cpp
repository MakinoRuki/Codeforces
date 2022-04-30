#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <list>
#include <random>
#define N 40010
#define M 502
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
ll getgcd(ll x, ll y) {
  return y == 0 ? x : getgcd(y, x %y);
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    ll b,q,y;
    ll c,r,z;
    scanf("%lld%lld%lld", &b, &q, &y);
    scanf("%lld%lld%lld", &c, &r, &z);
    if (z > y) {
      puts("0");
      continue;
    }
    ll tot=0LL;
    if (c < b || c + r * (z-1) > b + q * (y-1)) {
      puts("0");
      continue;
    }
    if (q == 0) {
      if (z == 1) {
        if (c != b) {
          puts("0");
        } else {
          puts("-1");
        }
      } else {
        // if (r != 0 || c != b) {
        //   puts("0");
        // } else if (y == z) {
        //   puts("-1");
        // } else {
        //   puts("1");
        // }
        if (y == z) {
          if (c!=b || r != 0) {
            puts("0");
          } else {
            puts("-1");
          }
        } else {
          if (c != b || r != 0) {
            puts("0");
          } else {
            puts("1");
          }
        }
      }
    } else {
      if (((c-b)%q>0) || ((c-b)/q < 0 || (c-b)/q >= y)) {
        puts("0");
        continue;
      }
      ll c2 = c + r*(z-1);
      if (((c2-b)%q)>0 || ((c2-b)/q < 0 || (c2-b)/q >= y)) {
        puts("0");
        continue;
      }
      if (z == 1) {
        puts("-1");
        continue;
      }
      if (r % q != 0) {
        puts("0");
      } else {
        if (c + r*z > b + q*(y-1) || c - r < b) {
          puts("-1");
          continue;
        }
       // ll dt = r/q;
        ll ans = 0LL;
        ll dt = 1LL;
   //      bool found=false;
   //      map<ll, ll> mp1;
   //      map<ll, ll> mp2;
   //      ll qq = q, rr = r;
   //    //  cout<<"xx"<<endl;
   //      for (ll d = 2; d * d <= qq; ++d) {
   //        if (qq % d) continue;
   //     //   cout<<"d="<<d<<endl;
   //        mp1[d] = 1;
   //        while(qq % d == 0) {
   //          mp1[d] *= d;
   //          qq/=d;
   //        }
   //      }
   //   //   cout<<"xx"<<endl;
   //      if (qq > 1) mp1[qq] = qq;
   //      for (ll d = 2; d * d <= rr; ++d) {
   //        if (rr%d) continue;
   //        mp2[d] = 1;
   //        while(rr % d == 0) {
   //          mp2[d] *=  d;
   //          rr/=d;
   //        }
   //      }
   //   //   cout<<"xx"<<endl;
   //      if (rr > 1) mp2[rr] = rr;
   //      ll tmp = 1LL;
   //      for (auto x : mp2) {
   //        if (x.second > mp1[x.first]) {
   //          dt *= x.second;
   //        } else {
   //          tmp *= x.second;
   //        }
   //      }
   // //     cout<<"xx"<<endl;
   //      for (ll d = 1; d*d <= tmp; ++d) {
   //        if (tmp % d) continue;
   //        ll q2 = dt * d;
   //        ll n1 = (r / q2) % mod;
   //        if (q2 <= r) ans = (ans + n1 * n1 % mod) % mod;
   //        if (q/d != d) {
   //          q2 = dt * (q/d);
   //          ll n2 = (r/q2) % mod;
   //          if (q2 <= r) ans = (ans + n2 * n2 % mod) % mod;
   //        }
   //      }
        vector<ll> qs;
        qs.clear();
        for (ll d = 1; d * d <= r; ++d) {
          if (r % d == 0) {
            ll g = getgcd(d, q);
            if (q / g * d == r) {
              ll n1 = (r / d) % mod;
              ans = (ans + n1 * n1 % mod) % mod;
              //qs.push_back(d);
            }
            if (r/d != d) {
              ll g = getgcd(r/d, q);
              if (q/g * (r/d) == r) {
                ll n1 = (r / (r/d)) % mod;
                ans = (ans + n1 * n1 % mod) % mod;
                //qs.push_back(r/d);
              }
            }
          }
        }
        // for (auto d : qs) {
        // //  cout<<"d="<<d<<endl;
        //   ll n1 = (r / d) % mod;
        //   ans = (ans + n1 * n1 % mod) % mod;
        // }
        printf("%lld\n", ans);
      }
    }
  }
  return 0;
}
