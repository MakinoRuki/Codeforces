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
#define N 102
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int n, m;
int a[N];
int main() {
  cin>>n;
  for (int i =1 ; i<=n;++i){
    scanf("%d",&a[i]);
  }
  sort(a+1,a+n+1);
  vector<int> os,es;
  os.clear();
  es.clear();
  for (int i = 1; i <= n; ++i) {
    if (i%2) os.push_back(a[i]);
    else es.push_back(a[i]);
  }
  reverse(es.begin(), es.end());
  for (int i = 0; i <es.size();++i){
    os.push_back(es[i]);
  }
  for (int i = 0; i < n; ++i) {
    printf("%d", os[i]);
    if (i < n-1) cout<<" ";
    else cout<<endl;
  }
  return 0;
}
