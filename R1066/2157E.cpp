
#include <iostream>
#include <sstream>
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
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 2000005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 1000003;
const ll base1 = 13331LL;
const ll base2 = 23333LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0));
const int base=337;
int n, m, q;
int k, w;
int t;
int a[N];
int cnt[2*N];
int sum[2*N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
  //  int x,y;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= 2*n; ++i) {
      cnt[i]=0;
    }
    for (int i = 1; i <= n; ++i) {
      cnt[a[i]]++;
    }
    vector<pair<int,int>> v;
    v.clear();
    for (int i = 1; i <= 2*n; ++i) {
      if (cnt[i]) {
        v.push_back(make_pair(i, cnt[i]));
      }
    }
    sum[0]=0;
    for (int i = 1; i <= 2*n; ++i) {
      sum[i] = sum[i-1];
      if (!cnt[i]) sum[i]++;
    }
    int ans=0;
    int pre=-1;
    ll l = 0, r= 3LL*n;
    while(l < r) {
      ll mid = (l+r)/2;
     // if (mid <= 2*n) cout<<"mid="<<mid<<endl;
      ll ex = 0;
      deque<int> dq;
      bool ok=true;
      for (int i = 2*n; i >= 1; --i) {
        if (!cnt[i]) {
          dq.push_front(i);
        } else {
          ll x = mid;
          int cur=i;
          int v=cnt[i];
          while(!dq.empty() && x && v>1) {
            if (dq.front()-cur<=x) {
              x -= dq.front()-cur;
              cur=dq.front();
              v--;
              dq.pop_front();
            } else {
              break;
            }
          }
          if (x) {
            cur += x;
            if (cur > 2*n) {
              ll tmp = cur-2*n;
              if (tmp > ex) {
                ll tmp2 = min(tmp-ex, v-1LL);
                v -= tmp2;
                ex += tmp2;
              }
            }
          }
          if (v > k) ok=false;
        }
      }
      if (ok) r = mid;
      else l = mid+1;
    }
    printf("%lld\n", r);
  }
  return 0;
}

