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
int t;
ll a,b,n;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>a>>b>>n;
    int cnt=0;
    while(max(a,b) <= n) {
      if (a<=b) {
        a+=b;
      } else {
        b += a;
      }
      cnt++;
    }
    cout<<cnt<<endl;
  }
  return 0;
}
