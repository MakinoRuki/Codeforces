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
#define N 52
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m, a, b;
vector<string> mt;
int main() {
  cin>>t;
  for (int cas = 1; cas <= t; ++cas) {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    vector<string> ans(n, string(m, '0'));
    if (n*a != m * b) {
      cout<<"NO"<<endl;
    } else {
      //cout<<"YES"<<endl;
      int cnt[N];
      memset(cnt, 0, sizeof(cnt));
      bool ok = true;
      for (int i = 0; i < n; ++i) {
        int tot=0;
        for (int j = 0; j < m; ++j) {
          if (cnt[j] < b && tot < a) {
            ans[i][j] = '1';
            cnt[j]++;
            tot++;
          }
        }
        if (tot != a) {
          ok = false;
        }
      }
      for (int j = 0; j < m; ++j) {
        if (cnt[j] != b) ok = false;
      }
      if (!ok) {
        cout<<"NO"<<endl;
      } else {
        cout<<"YES"<<endl;
        for (int i = 0; i < n; ++i) {
          cout<<ans[i]<<endl;
        }
      }
    }
  }
  return 0;
}
