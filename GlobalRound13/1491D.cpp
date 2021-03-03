#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 21
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n,t;
int q;
int getbits(int x) {
  int cnt=0;
  while(x) {
    if (x&1) cnt++;
    x/=2;
  }
  return cnt;
}
void dfs(int u, set<int>& ss) {
  if (ss.find(u) != ss.end()) {
    return ;
  }
  ss.insert(u);
  for (int i = 1; i < (1<<15); ++i) {
    if ((u&i) == i) {
      dfs(u+i, ss);
    }
  }
}
bool check(int u, int v) {
  if (u > v) {
      return false;
    } else {
      int cu = getbits(u);
      int cv = getbits(v);
      if (cu < cv) {
        return false;
      }
      int cnt1[32];
      int cnt2[32];
      memset(cnt1, 0, sizeof(cnt1));
      memset(cnt2, 0, sizeof(cnt2));
      for (int i = 0; i <= 30; ++i) {
        if ((1<<i) & u) cnt1[i]++;
        if (i>0) cnt1[i] += cnt1[i-1];
        if ((1<<i) & v) cnt2[i]++;
        if (i>0) cnt2[i] += cnt2[i-1];
      }
      for (int i = 0; i <= 30; ++i) {
        if (cnt1[i] < cnt2[i]) {
          return false;
        }
      }
      // int pw1=0;
      // int pw2=0;
      // while(u > 0 && v > 0 && ((u&1) == (v&1))) {
      //   u>>=1;
      //   v>>=1;
      // }
      // if (u==0 && v==0) return true;
      // if ((u==0 && v>0) || (u>0 && v==0)) return false;
      // while(!((1<<pw1)&u)) {
      //   pw1++;
      // }
      
      // while(!((1<<pw2)&v)) {
      //   pw2++;
      // }
      // if (pw1>pw2) {
      //   return false;
      // }
      return true;
    }
}
int main() {
  cin>>q;
  while(q-->0) {
    int u,v;
    scanf("%d%d", &u, &v);
    if (check(u, v)) {
      puts("YES");
    } else {
      puts("NO");
    }
  }
  // cin>>q;
  // while(q-->0) {
  //   int u,v;
  //   scanf("%d%d", &u, &v);
  //   if (u > v) {
  //     puts("NO");
  //     continue;
  //   } else {
  //     int cu = getbits(u);
  //     int cv = getbits(v);
  //     if (cu < cv) {
  //       puts("NO");
  //       continue;
  //     }
  //     int pw1=0;
  //     while(!((1<<pw1)&u)) {
  //       pw1++;
  //     }
  //     int pw2=0;
  //     while(!((1<<pw2)&v)) {
  //       pw2++;
  //     }
  //     if (pw1>pw2) {
  //       puts("NO");
  //       continue;
  //     }
  //     puts("YES");
  //   }
  //}
  // cin>>n;
  // for (int i = 1; i <= n; ++i) {
  //   set<int>ss;
  //   ss.clear();
  //   cout<<"i="<<i<<endl;
  //   dfs(i, ss);
  //   // for (auto itr : ss) {
  //   //   cout<<(itr)<<" ";
  //   // }
  //   for (int j = 0; j < (1<<15); ++j) {
  //     if (check(i, j) && ss.find(j) == ss.end()) {
  //       cout<<"j1="<<j<<endl;
  //     } else if (!check(i, j) && ss.find(j) != ss.end()) {
  //       cout<<"j2="<<j<<endl;
  //     }
  //   }
  //   cout<<endl;
  // }
  return 0;
}
