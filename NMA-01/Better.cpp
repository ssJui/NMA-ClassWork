#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>
using namespace std;

double f(double x) {
    return x*x*x - x - 2;  
}

double improvedBisection(double a, double b, double tol, int &iterations) {
    double c = a, prev_c = c;
    iterations = 0;

    if (f(a) * f(b) >= 0) {
        cout << "Invalid interval!" << endl;
        return NAN;
    }

    do {
        prev_c = c;
        c = (a + b) / 2.0;
        iterations++;

        if (fabs(f(c)) < tol)
            break;

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(c - prev_c) >= tol);

    return c;
}

int main() {
    double a = 1, b = 2, tol = 1e-6;
    int iter;

    auto start = chrono::high_resolution_clock::now();
    double root = improvedBisection(a, b, tol, iter);
    auto stop = chrono::high_resolution_clock::now();
    chrono::duration<double, milli> duration = stop - start;

    cout << fixed << setprecision(6);
    cout << "=== Improved Bisection Method ===" << endl;
    cout << "Root: " << root << endl;
    cout << "Iterations: " << iter << endl;
    cout << "Time: " << duration.count() << " ms" << endl;

    return 0;
}
