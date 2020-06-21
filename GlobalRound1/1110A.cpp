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
#define N 1005
#define M 100005
#define inf 1000000000
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int b, k;
int main() {
  cin>>b>>k;
  int odd = 0, even = 0;
  int ak = 0;
  for (int i = 1; i <= k; ++i) {
    int a;
    scanf("%d", &a);
    if (a%2) {
      odd++;
    } else {
      even++;
    }
    if (i == k) ak = a;
  }
  if (b%2) {
    if (odd%2) cout<<"odd"<<endl;
    else cout<<"even"<<endl;
  } else {
    if (ak % 2) cout<<"odd"<<endl;
    else cout<<"even"<<endl;
  }
  return 0;
}
