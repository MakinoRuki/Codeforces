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
#define M 12
#define N 200
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int n, k;
string t;
int main() {
  cin>>t;
  n = (int)t.size();
  vector<vector<int>> ids(2);
  for (int i = 0; i < n; ++i) {
    ids[0].push_back(i);
    ids[1].push_back(i);
  }
//  cout<<"ids"<<ids.size()<<endl;
  vector<vector<vector<int>>> mp;
  mp.clear();
  mp.push_back(ids);
  // cout<<mp.size()<<endl;
  // cout<<mp[0].size()<<endl;
  // cout<<mp[0][0].size()<<endl;
  while(true) {
    bool ok = true;
    for (int i = 0; i < mp.size(); ++i) {
      if (mp[i][0].size() > 1) {
       // cout<<"sz-"<<mp[i][0].size()<<endl;
        ok=false;
        break;
      }
    }
    if (ok) {
      break;
    }
    string qs(n, 'a');
    for (int i = 0; i < mp.size(); ++i) {
      if (mp[i][0].size() > 1) {
        auto ids = mp[i][0];
        int sz = (int)ids.size();
      //  cout<<"sz="<<sz<<endl;
        if (sz <= 26) {
          for (int j = 0; j < ids.size(); ++j) {
            qs[ids[j]] = 'a'+j;
          }
        } else {
          int q = sz/26;
          int r = sz%26;
          int cur=0;
          for (int j = 0; j < 26; ++j) {
            for (int j2 = 0; j2 < q; ++j2) {
              qs[ids[cur+j2]] = 'a'+ j;
            }
            cur += q;
            if (j < r) {
              qs[ids[cur++]] = 'a'+j;
            }
          }
        }
      }
    }
    cout<<"? "<<qs<<endl;
    fflush(stdout);
    string res;
    cin>>res;
    vector<vector<vector<int>>> mp2;
    mp2.clear();
    for (int i = 0; i < mp.size(); ++i) {
    //  cout<<"i="<<i<<endl;
      if (mp[i][0].size() > 1) {
        auto ids = mp[i][0];
        auto ids2 = mp[i][1];
        vector<vector<int>> v(26);
        for (int j = 0; j < ids2.size(); ++j) {
          v[res[ids2[j]]-'a'].push_back(ids2[j]);
        }
        int cur=0;
        for (int j = 0; j < 26; ++j) {
          if (v[j].empty()) continue;
          int sz = (int)v[j].size();
        //  cout<<"j="<<j<<" "<<sz<<endl;
          vector<int> tmp;
          tmp.clear();
          for (int j2 = 0; j2 < sz; ++j2) {
            tmp.push_back(ids[cur++]);
          }
          mp2.push_back({tmp, v[j]});
        }
      } else {
      //  cout<<"i="<<i<<endl;
        mp2.push_back(mp[i]);
      }
    }
    mp = mp2;
  }
  string s = t;
  for (int i = 0; i < mp.size(); ++i) {
    int x = mp[i][0][0];
    int y = mp[i][1][0];
    s[x] = t[y];
  }
  cout<<"! "<<s<<endl;
  return 0;
}
