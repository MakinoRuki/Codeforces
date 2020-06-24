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
#define N 100005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int n,t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    scanf("%d", &n);
    if (n%2) cout<<"NO"<<endl;
    else {
      int x = (n-2)/2;
      if (x%2) cout<<"YES"<<endl;
      else cout<<"NO"<<endl;
    }
  }
  return 0;
}
