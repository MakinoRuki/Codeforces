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
#define N 1000005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    set<pair<int,int>> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(make_pair(a[i], i));
    }
    if (n == 1) {
      puts("0");
    } else if (((*ss.begin()).first == 1) && ((*ss.begin()).first != (*ss.rbegin()).first)) {
      puts("-1");
    } else {
      vector<pair<int,int>> ans;
      ans.clear();
      while((*ss.begin()).first != (*ss.rbegin()).first) {
        int id1=(*ss.begin()).second;
        int id2=(*ss.rbegin()).second;
        int x = (*ss.begin()).first;
        int y = (*ss.rbegin()).first;
        ss.erase(--ss.end());
        y = (y+x-1)/x;
        ans.push_back(make_pair(id2, id1));
        ss.insert(make_pair(y, id2));
      }
      printf("%d\n", (int)ans.size());
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d %d\n", ans[i].first, ans[i].second);
      }
    }
  }
  return 0;
}
