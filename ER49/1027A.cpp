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
#define N 1000005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
ll mod2 = 998244353LL;
int t, n, m;
string s;
bool check(char a, char b) {
  if (a!='z' && b != 'z' && a+1==b+1) return true;
  if (a!='a' && b!='a' &&a-1==b-1) return true;
  if (a!='z' && b!='a' &&a+1==b-1) return true;
  if (a!='a' && b!='z' && a-1==b+1) return true;
  return false;
}
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>s;
    bool ok=true;
    for (int i = 0; i < n/2; ++i) {
      if (!check(s[i], s[n-1-i])) {
        ok=false;
        break;
      }
    }
    if (!ok) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
  }
  return 0;
}
