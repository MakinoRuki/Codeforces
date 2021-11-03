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
#define M 21
#define N 300005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, h;
int k;
int q;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    string s;
    cin>>s;
    vector<int> rk1;
    rk1.clear();
    vector<int> rk2;
    rk2.clear();
    for (int i =1 ; i <= n; ++i) {
      if (s[i-1] == 'R') {
        rk1.push_back(a[i]);
      } else {
        rk2.push_back(a[i]);
      }
    }
    sort(rk1.begin(), rk1.end());
    sort(rk2.begin(), rk2.end());
    bool ok = true;
    int id = 0;
    for (int i = 0; i <= n; ++i) {
      while(id < rk2.size() && rk2[id] <= i) {
        id++;
      }
      if (id > i) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    id = rk1.size()-1;
    for (int i = n+1; i >= 1; --i) {
      while(id >= 0 && rk1[id] >= i) {
        id--;
      }
      if (rk1.size()-1-id > n+1-i) {
        ok=false;
        break;
      }
    }
    if (!ok) {
      puts("NO");
      continue;
    }
    puts("YES");
    
  }  
  return 0;
}
