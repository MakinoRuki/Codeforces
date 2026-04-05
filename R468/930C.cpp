
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
#define N 200005
#define M 100
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
int b[N];
vector<pair<int,int>> sg;
int cnt[N];
int dp1[N], dp2[N];
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>n>>m;
  sg.clear();
  memset(cnt, 0, sizeof(cnt));
  vector<pair<int,int>> rk;
  rk.clear();
  for (int i =1 ; i <= n; ++i) {
    int l,r;
    scanf("%d%d", &l, &r);
    sg.push_back(make_pair(l, r));
    rk.push_back(make_pair(l, 1));
    rk.push_back(make_pair(r, -1));
  }
  sort(rk.begin(), rk.end());
  int sum=0;
  int cur=0;
  for (int i = 1; i <= m; ++i) {
    int n1=0,n0=0;
    while(cur < rk.size() && rk[cur].first==i) {
      if (rk[cur].second==1)n1++;
      else n0++;
      cur++;
    }
    sum += n1;
    a[i] += sum;
    sum -= n0;
  }
  // while(cur < rk.size()) {
  //   int i;
  //   int n0=0,n1=0;
  //   for (i = cur; i < rk.size(); ++i) {
  //     if (rk[i].first==rk[cur].first) {
  //       if (rk[i].second==1) n1++;
  //       else n0++;
  //     } else {
  //       break;
  //     }
  //   }
  //  // cout<<"cur="<<cur<<" "<<
  //   sum += n1;
  //   a[rk[cur].first] += sum;
  //   sum -= n0;
  //   cur = i;
  // }
  int len=0;
  for (int i = 1; i <= m; ++i) {
 //   cout<<"i="<<i<<" "<<a[i]<<endl;
    b[i]=0;
    if (len==0 || dp1[len] <= a[i]) {
      dp1[++len] = a[i];
      b[i] += len;
      continue;
    }
    int l=1,r=len;
    while(l < r) {
      int mid=(l+r)/2;
      if (dp1[mid] <= a[i]) {
        l=mid+1;
      } else {
        r = mid;
      }
    }
  //  cout<<"r="<<r<<endl;
    dp1[r] = a[i];
    b[i] += r;
   // cout<<"bi="<<b[i]<<" "<<len<<" "<<dp1[len]<<endl;
  }
  // for (int i = 1; i <= m; ++i) {
  //   cout<<"i="<<i<<" "<<b[i]<<endl;
  // }
  len=0;
  for (int i = m; i >= 1; --i) {
    if (len==0 || dp2[len] <= a[i]) {
      dp2[++len] = a[i];
      b[i] += len;
      continue;
    }
    int l=1,r=len;
    while(l<r) {
      int mid=(l+r)/2;
      if (dp2[mid] <= a[i]) {
        l=mid+1;
      } else {
        r=mid;
      }
    }
    dp2[r] = a[i];
    b[i] += r;
  }
  int ans=0;
  for (int i = 1; i <= m; ++i) {
    ans=max(ans, b[i]-1);
  }
  cout<<ans<<endl;
  return 0;
}

