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
#include <random>
#include <ctime>
#include <list>
#include <stack>
#include <bitset>
#include <chrono>
#define N 200005
#define M 2010
#define eps 1e-7
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
const int inf = 1000000010;
//const __int128 hmod = 212370440130137957LL;
//srand((unsigned)time(0)); 
const int base=337;
int n, m, q;
int k;
int t;
int main() {
  cin>>t;
  for (int cas=1; cas<=t; ++cas) {
      int d;
      scanf("%d%d", &n, &d);
      vector<int> v;
      v.clear();
      v.push_back(1);
      if (d == 5) v.push_back(5);
      if (n >= 9) {
          v.push_back(3);
          v.push_back(7);
          v.push_back(9);
      } else {
          ll fn=1LL;
          for (int i = 1; i <= n; ++i) {
              fn = fn*(ll)i;
          }
        //  cout<<"fn="<<fn<<endl;
          if (((d*fn)%3)==0) v.push_back(3);
          if (((d*fn)%9)==0) v.push_back(9);
          vector<int> vv={0,1,4,6,5,2};
        //  cout<<"v="<<fn%6<<" "<<v[fn%6]<<" "<<v[fn%6]*(d%7)<<" "<<(v[fn%6]*(d%7))<<endl;
          ll res=(vv[fn%6]*(d%7))%7;
        //  cout<<"res="<<res<<endl;
          if (res==0) {
              v.push_back(7);
          }
      }
      sort(v.begin(), v.end());
      for (int i = 0; i < v.size(); ++i) {
          printf("%d ", v[i]);
      }
      cout<<endl;
  }
  // cin>>n;
  // srand((unsigned)time(0)); 
  // for (int i = 1; i <= n; ++i) {
  //   printf("%d ", rand()%n+1);
  // }
  // cout<<endl;
  return 0;
}
