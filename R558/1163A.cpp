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
#define N 200005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int main() {
  cin>>n>>m;
  if (m<=1) {
    cout<<1<<endl;
  } else {
    if (n%2) {
      if (m<=n/2) cout<<m<<endl;
      else {
        int det = (m-(n+1)/2);
        cout<<n/2-det<<endl;
      }
    } else {
      if (m<=n/2) cout<<m<<endl;
      else {
        int det = (m-n/2);
        cout<<n/2-det<<endl;
      }
    }
  }
  return 0;
}
