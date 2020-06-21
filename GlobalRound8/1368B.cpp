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
#define N 1002
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
ll k;
int main() {
  cin>>k;
  int len;
  vector<char> cs = {'c', 'o', 'd', 'e', 'f', 'o', 'r', 'c', 'e', 's'};
  for (len=10; len <= 400; ++len) {
    int det=len/10;
    int r = len%10;
    ll res=1LL;
    for (int j = 1; j <= r; ++j) {
      if (res >= k || res < 0) break;
      res = res*(det+1);
    } 
    for (int j = r+1; j <= 10; ++j) {
      if (res >= k || res < 0) break;
      res = res*(det);
    }
    if (res >= k) {
      break;
    }
  }
  int det=len/10;
  int r=len%10;
  string ans="";
  for (int i = 1; i <= 10; ++i) {
    int ub = (i <= r ? det+1 : det);
    for (int j = 1; j <= ub; ++j) {
      ans.push_back(cs[i-1]);
    }
  }
  cout<<ans<<endl;
  return 0;
}
