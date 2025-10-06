#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return 4*x*x + 3*x - 3;
}

double findTrueRoot(double lower, double upper) {
    double root1 = (-3 + sqrt(57.0)) / 8.0;
    double root2 = (-3 - sqrt(57.0)) / 8.0;

    if (root1 >= min(lower, upper) && root1 <= max(lower, upper)) return root1;
    else if (root2 >= min(lower, upper) && root2 <= max(lower, upper)) return root2;
    else return NAN;
}

void bisectionMethod(double lower, double upper, double tolerance, double trueRoot) {
    if (f(lower) * f(upper) > 0) {
        cout << "No root found in the interval" << endl;
        return;
    }

    double intervalWidth = abs(upper - lower);
    double mid;

    while (intervalWidth >= tolerance) {
        mid = (lower + upper) / 2;
        double truePercentError = fabs((trueRoot - mid) / trueRoot) * 100;
        cout << "Mid = " << mid << " , True % Error = " << truePercentError << "%" << endl;

        if (f(mid) == 0.0) return;
        else if (f(lower) * f(mid) < 0) upper = mid;
        else lower = mid;

        intervalWidth = abs(upper - lower);
    }
}

void falsePositionMethod(double lower, double upper, double tolerance, double trueRoot) {
    if (f(lower) * f(upper) > 0) {
        cout << "No root found in the interval" << endl;
        return;
    }

    double intervalWidth = abs(upper - lower);
    double root;

    while (intervalWidth >= tolerance) {
        root = (lower * f(upper) - upper * f(lower)) / (f(upper) - f(lower));
        double truePercentError = fabs((trueRoot - root) / trueRoot) * 100;
        cout << "Root = " << root << " , True % Error = " << truePercentError << "%" << endl;

        if (f(root) == 0.0) return;
        else if (f(lower) * f(root) < 0) upper = root;
        else lower = root;

        intervalWidth = abs(upper - lower);
    }
}

int main() {
    double lowerBound, upperBound;
    cout << "Enter interval [lower upper]: ";
    cin >> lowerBound >> upperBound;

    double tolerance = 1e-4;
    double trueRoot = findTrueRoot(lowerBound, upperBound);

    if (isnan(trueRoot)) {
        cout << "No known root lies within the interval" << endl;
        return 1;
    }

    cout << "Bisection Method:" << endl;
    bisectionMethod(lowerBound, upperBound, tolerance, trueRoot);

    cout << "Regular False Position Method:" << endl;
    falsePositionMethod(lowerBound, upperBound, tolerance, trueRoot);

    return 0;
}
