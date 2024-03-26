#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

void t_zapad(vector<int> &conf) {
    int temp = conf[0];
    conf[0] = conf[1]; conf[1] = conf[2]; conf[2] = conf[3]; conf[3] = temp;
}

void t_istok(vector<int> &conf) {
    int temp = conf[0]; 
    conf[0] = conf[3]; conf[3] = conf[2]; conf[2] = conf[1]; conf[1] = temp;
}

void t_jug(vector<int> &conf) {
    int temp = conf[1]; 
    conf[1] = conf[5]; conf[5] = conf[3]; conf[3] = conf[4]; conf[4] = temp;
}

void t_sjever(vector<int> &conf) {
    int temp = conf[1];
    conf[1] = conf[4]; conf[4] = conf[3]; conf[3] = conf[5]; conf[5] = temp;
}

int main() {
    int M, N; 
    cin >> M >> N;
    
    vector<vector<int>> B(M, vector<int>(N));
    for(int i = 0; i < M; i++)
        for(int j = 0; j < N; j++)
            cin >> B[i][j];

    int start_x, start_y;
    cin >> start_x >> start_y;
    start_x--; start_y--;

    int k; 
    cin >> k;

    vector<char> arr(k);
    for(int i = 0 ; i < k; i++)
        cin >> arr[i];

    vector<int> values(6, 0);
    vector<int> conf{0, 1, 2, 3, 4, 5};
    values[1] += B[start_x][start_y];

    for(int i = 0 ; i < k; i++) {
        if(arr[i] == 'J') { t_jug(conf); start_x += 1; }
        else if(arr[i] == 'S') { t_sjever(conf); start_x -= 1; }
        else if(arr[i] == 'I') { t_istok(conf); start_y += 1; }
        else { t_zapad(conf); start_y -= 1; }
        values[conf[1]] += B[start_x][start_y];
    }    

    sort(values.rbegin(), values.rend());
    for(auto el : values)
        cout << el << endl;
    return 0;
}