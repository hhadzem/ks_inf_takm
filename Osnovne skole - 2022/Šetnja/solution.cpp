#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i = 0 ; i < n; i++)
		cin >> arr[i];
	int maxi = INT_MIN, counter = 1;
	for(int i = 1; i < n; i++){
		if(arr[i] != arr[i-1])
			counter ++;
		else
			counter = 1;
		maxi = max(counter, maxi);
	}
	maxi = max(counter, maxi);
	cout << maxi << endl;
	return 0;
}
