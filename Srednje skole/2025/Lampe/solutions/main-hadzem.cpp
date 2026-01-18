#include<bits/stdc++.h>
using namespace std;
int main() {
    int N; cin >> N;
    int rem_ones = 0, past_zeros = 0;

    vector<int> arr(N);
    for(int i = 0; i < N; i++) {
        cin >> arr[i];    
        rem_ones += arr[i];
    }

    int result = rem_ones;
    for(int i = 0; i < N; i++) {
        rem_ones -= arr[i];
        past_zeros += (1 - arr[i]);
        result = min(result, rem_ones + past_zeros);
    }
    cout << result << endl;
    return 0;
}