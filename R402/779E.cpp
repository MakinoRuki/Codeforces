#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#include <map>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
map<string, int> mp;
vector<string> ns;
vector<pair<string, pair<string,string>>> ops;
int check(int id, int v) {
  int tot=0;
  vector<int> tmp;
  tmp.clear();
  for (int i = 0; i < n; ++i) {
    if (ops[i].first == "") {
      tmp.push_back(ops[i].second.first[id]-'0');
      tot += tmp[i];
   //   if (id == 0) cout<<"v="<<v<<" "<<i<<" "<<mp[ns[i]]<<" "<<tot<<endl;
    } else {
      int v1 = (ops[i].second.first == ""  ? v : tmp[stoi(ops[i].second.first)]);
      int v2 = (ops[i].second.second == "" ? v : tmp[stoi(ops[i].second.second)]);
      if (ops[i].first == "AND") {
        tmp.push_back(v1 & v2);
        tot += v1 & v2;
      } else if (ops[i].first == "OR") {
        tmp.push_back(v1 | v2);
        tot += v1 | v2;
      } else {
        tmp.push_back(v1 ^ v2);
        tot += v1 ^ v2;
      }
    //  if (id == 0) cout<<"v="<<v<<" "<<i<<" "<<mp[ns[i]]<<" "<<tot<<endl;
    }
  }
  return tot;
}
int main() {
  cin>>n>>m;
  string s;
  getline(cin,s);
  mp.clear();
  ops.clear();
  ns.clear();
  for (int i = 1; i <= n; ++i) {
    getline(cin, s);
    int cnt=0;
    int j = 0;
    string name="";
    while(j < s.size()) {
      if (s[j] == ' ') cnt++;
      else if (cnt==0) {
        name.push_back(s[j]);
      }
      if (cnt == 2) break;
      j++;
    }
    mp[name] = i-1;
    j++;
    if (s[j] >= '0' && s[j] <= '1') {
      string res = s.substr(j);
      ops.push_back(make_pair("", make_pair(res, "")));
    } else {
      string res1="",res2="";
      string op="";
      int cnt=0;
      while(j < s.size()) {
        if (s[j] == ' ') {
          cnt++;
        } else {
          if (cnt == 0) {
            res1.push_back(s[j]);
          } else if (cnt == 1) {
            op.push_back(s[j]);
          } else {
            res2.push_back(s[j]);
          }
        }
        j++;
      }
      string x = (res1 == "?" ? "" : to_string(mp[res1]));
      string y = (res2 == "?" ? "" : to_string(mp[res2]));
      ops.push_back(make_pair(op, make_pair(x, y)));
    }
  }
  string ans1="",ans2="";
  for (int i = 0; i < m; ++i) {
    int r0, r1;
    r0 = check(i, 0);
    r1 = check(i, 1);
    if (r0 == r1) {
      ans1.push_back('0');
      ans2.push_back('0');
    } else {
      if (r0 > r1) {
        ans1.push_back('1');
        ans2.push_back('0');
      } else {
        ans1.push_back('0');
        ans2.push_back('1');
      }
    }
  }
  cout<<ans1<<endl;
  cout<<ans2<<endl;
  return 0;
}
