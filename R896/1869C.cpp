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
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d", &n, &m);
    if (m == 1) {
      puts("0");
      for (int i = 1; i <= n; ++i) {
        cout<<0<<endl;
      }
      continue;
    }
    vector<vector<int>> v;
    v.clear();
    vector<int> tmp;
    tmp.clear();
    for (int j = 0; j < m; ++j) {
      tmp.push_back(j);
    }
    v.push_back(tmp);
    for (int i = 1; i <= min(m-1, n)-1; ++i) {
      tmp.clear();
      for (int j = 0; j < m; ++j) {
        tmp.push_back(v[i-1][(j+1)%m]);
      }
      v.push_back(tmp);
    }
    while(v.size() < n) {
      v.push_back(v.back());
    }
    printf("%d\n", min(n+1, m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        printf("%d ", v[i][j]);
      }
      cout<<endl;
    }
  }
  return 0;
}
