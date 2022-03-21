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
#define M 202
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
vector<pair<int, pair<int,int>>> os;
int main() {
  cin>>n>>q>>m;
  for (int i= 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  os.clear();
  for (int i=  0; i < q; ++i) {
    int tp, l, r;
    scanf("%d%d%d", &tp,&l, &r);
    os.push_back(make_pair(tp, make_pair(l, r)));
  }
  vector<int> ans;
  ans.clear();
  for (int i = 1; i <= m; ++i) {
    int id;
    scanf("%d", &id);
    for (int j= os.size()-1; j >= 0; --j) {
      int tp = os[j].first;
      int l = os[j].second.first;
      int r = os[j].second.second;
      if (id >= l && id <= r) {
        if (tp == 1) {
          if (id > l) id--;
          else id = r;
        } else {
          id = l+r-id;
        }
      }
    }
    ans.push_back(a[id]);
  }
  for (int i = 0; i < ans.size(); ++i) {
    printf("%d", ans[i]);
    if (i < ans.size()-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
