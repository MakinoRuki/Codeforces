#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 1005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, k;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>k;
    ll res;
    if (k%(n-1)) {
      res=k/(n-1)*n+k%(n-1);
    } else {
      res = k/(n-1)*n-1;
    }
    cout<<res<<endl;
  }
  return 0;
}
