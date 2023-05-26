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
#define N 200005
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
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    n = (int)s.size();
    int pre = -1;
    vector<int> ids;
    ids.clear();
    for (int i = 0; i < n; ++i) {
      if (s[i] != '?') {
        if (!ids.empty()) {
          if (pre >= 0) {
            for (int j = 0; j < ids.size(); ++j) {
              s[ids[j]] = pre+'0';
            }
          } else {
            for (int j = 0; j < ids.size(); ++j) {
              s[ids[j]] = s[i];
            }
          }
          ids.clear();
        }
        pre = s[i]-'0';
      } else {
        ids.push_back(i);
      }
    }
    if (!ids.empty()) {
      if (pre >= 0) {
        for (int i = 0; i < ids.size(); ++i) {
          s[ids[i]] = pre+'0';
        }
      } else {
        for (int i = 0; i < ids.size(); ++i) {
          s[ids[i]] = '1';
        }
      }
    }
    cout<<s<<endl;
  }
  return 0;
}
