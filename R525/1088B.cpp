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
#define M 10005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, k;
int a[N];
int main() {
  cin>>n>>k;
  for (int i =1 ; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  sort(a+1, a+n+1);
  //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
  int cnt=unique(a+1, a+n+1)-(a+1);
  //cout<<a[1]<<" "<<a[2]<<" "<<a[3]<<endl;
  //cout<<"cnt="<<cnt<<endl;
  for (int i = 1; i <= k; ++i) {
    if (i <= cnt) {
      if (i==1) cout<<a[i]<<endl;
      else cout<<a[i]-a[i-1]<<endl;
    } else {
      cout<<0<<endl;
    }
  }
  return 0;
}
