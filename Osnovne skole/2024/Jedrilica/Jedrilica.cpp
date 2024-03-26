#include<iostream>
#include<vector>
using namespace std;
int main() {
    int N; cin >> N;
    vector<int> arr(N);
    for(int i = 0 ; i < N; i++)
        cin >> arr[i];
    int result = 0;
    for(int i = 0; i < N - 1; i++) {
        int diff = max(arr[i], arr[i+1]) - min(arr[i], arr[i+1]);
        if(diff > 180) diff = 360 - diff;
        result += diff;
    }
    cout << result << endl;
    return 0;
}   