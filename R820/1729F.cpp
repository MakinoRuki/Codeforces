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
#define N 200005
#define M 2505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000000;
int n, m, k, q;
int t;
int idx[15][2];
int res[N];
int sum[N];
int main() {
  cin>>t;
  mt19937 rnd(time(0));
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    int w;
    scanf("%d%d", &w, &m);
    for (int j = 0; j < n; ++j) {
      sum[j] = 0;
    }
    for (int i = 0; i < 10; ++i) {
      idx[i][0] = -1;
      idx[i][1] = -1;
    }
    for (int i = 0; i < n; ++i) {
      sum[i] = (i == 0 ? 0 : sum[i-1]);
      sum[i] = (sum[i] + (s[i]-'0')%9) % 9;
    }
    int cur = 0;
    for (int i = 0; i < w; ++i) {
      cur = (cur + s[i]-'0') % 9;
    }
    res[0] = cur;
    idx[cur][0] = 0;
   // cout<<"cur="<<cur<<endl;
    for (int i = w; i < n; ++i) {
      cur = (cur - (s[i-w]-'0')%9 + 9) % 9;
      cur = (cur + s[i]-'0') % 9;
      res[i-w+1] = cur;
     // if (i == w) cout<<"i="<<i<<" "<<cur<<endl;
      if (idx[cur][0] < 0) {
        idx[cur][0] = i-w+1;
      } else if (idx[cur][1] < 0) {
        idx[cur][1] = i-w+1;
      }
    }
  //  cout<<"id="<<idx[0][3]<<" "<<res[3]<<endl;
    // for (int i = n-1; i >= 1; --i) {
    //   for (int j = 0; j < 10; ++j) {
    //     if (i+1<n && idx[i+1][j] >= 0) {
    //       idx[i][j] = idx[i+1][j];
    //     }
    //   }
    //   if (i + w-1<=n-1) {
    //     idx[i][res[i]] = i;
    //   //  if (i == 3) cout<<"??="<<res[i]<<" "<<idx[i][res[i]]<<endl;
    //   }
    // //  cout<<"ii="<<i<<" "<<idx[i][7]<<endl;
    // }
    for (int i = 1; i <= m; ++i) {
      int l, r;
      scanf("%d%d%d", &l, &r, &k);
      r--;
      l--;
      int tmp = sum[r];
      if (l-1>=0) {
        tmp = (tmp - sum[l-1] + 9) % 9;
      }
      int id1 = -1, id2 = -1;
      for (int j = 0; j < 9; ++j) {
        if (idx[j][0] >= 0) {
     //     if (j == 3) cout<<"id2="<<j<<" "<<idx[0][j]<<endl;
          int r2 =  (k % 9 - (j * tmp) % 9 + 9) % 9;
          int x = idx[j][0];
          int y;
          if (j == r2) {
            y = idx[j][1];
          } else {
            y = idx[r2][0];
          }
       //   if (j == 3) cout<<"j="<<j<<" "<<r2<<" "<<x<<" "<<idx[x+1][r2]<<endl;
          if (y >= 0) {
            if (id1 < 0) {
              id1 = x + 1;
              id2 = y + 1;
            } else if (x+1 < id1 || (x+1 == id1 && y+1 < id2)) {
              id1 = x + 1;
              id2 = y+1;
            }
          }
        }
      }
      printf("%d %d\n", id1, id2);
    }
  }
  return 0;
}
