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
#define N 200005
//#define M 10005
#define inf 1000000000
#define pii pair<int, int>
using namespace std;
typedef long long ll;
const ll mod = 1000000007LL;
const ll mod2 = 998244353LL;
int n;
int main() {
	cin>>n;
	if (n<=2) {
		cout<<"No"<<endl;
	} else {
		cout<<"Yes"<<endl;
		if (n%2) {
			printf("1 %d\n", (n+1)/2);
			printf("%d", n-1);
			for (int i = 1; i < (n+1)/2; ++i) {
				printf(" %d", i);
			}
			for (int i = (n+1)/2+1; i <= n; ++i) {
				printf(" %d", i);
			}
			cout<<endl;
		} else {
			printf("2 %d %d\n", n/2, n/2+1);
			printf("%d", n-2);
			for (int i =1 ; i < n/2; ++i) {
				printf(" %d", i);
			}
			for (int i = n/2+2; i <= n; ++i) {
				printf(" %d", i);
			}
			cout<<endl;
		}
	}
	return 0;
}
