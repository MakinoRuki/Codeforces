
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
#define N 2000005
#define M 505
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
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int h;
    int p;
  //  int x,y;
    scanf("%d%d%d%d", &n, &k, &p, &m);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    set<pair<int,int>> ss;
    ss.clear();
    deque<pair<int,int>> dq;
    for(int i =1; i <= n; ++i) {
      if (i <= k) ss.insert(make_pair(a[i], i));
      else dq.push_back(make_pair(a[i], i));
    }
    int cnt=0;
    while(m) {
      if (ss.find(make_pair(a[p], p)) != ss.end()) {
        if (m >= a[p]) {
          m -= a[p];
          cnt++;
          ss.erase(make_pair(a[p], p));
          dq.push_back(make_pair(a[p], p));
          if (!dq.empty()) {
            ss.insert(dq.front());
            dq.pop_front();
          }
        } else {
          break;
        }
      } else {
        auto pr = *ss.begin();
        if (m < pr.first) break;
        m -= pr.first;
        ss.erase(pr);
        dq.push_back(pr);
        if (!dq.empty()) {
          ss.insert(dq.front());
          dq.pop_front();
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}

