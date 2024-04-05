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
#define N 1000005
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
int id[28][28];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d%d%d", &n, &k, &m);
    string s;
    cin>>s;
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < k; ++j) {
        id[i][j] = inf;
      }
    }
    int cur=1;
    int cnt=0;
    for (int i = 0; i < m; ++i) {
      int c=s[i]-'a';
      if (id[cur][c] >= inf) {
        id[cur][c] = i;
        cnt++;
        if (cnt >= k) {
          cur++;
          cnt=0;
          if (cur > n) break;
        }
      }
    }
    int mx=0;
    for (int i = 0; i < k; ++i) {
      mx = max(mx, id[n][i]);
    }
    if (mx < inf) {
      puts("YES");
    } else {
      puts("NO");
      string ans="";
      for (int i = 1; i <= n; ++i) {
        mx=-1;
        int c=-1;
        for (int j = 0; j < k; ++j) {
          if (id[i][j] > mx) {
            mx=id[i][j];
            c=j;
          }
        }
        ans.push_back('a'+c);
      }
      cout<<ans<<endl;
    }
  }
  return 0;
}
