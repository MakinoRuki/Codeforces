#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <cmath>
#define N 200005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n, m, k, q;
int t;
int a[N];
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    string s;
    cin>>s;
    string ans="";
    if (s[0] == '9') {
      int add = 0;
      for (int i = n-1; i >= 0; --i) {
        int d= s[i]-'0';
        int r = (d+add)%10;
        add+=d;
        if (r <= 1) {
          ans.push_back(1-r+'0');
          add += 1-r;
        } else {
          ans.push_back(11-r+'0');
          add += 11-r;
        }
        add/=10;
      }
      reverse(ans.begin(), ans.end());
    } else {
      for (int i = 0; i < n; ++i) {
        ans.push_back(9-(s[i]-'0')+'0');
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}
