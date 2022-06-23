#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  scanf("%d%d", &n, &m);
  vector<pair<int,int>> es;
  es.clear();
  string s(m, '0');
  for (int i = 0; i < m; ++i) {
    s[i] = '1';
    cout<<"? "<<s<<endl;
    cout.flush();
    int res;
    scanf("%d", &res);
    es.push_back(make_pair(res, i));
    s[i] = '0';
  }
  sort(es.begin(), es.end());
  int tot=0;
  for (int i = 0; i < es.size(); ++i) {
    int w = es[i].first;
    int id = es[i].second;
    s[id] = '1';
    cout<<"? "<<s<<endl;
    cout.flush();
    int res;
    scanf("%d", &res);
    if (tot + w == res) {
      tot += w;
    } else {
      s[id] = '0';
    }
  }
  printf("! %d\n", tot);
  return 0;
}
