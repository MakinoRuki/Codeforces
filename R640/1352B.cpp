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
    vector<int> ans;
    ans.clear();
    if (n > k-1 && (n-(k-1))%2) {
      for (int i = 1; i < k; ++i) {
        ans.push_back(1);
      }
      ans.push_back(n-(k-1));
    } else if (n > 2*(k-1) && (n-2*(k-1))%2==0) {
      for (int i =1; i < k; ++i) {
        ans.push_back(2);
      }
      ans.push_back(n-2*(k-1));
    }
    if (ans.empty()) {
      cout<<"NO"<<endl;
    } else {
      cout<<"YES"<<endl;
      for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i];
        if (i<ans.size()-1) cout<<" ";
        else cout<<endl;
      }
    }
  }
  return 0;
}
