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
#include <random>
#include <ctime>
#define N 2000
#define M 22
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int x;
bool check(string& s, vector<string>& v) {
 //cout<<"s="<<s<<endl;
  map<string, int> mp;
  mp.clear();
  for (int i =0; i < v.size(); ++i) {
    mp[v[i]]++;
  }
  string tmp="";
  for (int i = 0; i < s.size()-1; ++i) {
    tmp.push_back(s[i]);
   // cout<<"tmp="<<tmp<<endl;
    if (mp.find(tmp) != mp.end()) {
      mp[tmp]--;
      if (mp[tmp] == 0) mp.erase(tmp);
    }
  }
  tmp.clear();
  for (int i = s.size()-1; i > 0; --i) {
    tmp = s.substr(i, 1) + tmp;
   // cout<<"tmp="<<tmp<<endl;
    if (mp.find(tmp) != mp.end()) {
      mp[tmp]--;
      if (mp[tmp] == 0) mp.erase(tmp);
    }
  }
  if (mp.empty()) {
    int l = 0, r = s.size()-1;
    while(l < r) {
      if (s[l] != s[r]) {
        return false;
      }
      l++;
      r--;
    }
    return true;
  }
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    vector<string> v;
    v.clear();
    vector<string> v2;
    v2.clear();
    scanf("%d", &n);
    for (int i = 0; i < 2*n-2; ++i) {
      string s;
      cin>>s;
      v.push_back(s);
      int len = (int)s.size();
      if (len == n-1) {
        v2.push_back(s);
      }
    }
    string res=v2[0];
    res.push_back(v2[1].back());
    bool ok=false;
    ok |= check(res, v);
   // cout<<"ok="<<ok<<endl;
    res=v2[1];
    res.push_back(v2[0].back());
    ok |= check(res, v);
    if (ok) puts("YES");
    else puts("NO");
  }
  return 0;
}
