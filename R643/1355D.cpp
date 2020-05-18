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
#define N 300005
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, s;
int main() {
  cin>>n>>s;
  if (2*n > s) {
    cout<<"NO"<<endl;
  } else {
    cout<<"YES"<<endl;
    for (int i = 1; i < n; ++i) {
      cout<<2<<" ";
    }
    cout<<s-2*(n-1)<<endl;
    cout<<1<<endl;
  }
  return 0;
}
