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
#define N 500005
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> ov;
    vector<int> ev;
    ov.clear();
    ev.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      if (a[i] %2) ov.push_back(a[i]);
      else ev.push_back(a[i]);
    }
    sort(ov.begin(), ov.end());
    sort(ev.begin(), ev.end());
    if (ov.empty() || ev.empty()) {
      puts("0");
    } else {
      ll cur = ov.back();
      int i;
      for (i = 0; i < ev.size(); ++i) {
        if (cur < ev[i]) {
          break;
        }
        cur += ev[i];
      }
      if (i >= ev.size()) {
        printf("%d\n", (int)ev.size());
      } else {
        printf("%d\n", (int)ev.size() + 1);
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
