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
#define N 200005
#define M 635
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
int n, m, k, q;
int t;
int a[N];
int deg[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    vector<int> ids;
    ids.clear();
    string tmp="";
    for (int i = 0; i < n; ++i) {
      while(!ids.empty() && s[i] > s[ids.back()]) {
        ids.pop_back();
        tmp.pop_back();
      }
      ids.push_back(i);
      tmp.push_back(s[i]);
    }
    sort(tmp.begin(), tmp.end());
    for (int i = 0; i < tmp.size(); ++i) {
      s[ids[i]] = tmp[i];
    }
    int i;
    for (i = 1; i < n; ++i) {
      if (s[i] < s[i-1]) {
        break;
      }
    }
    if (i < n) {
      puts("-1");
    } else {
      int cnt=0;
      for (int i = 0; i < tmp.size(); ++i) {
        if (tmp[i] != tmp.back()) {
          cnt++;
        }
      }
      printf("%d\n", cnt);
    }
  }
  return 0;
}
