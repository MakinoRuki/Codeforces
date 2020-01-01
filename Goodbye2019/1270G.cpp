#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_set>
#define N 1000005
using namespace std;
typedef long long ll;
int t, n;
int a[N];
int vis[N];
int main() {
  //ios_base::sync_with_stdio(0);
  //cin.tie(nullptr);
  // freopen("data.txt", "r", stdin);
  // freopen("output.txt", "w", stdout);
  cin>>t;
  for (int cas=1; cas <= t; ++cas) {
    scanf("%d", &n);
    //cin>>n;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
      //cin>>a[i];
    }
    for (int i = 0; i <= n; ++i) {
      vis[i] = 0;
    }
    vector<int> ans;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        vis[i] = i;
        int cur = i-a[i];
        while(true) {
          if (vis[cur] == i) {
            break;
          }
          if (vis[cur]) break;
          vis[cur] = i;
          cur = cur-a[cur];
        }
        if (vis[cur] == i) {
          ans.clear();
          ans.push_back(cur);
          int nxt = cur-a[cur];
          while(nxt != cur) {
            ans.push_back(nxt);
            nxt = nxt-a[nxt];
          }
          break;
        }
      }
    }
    printf("%d\n", (int)ans.size());
    //cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      //cout<<ans[i];
      if (i < ans.size()-1) printf(" ");
      else printf("\n");
    }
  }
  return 0;
}
