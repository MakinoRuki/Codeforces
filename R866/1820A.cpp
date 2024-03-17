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
#include <list>
#define N 300005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    vector<pair<int,int>> v;
    v.clear();
    int cur=-1,cnt=0;
    for (int i = 0; i < s.size(); ++i) {
      if (i == 0 || s[i] == s[i-1]) {
        if (s[i] == '^') cur=1;
        else cur=0;
        cnt++;
      } else {
        v.push_back(make_pair(cur, cnt));
        if (s[i] == '^') cur=1;
        else cur=0;
        cnt=1;
      }
    }
    if (cnt > 0) {
      v.push_back(make_pair(cur, cnt));
    }
    int tot=0;
    if (v.size() == 1) {
      if (v[0].first == 0) {
        tot += 2 + v[0].second-1;
      } else {
        if (v[0].second==1) tot++;
      }
    } else {
      if (v[0].first == 0) tot++;
      if (v.back().first == 0) tot++;
      for (int i = 0; i < v.size(); ++i) {
        if (v[i].first == 0) tot += v[i].second-1;
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
