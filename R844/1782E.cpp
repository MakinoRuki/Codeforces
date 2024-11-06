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
#define M 325
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
int r1[N],r2[N];
int c1[N],c2[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d%d%d%d", &r1[i], &c1[i], &r2[i], &c2[i]);
      //线段处理：格子变端点
      c1[i]--;
    }
    //排序处理：只给下标排序
    vector<int> ids;
    ids.clear();
    for (int i = 1; i <= n; ++i) {
      ids.push_back(i);
    }
    sort(ids.begin(), ids.end(), [](const int& i, const int& j) {
      return c1[i] < c1[j];
    });
    set<pair<int,int>> ss;
    ss.clear();
    int p1=-1,p2=-1;
    ll ans=0LL;
    for (auto i : ids) {
      if (r1[i] == 1 && r2[i] == 2) {
        if (p1 >= c2[i] && p2 >= c2[i]) {
          r1[i]=r2[i]=c1[i]=c2[i]=0;
          continue;
        }
        if (p1 >= c2[i]) {
          r1[i] = 2;
        } else if (p2 >= c2[i]) {
          r2[i] = 1;
        } else {
          while(!ss.empty()) {
            auto pr = *ss.rbegin();
            if (pr.first >= c1[i]) {
              c2[pr.second]=c1[i];
              ss.erase(pr);
            } else {
              break;
            }
          }
          //求面积处理：只加delta。
          ans += (c2[i] - max(p1, c1[i])) + (c2[i] - max(p2, c1[i]));
          p1 = c2[i];
          p2 = c2[i];
          ss.insert(make_pair(c2[i], i));
          continue;
        }
      }
      if (r1[i] == 1) {
        c1[i] = max(p1, c1[i]);
        p1 = max(p1, c2[i]);
      } else {
        c1[i] = max(c1[i], p2);
        p2 = max(p2, c2[i]);
      }
      if (c1[i] < c2[i]) {
        ans += c2[i]-c1[i];
        ss.insert(make_pair(c2[i], i));
      }
    }
    printf("%lld\n", ans);
    for (int i = 1; i <= n; ++i) {
      c1[i]++;
      if (c1[i] <= c2[i]) {
        printf("%d %d %d %d\n", r1[i], c1[i], r2[i], c2[i]);
      } else {
        printf("0 0 0 0\n");
      }
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

