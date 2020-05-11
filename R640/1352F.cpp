#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 8002
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n0, n1, n2;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n0>>n1>>n2;
    string ans="";
    for (int i = 1; i <= n2; ++i) {
      ans.push_back('1');
    }
    if (n2 || n1) ans.push_back('1');
    else ans.push_back('0');
    if (n1) {
      if (n1 % 2) {
        for (int i = 1; i <= n1; ++i) {
          if (i%2) ans.push_back('0');
          else ans.push_back('1');
        }
      } else {
        for (int i = 1; i < n1; ++i) {
          if (i%2) ans.push_back('0');
          else ans.push_back('1');
        }
      }
    }
    for (int i = 1; i <= n0; ++i) {
      ans.push_back('0');
    }
    if (n1 > 0 && (n1%2==0)) {
      ans.push_back('1');
    }
    cout<<ans<<endl;
  }
  return 0;
}
