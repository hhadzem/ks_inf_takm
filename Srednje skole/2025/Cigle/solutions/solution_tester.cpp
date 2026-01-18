#include "generator_specific.cpp"

#undef solve
#undef main
#define solve solveBruteForce
#define main mainBruteForce
#include "main_ST3_brute_force.cpp"
#undef main
#undef solve

int main(int argc, char** argv) {
    int N = 4;
    vector<int> c(N), h(N);
    testInit(argc, argv);
    while (true) {
        generate(c, h);
        if (solveReal(c, h) != solveBruteForce(c, h)) {
            cout << N << endl;
            for (auto col : c) cout << col << " ";
            cout << endl;
            for (auto hei : h) cout << hei << " ";
            cout << endl;
            break;
        }
    }
}