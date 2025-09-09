
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
#define N 600005
#define M 5002
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
int b[N];
vector<int> v[N];
int main() {
 // freopen("data.txt", "r", stdin);
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
      v[i].clear();
    }
    for (int i =1; i <= n; ++i) {
      v[b[i]].push_back(i);
    }
    bool ok=true;
    for (int i= 1; i <= n; ++i) {
      int sz=(int)v[i].size();
      if (sz==0) continue;
      if (sz >= i && ((sz%i) == 0)) {
        continue;
      }
      ok=false;
      break;
    }
    if (!ok) puts("-1");
    else {
      int cur=1;
      for (int i = 1; i <= n; ++i) {
        int sz=(int)v[i].size();
        if (sz==0) continue;
        int id=0;
        for (int j = 1; j <= sz/i; ++j) {
          for (int k = 1; k <= i; ++k) {
            a[v[i][id++]] = cur;
          }
          cur++;
        }
      }
      for (int i = 1; i <= n; ++i) {
        printf("%d ", a[i]);
      }
      cout<<endl;
    }
  }

  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
} 
