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
int n;
int main() {
	cin>>t;
	for (int cas=1; cas<=t; ++cas) {
		cin>>n;
		if (n < 31) cout<<"NO"<<endl;
		else {
			cout<<"YES"<<endl;
			if (n==36) {
				cout<<5<<" "<<6<<" "<<10<<" "<<15<<endl;
			} else if (n==44) {
				cout<<6<<" "<<7<<" "<<10<<" "<<21<<endl;
			} else if (n==40) {
				cout<<6<<" "<<10<<" "<<15<<" "<<9<<endl;
			} else {
				cout<<6<<" "<<10<<" "<<14<<" "<<n-30<<endl;
			}
		}
	}
  return 0;
}
