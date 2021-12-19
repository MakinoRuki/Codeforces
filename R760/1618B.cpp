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
#define N 500005
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k;
int t;
string s;
int a[N];
bool check(vector<string>& v) {
  for (int i = 1; i < v.size(); ++i) {
    if (v[i][0] != v[i-1][1]) return false;
  }
  return true;
}
void print(vector<string>& v) {
  string ans=v[0];
  for (int i = 1; i < v.size(); ++i) {
    ans.push_back(v[i][1]);
  }
  cout<<ans<<endl;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    vector<string> bs;
    bs.clear();
    for (int i = 0; i < n-2; ++i) {
      cin>>s;
      bs.push_back(s);
    }
    for (int i = 0; i < n-1; ++i) {
      vector<string> v;
      v.clear();
      if (i == 0) {
        string tmp="";
        tmp.push_back('a');
        tmp.push_back(bs[0][0]);
        v.push_back(tmp);
        for (int j = 0; j < i; ++j) {
          v.push_back(bs[j]);
        }
        for (int j = i; j < bs.size(); ++j) {
          v.push_back(bs[j]);
        }
        if (check(v)) {
          print(v);
          break;
        }
        tmp.clear();
        tmp.push_back('b');
        tmp.push_back(bs[0][0]);
        v.clear();
        v.push_back(tmp);
        for (int j = 0; j < i; ++j) {
          v.push_back(bs[j]);
        }
        for (int j = i; j < bs.size(); ++j) {
          v.push_back(bs[j]);
        }
        if (check(v)) {
          print(v);
          break;
        }
      } else if (i == n-2) {
        string tmp="";
        tmp.push_back(bs.back()[1]);
        tmp.push_back('a');
        for (int j = 0; j < i; ++j) {
          v.push_back(bs[j]);
        }
        for (int j = i; j < bs.size(); ++j) {
          v.push_back(bs[j]);
        }
        v.push_back(tmp);
        if (check(v)) {
          print(v);
          break;
        }
        tmp.clear();
        tmp.push_back(bs.back()[1]);
        tmp.push_back('b');
        v.clear();
        for (int j = 0; j < i; ++j) {
          v.push_back(bs[j]);
        }
        for (int j = i; j < bs.size(); ++j) {
          v.push_back(bs[j]);
        }
        v.push_back(tmp);
        if (check(v)) {
          print(v);
          break;
        }
      } else {
        for (int j = 0; j < i; ++j) {
          v.push_back(bs[j]);
        }
        string tmp="";
        tmp.push_back(bs[i-1][1]);
        tmp.push_back(bs[i][0]);
        v.push_back(tmp);
        for (int j = i; j < bs.size(); ++j) {
          v.push_back(bs[j]);
        }
        if (check(v)) {
          print(v);
          break;
        }
      }
    }
  }
  return 0;
}
