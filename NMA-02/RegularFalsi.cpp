#include <bits/stdc++.h>
#define ll long long
using namespace std;

double f(double x) {
    return log(3*x) - 3;
}

void falsePosition(double lower, double upper, double tol) {
    if (f(lower) * f(upper) > 0) {
        cout << "No root found in the interval" << endl;
        return;
    }

    ll iter = 0;
    double error = abs(upper - lower);
    double root;

    while (error >= tol) {
        root = (lower * f(upper) - upper * f(lower)) / (f(upper) - f(lower));

        if (f(root) == 0.0) {
            cout << "Root is " << root << endl;
            return;
        } 
        else if (f(lower) * f(root) < 0) {
            upper = root;
        } 
        else {
            lower = root;
        }

        error = abs(upper - lower);
        iter++;
    }

    cout << "Approximate root is " << root << endl;
}

int main() {
    double l, u;
    cout << "Enter interval [lower upper]: ";
    cin >> l >> u;

    double tol = 1e-4;
    falsePosition(l, u, tol);
}
