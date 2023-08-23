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
#define M 100
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
    for (int i = n-1; i >= 0; --i) {
      a[n-1-i] = s[i]-'0';
    }
    a[n] = 0;
    int cur = -1;
    for (int i = 0; i < n; ++i) {
      if (a[i] >= 5) {
        a[i+1]++;
        cur = i+1;
      }
    }
    string ans="";
    if (a[n] == 0) {
      for (int i = n-1; i >= 0; --i) {
        if (i < cur) ans.push_back('0');
        else ans.push_back(a[i]+'0');
      }
    } else {
      for (int i = n; i >= 0; --i) {
        if (i < cur) ans.push_back('0');
        else ans.push_back(a[i]+'0');
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
