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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%d", &n);
    set<pair<int, int>> ss;
    ss.clear();
    ss.insert(make_pair(-n, 1));
    for (int i = 1; i <= n; ++i) {
      auto tp = *ss.begin();
      ss.erase(tp);
      int len = -tp.first;
      int id = tp.second;
      int id2 = id + (len+1)/2 - 1;
      a[id2] = i;
      int len1 = id2-id;
      int len2 = len-1-len1;
      if (len1 > 0) {
        ss.insert(make_pair(-len1, id));
      }
      if (len2 > 0) {
        ss.insert(make_pair(-len2, id2+1));
      }
    }
    for (int i = 1; i <= n; ++i) {
      printf("%d", a[i]);
      if (i < n) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
