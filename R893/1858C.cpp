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
#define N 100005
#define M 100
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
int s[N];
int main() {
  cin>>t;
  int d;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<int> ans;
    ans.clear();
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      ss.insert(i);
    }
    while(!ss.empty()) {
      auto x = *ss.begin();
      while(x <= n) {
        ss.erase(x);
        ans.push_back(x);
        x*=2;
      }
    }
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
