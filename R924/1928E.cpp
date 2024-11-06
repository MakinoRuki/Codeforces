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
#include <list>
#include <stack>
#include <bitset>
#define N 300005
#define M 5002
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k;
int t;
int a[N];
int dp[N];
int res[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y,s;
    scanf("%d%d%d%d", &n, &x, &y, &s);
    for (int i = 0; i <= s; ++i) {
      dp[i] = inf;
      res[i]=-inf;
    }
    // if (cas==17063) {
    //   cout<<n<<endl;
    //   //string tmp=to_string(n)+"#"+to_string(x)+"#"+to_string(y)+"#"+to_string(s);
    //   //cout<<tmp<<endl;
    // }
    ll len = x/y;
    ll tot = ((ll)s-(ll)(x%y)*(ll)n);
    if (tot % y) {
      puts("NO");
      continue;
    }
    if (s < x + (x%y)*(n-1)) {
      puts("NO");
      continue;
    }
    tot /= y;
    for (int i = 1; i <= n; ++i) {
      ll dt = len*(ll)i + (ll)i*(ll)(i-1)/2LL;
      if (dt <= tot) {
        if (i < dp[dt]) {
          dp[dt] = i;
          res[dt] = -i;
        }
      }
    }
  //  cout<<"v5="<<dp[5]<<endl;
    for (int i = 0; i <= tot; ++i) {
      if (dp[i] < inf) {
        for (int j = 1; j*(j+1)/2 <= tot-i; ++j) {
          if (dp[i] + j+1 <= n) {
            ll sum = j*(j+1)/2;
          //  if (i == 5 && j == 1) cout<<"vv="<<dp[i]<<" "<<i+sum<<endl;
            if (i+sum<=tot && dp[i]+j+1 < dp[i+sum]) {
              dp[i+sum] = dp[i]+j+1;
              res[i+sum] = j;
            }
          }
        }
      }
    }
    if (dp[tot] <= n) {
      vector<int> ans;
      ans.clear();
      int cur = tot;
      while(res[cur]>0) {
        for (int i = res[cur]; i >= 0; --i) {
          ans.push_back((x%y)+(i*y));
        }
        cur -= res[cur]*(res[cur]+1)/2;
      }
      res[cur]=abs(res[cur]);
      for (int i = res[cur]-1; i >= 0; --i) {
        ans.push_back(x + y*i);
      }
      reverse(ans.begin(), ans.end());
      while(ans.size() < n) {
        ans.push_back(x%y);
      }
      puts("YES");
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
      }
      cout<<endl;
    } else {
      puts("NO");
    }
    // bool found=false;
    // for (int i = 1; i <= n; ++i) {
    //   ll dt = len*(ll)i + (ll)i*(ll)(i-1)/2LL;
    //   if (tot < dt) continue;
    //   //cout<<"i="<<i<<" "<<dt<<" "<<tot-dt<<" "<<dp[tot-dt]<<endl;
    //   if (i + dp[tot-dt] <= n) {
    //     ll cur= tot-dt;
    //     vector<int> v;
    //     v.clear();
    //     while(cur) {
    //       int tmp=res[cur];
    //       v.push_back(tmp);
    //       cur -= tmp*(tmp-1)/2;
    //     }
    //     reverse(v.begin(), v.end());
    //     puts("YES");
    //     cur = x/y*y;
    //     for (int j = 1; j <= i; ++j) {
    //       printf("%d ", (x%y)+cur);
    //       cur += y;
    //     }
    //     for (auto j : v) {
    //       cur= 0;
    //       for (int j2 = 1; j2 <= j; ++j2) {
    //         printf("%d ", (x%y)+cur);
    //         cur += y;
    //       }
    //     }
    //     for (int j =1; j <= n-(i+dp[tot-dt]); ++j) {
    //       printf("%d ", x%y);
    //     }
    //     cout<<endl;
    //     found=true;
    //     break;
    //   }
    // }
    // if (!found) {
    //   puts("NO");
    // }
    // if (dp[tot] <= n) {
    //   vector<int> v;
    //   v.clear();
    //   ll cur = tot;
    //   while(cur) {
    //     int len=res[cur];
    //     v.push_back(abs(len));
    //     if (len > 0) {
    //       cur -= len*(len+1)/2;
    //     } else {
    //       break;
    //     }
    //   }
    //   puts("YES");
    //   int cnt=0;
    //   reverse(v.begin(), v.end());
    //   for (int i = 0; i < v.size(); ++i) {
    //     cout<<"i="<<i<<" "<<v[i]<<endl;
    //     int cur = 0;
    //     if (i == 0) cur = x/y*y;
    //     for (int j = 1; j <= v[i]; ++j) {
    //       cnt++;
    //       printf("%d ", cur + (x%y));
    //       cur += y;
    //     }
    //   }
    //   for (int i = 1; i <= n-cnt; ++i) {
    //     printf("%d ", x%y);
    //   }
    //   cout<<endl;
    // } else {
    //   puts("NO");
    // }
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}

