#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <deque>
#define M 20005
#define N 100005
#define SZ 200000002
using namespace std;
typedef long long ll;
const int inf = 1000000000;
ll mod = 1000000007LL;
int w,l;
int a[N];
int sum[N];
int main() {
	cin>>w>>l;
	int tot=0;
	memset(sum, 0, sizeof(sum));
	for (int i =1; i < w; ++i) {
		scanf("%d", &a[i]);
		if (i<=l) {
			sum[i]=a[i];
		}
	}
	int j = 1;
	int i = l+1;
	while(j<w) {
		if (j+l>=w) {
			tot += sum[j];
			j++;
		} else {
			if (j>=i) {
				i++;
				continue;
			}
			if (j+l<i) {
				j++;
				continue;
			}
			if (sum[j]+sum[i]<=a[i]) {
				sum[i]+=sum[j];
				j++;
			} else {
				while(j+l>=i) {
					if (sum[j]+sum[i]<=a[i]) {
						sum[i]+=sum[j];
						break;
					}
					int det=a[i]-sum[i];
					sum[i]=a[i];
					sum[j]-=det;
					i++;
				}
				j++;
			}
		}
	}
	cout<<tot<<endl;
	return 0;
}
