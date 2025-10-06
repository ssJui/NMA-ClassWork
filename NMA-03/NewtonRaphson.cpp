#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return pow(x, 5) - 3*x + 5;
}

double df(double x) {
    return 5*pow(x, 4) - 3;
}

void newtonRaphson(double initialGuess, double tolerance) {
    double correction = f(initialGuess) / df(initialGuess);
    while (abs(correction) >= tolerance) {
        correction = f(initialGuess) / df(initialGuess);
        initialGuess = initialGuess - correction;
    }
    cout << "Root is " << initialGuess << endl;
}

int main() {
    double guess;
    cout << "Enter initial guess: ";
    cin >> guess;

    double tolerance = 1e-3;
    newtonRaphson(guess, tolerance);
}
