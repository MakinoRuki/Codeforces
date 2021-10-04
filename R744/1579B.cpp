#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#include <cmath>
#include <queue>
#define eps 1e-7
#define M 105
#define N 100
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t;
int n, m;
int a[N];
void getrev(int l, int r) {
  while(l < r) {
    swap(a[l], a[r]);
    l++;
    r--;
  }
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    vector<pair<int,int>> ans;
    ans.clear();
    for (int i = 1; i <= n; ++i) {
      int id=i;
      for (int j = i; j <= n; ++j) {
        if (a[j] < a[id]) {
          id = j;
        }
      }
      if (id == i) continue;
      ans.push_back(make_pair(i,id-i));
      getrev(i, id-1);
      getrev(id, n);
      getrev(i, n);
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d %d\n", ans[i].first, n, ans[i].second);
    }
  }
  return 0;
}
