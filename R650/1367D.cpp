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
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int q;
string s;
int m;
int b[N];
int cnt[N];
bool vis[N];
int main() {
  cin>>q;
  //q = 1;
  for (int cas=1; cas<=q; ++cas) {
    cin>>s;
    cin>>m;
    memset(cnt, 0, sizeof(cnt));
    memset(vis, false, sizeof(vis));
    for (int i = 0; i < s.size(); ++i) {
      cnt[s[i]-'a']++;
    }
    for (int i = 1; i <= m; ++i) {
      scanf("%d", &b[i]);
      //cnt[b[i]-'a']++;
    }
  //  cout<<"ok"<<endl;
    string ans(m, ' ');
    vector<int> ids;
    ids.clear();
    int ub = 25;
    // cout<<"ok1"<<endl;
    // cout<<"m="<<m<<" "<<ans<<endl;
    while(true) {
       //cout<<"x="<<x<<endl;
      //cout<<"ok2"<<endl;
      vector<int> ids2;
      ids2.clear();
    //  if (x > 10) break;
      for (int i = 1; i <= m; ++i) {
        if (ans[i-1] == ' ') {
          int tot = 0;
          for (int j = 0; j < ids.size(); ++j) {
            tot += abs(ids[j]-i);
          }
          if (tot == b[i]) {
            ids2.push_back(i);
          }
        }
      }
     // cout<<"ok3="<<ids2.size()<<endl;
      if (ids2.empty()) {
        break;
      }
      int i;
      for (i = ub; i >= 0; --i) {
        if (!vis[i] && cnt[i] >= ids2.size()) {
          break;
        }
      }
      //cout<<"ok4="<<ids2.size()<<endl;
      for (int j = 0; j < ids2.size(); ++j) {
        ans[ids2[j]-1] = 'a' + i;
      }
      vis[i] = true;
      ub = i-1;
      for (int i = 0; i < ids2.size(); ++i) {
        ids.push_back(ids2[i]);
      }
      // cout<<"ok5="<<ids2.size()<<endl;
      // cout<<"ok6="<<ids2.size()<<endl;
      // cout<<"ok7="<<ids2.size()<<endl;
      //cout<<"x2="<<x<<endl;
    }
    cout<<ans<<endl;
  }
  return 0;
}
