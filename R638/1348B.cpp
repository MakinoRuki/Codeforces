#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#define N 105
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int a[N];
bool vis[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    set<int> ss;
    ss.clear();
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      ss.insert(a[i]);
    }
    if (ss.size() > k) {
      cout<<-1<<endl;
    } else {
      memset(vis, false, sizeof(vis));
      vector<int> ans;
      ans.clear();
      int i = 1;
      for (auto x : ss) {
        ans.push_back(x);
        vis[x] = true;
        if (x == a[i]) i++;
      }
      if (ans.size() < k) {
        for (int i = 1; i <= n; ++i) {
          if (ans.size()==k) break;
          if (!vis[i]) {
            ans.push_back(i);
            vis[i] = true;
          }
        }
      }
      int cur=k;
      while(true) {
        if (i > n) break;
        if (ans[cur-k] == a[i]) {
          i++;
        }
        ans.push_back(ans[cur-k]);
        cur++;
      }
      cout<<ans.size()<<endl;
      for (int i = 0; i < ans.size(); ++i) {
        printf("%d", ans[i]);
        if (i < ans.size()-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
