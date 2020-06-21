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
#define N 2005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 998244353LL;
int t, n;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    if (n==1) {
      cout<<"FastestFinger"<<endl;
      continue;
    }
    if (n== 2) {
      cout<<"Ashishgup"<<endl;
      continue;
    }
    int n1 = 0, n2 = 0;
    for (ll i = 2; i * i <= n; ++i) {
      if (n%i == 0) {
        while(n%i == 0) {
          if (i%2) n1++;
          else n2++;
          n/=i;
        }
      }
    }
    if (n > 1) {
      if (n%2) n1++;
      else n2++;
    }
    if (n2 == 0) {
      cout<<"Ashishgup"<<endl;
    } else if (n2 == 1) {
      if (n1 == 1) cout<<"FastestFinger"<<endl;
      else cout<<"Ashishgup"<<endl;
    } else {
      if (n1 > 0) cout<<"Ashishgup"<<endl;
      else cout<<"FastestFinger"<<endl;
    }
  }
  return 0;
}
