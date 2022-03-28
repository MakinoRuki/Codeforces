#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <ctime>
#define M 202
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int m, k, q;
int n;
int t;
int c;
ll a[N];
struct node {
  int cnt;
  node* next[2];
  node() {
    cnt = 0;
    next[0] = NULL;
    next[1] = NULL;
  }
};
node* root = NULL;
int solve(int x, int r) {
  int tot=0;
  node* cur = root;
//  cout<<"xr="<<x<<" "<<r<<endl;
  for (int i = 17; i >= 0; --i) {
    //cout<<"i="<<i<<endl;
    if ((1<<i) & r) {
      if ((1<<i) & x) {
        if (cur->next[1]) {
          // if (x == 4 && r == 7 && i == 2) {
          //   cout<<"x="<<cur->next[1]->cnt;
          // }
          tot += cur->next[1]->cnt;
        }
        if (cur->next[0]) {
          cur = cur->next[0];
        } else {
          return tot;
        }
      } else {
        if (cur->next[0]) {
          tot += cur->next[0]->cnt;
        }
        if (cur->next[1]) {
          cur = cur->next[1];
        } else {
          return tot;
        }
      }
    } else {
      if ((1<<i) & x) {
        if (cur->next[1]) {
          cur=cur->next[1];
        } else {
          return tot;
        }
      } else {
        if (cur->next[0]) {
          cur=cur->next[0];
        } else {
          return tot;
        }
      }
    }
    //if (x == 4 && r == 7) cout<<"i="<<i<<" "<<tot<<endl;
  }
  tot += cur->cnt;
  return tot;
}
int main() {
  cin>>t;
  for (int cas=1;cas<=t; ++cas) {
    ll l, r;
    scanf("%lld%lld", &l, &r);
    ll x = 0;
    ll y = 0;
    for (ll i = l; i <= r; ++i) {
      x ^= i;
    }
    for (int i = 1; i <= r-l+1; ++i) {
      scanf("%lld", &a[i]);
      y ^= a[i];
    }
    ll n = (r-l+1);
    if (n % 2) {
      printf("%lld\n", x^y);
    } else {
      root = new node();
      for (int i = 1; i <= n; ++i) {
        node* cur = root;
        for (int j = 17; j >= 0; --j) {
          int bt = ((1<<j) & a[i])>0;
          if (!cur->next[bt]) {
            cur->next[bt] = new node();
          }
          cur->next[bt]->cnt++;
          cur = cur->next[bt];
        }
      }
    //  cout<<"x="<<root->next[1]->cnt<<endl;
      int res;
    //  cout<<"v="<<solve(1, 2)<<" "<<solve(1, 0)<<endl;
      for (int i = 1; i <= n; ++i) {
        res = a[i] ^ l;
        if (solve(res, r) - (l == 0 ? 0 : solve(res, l-1)) == r-l+1) {
          printf("%d\n", res);
          break;
        } 
      }
    }
  }
  return 0;
}
