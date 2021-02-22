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
#define M 21
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n;
vector<string> sv;
void dfs(int l, int r, int idx) {
  if (l >= r) return;
  int i;
  for (i = r-1; i >= l; --i) {
    if (idx<sv[i].size() && idx<sv[i+1].size() && sv[i][idx]>sv[i+1][idx]) {
      break;
    } else if (idx<sv[i].size() && idx >= sv[i+1].size()) {
      break;
    }
  }
  if (i >= l) {
    for (int j = i; j >= l; --j) {
      while(sv[j].size() > idx) {
        sv[j].pop_back();
      }
    }
  }
  int id = l;
  while(id <= r && sv[id].size() <= idx) {
    id++;
  }
  int id2=id;
  for (int i = id; i <= r; ++i) {
    if (sv[i][idx] != sv[id2][idx]) {
      dfs(id2, i-1, idx+1);
      id2 = i;
    }
  }
  if (id2 <= r) {
    dfs(id2, r, idx+1);
  }
}
int main() {
  cin>>n;
  sv.clear();
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    sv.push_back(s);
  }
  dfs(0, n-1, 1);
  for (int i = 0; i < n; ++i) {
    cout<<sv[i]<<endl;
  }
  return 0;
}
