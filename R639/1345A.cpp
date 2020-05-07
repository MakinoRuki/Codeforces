#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <set>
#include <map>
#define N 100005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t, n, m;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n>>m;
    if (n==1 || m==1) {
      cout<<"YES"<<endl;
    } else {
      if (n==2 && m==2) {
        cout<<"YES"<<endl;
      } else {
        cout<<"NO"<<endl;
      }
    }
  }
  return 0;
}
