#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

void solve_o_nlogn(vector<int> &arr, int &n) {
	vector<int> diff;
	for(int i = 1; i < n; i++)
		if(arr[i] > arr[i-1])
			diff.push_back(arr[i] - arr[i-1]);
	sort(diff.begin(), diff.end());
	cout << (diff.size() < 2 ? 0 : diff[diff.size() - 2]) << endl;
}

void solve_o_n(vector<int> &arr, int &n) {
	vector<int> diff;
	int max_first = INT_MIN, max_second = INT_MIN;
	for(int i = 1; i < n; i++)
		if(arr[i] > arr[i-1]) {
			int diff = arr[i] - arr[i-1];
			if(diff >= max_first) {
				max_second = max_first;
				max_first = diff;
			} else if(diff > max_second) {
				max_second = diff;
			}
		}
	cout << (max_second == INT_MIN ? 0 : max_second) << endl;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n; cin >> n;
	vector<int> arr(n), diff;

	for(int i = 0; i < n; i++)
		cin >> arr[i];

	//solve_o_n(arr, n);
	solve_o_nlogn(arr, n);
	return 0;
}
