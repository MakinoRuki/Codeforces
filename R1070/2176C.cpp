
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
#define N 500005
#define M 8002
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
ll sum[2][N];
ll ans[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> v1;
    vector<int> v0;
    v1.clear();
    v0.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i]%2) v1.push_back(a[i]);
      else v0.push_back(a[i]);
    }
    sum[0][0]=0;
    sum[1][0]=0;
    sort(v0.begin(), v0.end());
    sort(v1.begin(), v1.end());
    for (int i = 1; i <= v0.size(); ++i) {
      sum[0][i] = sum[0][i-1] + v0[i-1];
    }
    for (int i = 1; i <= v1.size(); ++i) {
      sum[1][i] = sum[1][i-1] + v1[i-1];
    }
    int sz1=(int)v1.size();
    int sz0=(int)v0.size();
    int cur=0;
    if (v1.empty()) {
      for (int i = 1; i <= n; ++i) {
        ans[i]=0;
      }
    } else if (v0.empty()) {
      for (int i = 1; i <= n; ++i) {
        if (i%2) ans[i]=v1.back();
        else ans[i]=0;
      }
    } else {
      for (int i = 1; i <= n; ++i) {
        if (i == 1) {
          ans[i]=v1.back();
        } else {
          if (i-(cur+1)<=(int)v0.size()) {
            int dt=i-(cur+1);
            ans[i] = v1.back()+sum[0][sz0]-sum[0][sz0-dt];
          } else {
            if (cur+2<sz1) {
              cur += 2;
              int dt=i-(cur+1);
              ans[i] = v1.back()+sum[0][sz0]-sum[0][sz0-dt];
            } else {
              if (sz1%2) ans[i] = v1.back()+sum[0][sz0];
              else ans[i]=0;
            }
          }
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%lld ", ans[i]);
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
