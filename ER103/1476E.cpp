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
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, m, k;
vector<int> edges[N];
unordered_map<string, int> mp;
int deg[N];
int main() {
  cin>>n>>m>>k;
  mp.clear();
  for (int i = 1; i <= n; ++i) {
    string s;
    cin>>s;
    mp[s] = i;
    deg[i] = 0;
  }
  bool ok = true;
  for (int i = 1; i <= m; ++i) {
    string s;
    int mt;
    cin>>s;
    scanf("%d", &mt);
    vector<int> ids;
    ids.clear();
    bool found=false;
    for (int j = 0; j < (1<<k); ++j) {
      string t = "";
      for (int j2 = 0; j2 < k; ++j2) {
        if ((1<<j2) & j) {
          t.push_back(s[j2]);
        } else {
          t += "_";
        }
      }
      if (mp.find(t) != mp.end()) {
        int id = mp[t];
        ids.push_back(id);
        if (id == mt) {
          found=true;
        }
      }
    }
    if (!found) {
      ok=false;
      continue;
    }
  //  cout<<"i="<<i<<endl;
    for (int j = 0; j < ids.size(); ++j) {
      if (ids[j] != mt) {
      //  cout<<"e="<<mt<<" "<<ids[j]<<endl;
        edges[mt].push_back(ids[j]);
        deg[ids[j]]++;
      }
    }
  }
  if (!ok) {
    cout<<"NO"<<endl;
    return 0;
  }
  vector<int> ans;
  ans.clear();
  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] == 0) {
      q.push(i);
    }
  }
  while(!q.empty()) {
    int cur=q.front();
    q.pop();
    ans.push_back(cur);
    for (int i = 0; i < edges[cur].size(); ++i) {
      int v = edges[cur][i];
      deg[v]--;
      if (deg[v] == 0) {
        q.push(v);
      }
    }
  }
  if (ans.size() < n) {
    cout<<"NO"<<endl;
  } else {
    cout<<"YES"<<endl;
    for (int i = 0; i < ans.size(); ++i) {
      printf("%d", ans[i]);
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
