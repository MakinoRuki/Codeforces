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
#define N 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
string s;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n  == 3) {
      printf("%d %d %d\n", 3, 2, 1);
      printf("%d %d %d\n", 1, 3, 2);
      printf("%d %d %d\n", 3, 1, 2);
    } else {
      vector<vector<int>> ans;
      ans.clear();
      for (int i = 0; i < n; ++i) {
        ans.push_back({});
        for (int j = n-i; j >= 1; --j) {
          ans.back().push_back(j);
        }
        for (int j = n; j > n-i; --j) {
          ans.back().push_back(j);
        }
      }
      for (int i = 0; i < ans.size(); ++i) {
        for (int j = 0; j < ans[i].size(); ++j) {
          printf("%d", ans[i][j]);
          if (j < ans[i].size()-1) cout<<" ";
          else cout<<endl;
        }
      }
    }
  }
  return 0;
}
