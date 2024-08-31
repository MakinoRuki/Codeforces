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
#define N 300005
#define M 505
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, k, q;
int t;
int a[N];
int ad[M][2];
int mn[M][2];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    ll tot=0LL;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      tot += a[i];
    }
    if (tot % n) {
      puts("No");
      continue;
    }
    for (int i = 0; i <= 35; ++i) {
      ad[i][0] = ad[i][1] = 0;
      mn[i][0] = mn[i][1] = 0;
    }
    bool ok = true;
    for (int i = 1; i <= n; ++i) {
      ll dt = abs(a[i] - tot/n);
      vector<int> bs;
      bs.clear();
      for (int j = 0; j <= 30; ++j) {
        if (dt & (1<<j)) {
          bs.push_back(j);
        }
      }
      for (int j = 1; j < bs.size(); ++j) {
        if (bs[j] != bs[j-1] + 1) {
          ok=false;
          break;
        }
      }
      if (!ok) break;
      if (a[i] > tot/n) { 
        if (bs.size() == 1) {
          mn[bs[0]][0]++;
        } else {
          mn[bs.back()+1][1]++;
          ad[bs[0]][1]++;
        }
      } else if (a[i] < tot/n) {
        if (bs.size() == 1) {
          ad[bs[0]][0]++;
        } else {
          ad[bs.back()+1][1]++;
          mn[bs[0]][1]++;
        }
      }
    }
    if (!ok) {
      puts("No");
      continue;
    }
    int id0=33, id1=33;
    while(id0 >=0 || id1 >= 0) {
      while(id0 >= 0 && !mn[id0][0] && !mn[id0][1]) id0--;
      while(id1 >= 0 && !ad[id1][0] && !ad[id1][1]) id1--;
      if (id0 < 0 || id1 < 0) {
        break;
      }
      if (abs(id0-id1) > 1) {
        ok=false;
        break;
      }
      if (id0 == id1) {
        if (mn[id0][1]) mn[id0][1]--;
        else mn[id0][0]--;
        if (ad[id1][1]) ad[id1][1]--;
        else ad[id1][0]--;
      } else if (id0 < id1) {
        if (!mn[id0][0]) {ok=false;break;}
        mn[id0][0]--;
        ad[id0][1]++;
        if (ad[id1][1]) ad[id1][1]--;
        else ad[id1][0]--;
      } else {
        if (!ad[id1][0]) {ok=false;break;}
        ad[id1][0]--;
        mn[id1][1]++;
        if (mn[id0][1]) mn[id0][1]--;
        else mn[id0][0]--;
      }
    }
    if (!ok || id0>=0 || id1 >= 0) {
      puts("No");
    } else {
      puts("Yes");
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
 
