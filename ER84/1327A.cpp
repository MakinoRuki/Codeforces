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
#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
int t;
ll n, k;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n>>k;
		ll det = n-k;
		if (det>=0 && det%2==0) {
			if (det>=k*(k-1)) {
				cout<<"YES"<<endl;
			} else {
				cout<<"NO"<<endl;
			}
		} else {
			cout<<"NO"<<endl;
		}
	}
  return 0;
}
