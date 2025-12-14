
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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &k);
    set<int> ss;
    ss.clear();
    set<int> st;
    st.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    vector<int> v(ss.begin(), ss.end());
    bool ok=true;
    vector<int> ans;
    ans.clear();
    for (auto x : v) {
      if (st.find(x) !=st.end()) {
        continue;
      }
      if (k/x > n) {
        if (st.find(x) == st.end()) {
          ok=false;
          break;
        }
        continue;
      }
      int i;
      for (i = x; i <= k/x*x; i += x) {
        if (ss.find(i) == ss.end()) {
          break;
        }
      }
      if (i > k/x*x) {
        ans.push_back(x);
        for (int j = x; j <= k/x*x; j += x) {
          st.insert(j);
        }
      } else {
        if (st.find(x) == st.end()) {
          ok=false;
          break;
        }
      }
    }
    if (!ok) puts("-1");
    else {
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d ", ans[i]);
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
