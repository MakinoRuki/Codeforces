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
#define M 52
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m, k;
int q;
int x[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    string s;
    cin>>s;
    bool found=false;
    n = (int)s.size();
    for (int i = 0; i < n-1; ++i) {
      int d1 = s[i]-'0';
      int d2 = s[i+1] - '0';
      if (d1 + d2 >= 10) {
        found=true;
      }
    }
    if (found) {
      int id = -1;
      for (int i = 0; i < n-1; ++i) {
        int d1 = s[i]-'0';
        int d2 = s[i+1] - '0';
        if (d1 + d2 >= 10) {
          id = i;
        }
      }
      int d1 = s[id]-'0';
      int d2 = s[id+1] - '0';
      d1 += d2;
      s[id] = d1/10+'0';
      s[id+1] = d1%10+'0';
    } else {
      int d1 = s[0]-'0';
      int d2 = s[1] - '0';
      d1 += d2;
      string tmp = "";
      tmp.push_back(d1+'0');
      s = tmp + s.substr(2);
    }
    cout<<s<<endl;
  }
  return 0;
}
