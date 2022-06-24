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
#define N 500005
#define M 1005
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 2000000000;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    vector<pair<int,int>> sg;
    sg.clear();
    int cnt=0;
    for (int i = 0; i < n; ++i) {
      if (i == 0 || s[i] == s[i-1]) {
        cnt++;
      } else {
        sg.push_back(make_pair(cnt, s[i-1]-'0'));
        cnt = 1;
      }
    }
    if (cnt>0) {
      sg.push_back(make_pair(cnt, s[n-1]-'0'));
    }
    int tot=0;
    vector<pair<int,int>> stk;
    stk.clear();
    int i = 0;
    while(i < sg.size()) {
      if (!stk.empty() && sg[i].second == stk.back().second) {
        stk.back().first += sg[i].first;
      } else {
        stk.push_back(sg[i]);
      }
      if (stk.back().first % 2) {
        if (sg[i+1].first % 2) {
          tot++;
          sg[i+1].first--;
          stk.back().first++;
          if (sg[i+1].first > 0) {
            stk.push_back(sg[i+1]);
          }
          i += 2;
        } else {
          tot += 2;
          if (sg[i+1].first == 2) {
            stk.back().first += 2;
            i += 2;
          } else {
            stk.back().first--;
            sg[i+2].first++;
            stk.push_back(sg[i+1]);
            i += 2;
          }
        }
      } else {
        i++;
      }
    }
    printf("%d\n", tot);
  }
  return 0;
}
