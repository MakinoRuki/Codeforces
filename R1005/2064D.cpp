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
#include <chrono>
#define N 200005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const int mod2 = 998244353;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int a[N];
int ln[32][N];
int rs[32][N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 0; i < 30; ++i) {
      ln[i][0]=0;
      for (int j = 1; j <= n; ++j) {
        ln[i][j]=ln[i][j-1];
        if ((1<<i)&a[j]) {
          ln[i][j] = j;
        }
      }
    }
    for (int i = 0; i < 30; ++i) {
      rs[i][n+1]=0;
      for (int j = n; j >= 1; --j) {
        rs[i][j] = rs[i][j+1];
        if ((1<<i)&a[j]) {
          rs[i][j]^=1;
        }
      }
    }
    vector<int> ans;
    ans.clear();
    while(q-->0) {
      int x;
      scanf("%d", &x);
      int lb=0;
      int cur=n;
      int suf=0;
      for (int i = 29; i >= 0; --i) {
        if (cur <= lb) break;
        suf = rs[i][cur+1];
        int res=((1<<i)&x)>0;
        if (suf^res) {
          int b1=ln[i][cur];
          if (b1-1>0&&ln[i][b1-1]) {
            lb=max(lb,ln[i][b1-1]);
          }
          cur=b1;
        } else {
          int b1=ln[i][cur];
          lb=max(lb, b1);
        }
       // cout<<"i="<<i<<" "<<lb<<endl;
      }
      ans.push_back(n-lb);
    }
    for (auto x : ans) {
      printf("%d ", x);
    }
    cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
