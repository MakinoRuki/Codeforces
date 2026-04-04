
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
#define N 200005
#define M 110
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const ll mod3 = 676767677;
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
int b[N];
vector<string> v;
int main() {
  // cin>>t;
  // for (int cas=1; cas<=t; ++cas) {
  // }
  // ll ans=1LL;
  // for (int i =1; i <= 500; ++i) {
  //   ans=ans*5813LL%9422LL;
  // }
  // cout<<ans<<endl;
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    int x,y;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &b[i]);
    }
    bool ok = true;
    for (int i = 1; i <= k; ++i) {
      set<int> ss;
      ss.clear();
      for (int j = i; j <= n; j += k) {
        ss.insert(a[j]);
      }
      int sz=(int)ss.size();
      if (sz > 1) {
        for (int j = i; j <= n; j += k) {
          if (b[j] != -1 && b[j] != a[j]) {
            ok=false;
            break;
          }
        }
        if (ok) b[i] = a[i];
      } else {
        set<int> ss2;
        ss2.clear();
        for (int j = i; j <= n; j += k) {
          if (b[j] != -1) ss2.insert(b[j]);
        }
        if ((int)ss2.size()>1) {
          ok=false;
          break;
        }
        if (ss2.size() == 1) {
          b[i] = *ss2.begin();
        }
      }
      if (!ok) break;
    }
 //   cout<<"ok??"<<ok<<endl;
    map<int,int> m1, m2;
    m1.clear();
    m2.clear();
    for (int i = 1; i <= k; ++i) {
      m1[a[i]]++;
      if (b[i] != -1) m2[b[i]]++;
    }
    for (auto pr : m2) {
      if (m1.find(pr.first) == m1.end() || pr.second > m1[pr.first]) {
        ok=false;
        break;
      }
    }
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}

