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
int t, n;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
    cin>>n;
    vector<int> ans;
    ans.clear();
    for (int i = 1; i <= 10000; i*=10) {
      if ((n/i) % 10) {
        ans.push_back(((n/i)%10)*i);
      }
    }
    cout<<ans.size()<<endl;
    for (int i = 0; i < ans.size(); ++i) {
      cout<<ans[i];
      if (i < ans.size()-1) cout<<" ";
      else cout<<endl;
    }
  }
  return 0;
}
