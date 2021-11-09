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
#define M 52
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
map<string, int> mp;
vector<pair<string,string>> msg;
vector<vector<int>> cdds;
int dp[N][N];
vector<int> getcs(string s) {
  vector<int> tmp;
  tmp.clear();
  string c = "";
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] >= 'A' && s[i] <= 'Z') {
      c.push_back(s[i]);
    } else if (s[i] >= 'a' && s[i] <= 'z') {
      c.push_back(s[i]);
    } else if (s[i] >= '0' && s[i] <= '9') {
      c.push_back(s[i]);
    } else {
    //  cout<<"tmp="<<c<<endl;
      if (!c.empty() && mp.find(c) != mp.end()) {
        tmp.push_back(mp[c]);
      }
      c.clear();
    }
  }
  if (!c.empty() && mp.find(c) != mp.end()) {
    tmp.push_back(mp[c]);
  }
  return tmp;
}
int dfs(int cur, int id) {
  if (dp[cur][id] != -1) {
    return dp[cur][id];
  }
  for (int i = 0; i < cdds[cur].size(); ++i) {
  //  if (cur == 0 && id == 0) cout<<"cdds[cur][i]="<<cdds[cur][i]<<endl; 
    if (id == cdds[cur][i]) return dp[cur][id] = -2;
  }
  if (cur == 0) {
    if (msg[cur].first != "?") {
      if (mp[msg[cur].first] == id) {
        return dp[cur][id] = id;
      } else {
        return dp[cur][id] = -2;
      }
    } else {
      return dp[cur][id] = id;
    }
  }
  if (msg[cur].first != "?" && mp[msg[cur].first] != id) {
    return dp[cur][id] = -2;
  }
  for (int i = 0; i < n; ++i) {
    if (id != i && dfs(cur-1, i) >= 0) {
      return dp[cur][id] = i;
    }
  }
  return dp[cur][id] = -2;
}
int main() {
  cin>>t;
  vector<string> ns;
  for (int cas=1; cas<=t; ++cas) {
    msg.clear();
    cdds.clear();
    ns.clear();
    mp.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      string s;
      cin>>s;
      mp[s] = i;
      ns.push_back(s);
    }
    scanf("%d", &m);
    string s;
    //getline(cin, s);
    cin.get();
    for (int i = 0; i < m; ++i) {
    //  cout<<"i="<<i<<endl;
      s.clear();
      getline(cin, s);
    //  cout<<s<<endl;
      int id;
      for (id = 0; id < s.size(); ++id) {
        if (s[id] == ':') {
          break;
        }
      }
    //  cout<<"i="<<i<<endl;
      msg.push_back(make_pair(s.substr(0, id), s.substr(id+1)));
    //  cout<<"i="<<i<<endl;
      cdds.push_back(getcs(s.substr(id+1)));
    //  cout<<"i="<<i<<endl;
    }
  //  cout<<cdds[0].size()<<endl;
  //  cout<<"???"<<endl;
    memset(dp, -1, sizeof(dp));
    int id=-1;
    if (msg.back().first != "?") {
      dfs(m-1, mp[msg.back().first]);
      if (dp[m-1][mp[msg.back().first]] >= 0) {
        id = mp[msg.back().first];
      }
    } else {
      for (int i = 0; i < n; ++i) {
        dfs(m-1, i);
        if (dp[m-1][i] >= 0) {
          id = i;
          break;
        }
      }
    }
    if (id < 0) {
      puts("Impossible");
    } else {
      int cur = id;
      for (int i = m-1; i >= 0; --i) {
        if (msg[i].first == "?") {
          msg[i].first = ns[cur];
        }
        cur = dp[i][cur];
      }
      for (int i = 0; i < m; ++i) {
        cout<<msg[i].first + ":" + msg[i].second<<endl;
      }
    }
  }
  return 0;
}
