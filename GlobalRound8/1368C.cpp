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
int n;
int main() {
  cin>>n;
  vector<pair<int,int>> ans = {{0,0}, {-1,0}, {1,0},{0,1},{1,1}, {-1,-1},{0,-1}};
  for (int i = 2; i <= n; ++i) {
    ans.push_back(make_pair(i, i));
    ans.push_back(make_pair(i-1, i));
    ans.push_back(make_pair(i, i-1));
  }
  cout<<ans.size()<<endl;
  for (int i = 0; i < ans.size(); ++i){
    printf("%d %d\n", ans[i].first, ans[i].second);
  }
  return 0;
}
