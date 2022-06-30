#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define N 300005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int par[N];
vector<int> edges[N];
int deg[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<pair<int,int>> ans;
    ans.clear();
    string s;
    cin>>s;
    int id1=-1, id2=-1;
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      deg[i+1] = 0;
      if (s[i] == '1') cnt++;
    }
    if (cnt==0 || cnt % 2) {
      puts("NO");
      continue;
    }
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0') {
        int j = (i-1+n)%n;
        ans.push_back(make_pair(i+1, j+1));
   //     cout<<"add="<<i+1<<" "<<j+1<<endl;
        deg[i+1]++;
        deg[j+1]++;
      }
    }
    vector<int> ids;
    ids.clear();
    for (int i = 0; i < n; ++i) {
      if (s[i] == '0' && (deg[i+1]%2)) {
        ids.push_back(i+1);
      } else if (s[i] == '1' && (deg[i+1]%2==0)) {
        ids.push_back(i+1);
      }
    }
//     for (int i = 0; i < ids.size(); ++i) {
//       cout<<"X="<<ids[i]<<endl;
//     }
    for (int i = 1; i < ids.size(); ++i) {
      ans.push_back(make_pair(ids[i], ids[0]));
    }
    puts("YES");
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d %d\n", ans[i].first, ans[i].second);
    }
  }
  return 0;
}
