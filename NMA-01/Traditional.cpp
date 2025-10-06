#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;  
}

int main() {
    double a = 1, b = 2, mid, tol = 1e-6;
    int iteration = 0;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval! f(a) and f(b) must have opposite signs." << endl;
        return 0;
    }

    auto start = chrono::high_resolution_clock::now();

    while ((b - a) >= tol) {
        iteration++;
        mid = (a + b) / 2.0;

        if (f(mid) == 0.0)
            break;
        else if (f(mid) * f(a) < 0)
            b = mid;
        else
            a = mid;
    }

    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = stop - start;

    cout << fixed << setprecision(6);
    cout << "=== Traditional Bisection Method ===" << endl;
    cout << "Root: " << mid << endl;
    cout << "Iterations: " << iteration << endl;
    cout << "Time: " << duration.count() << " ms" << endl;

    return 0;
}
