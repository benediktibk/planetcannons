#include "LinearAlgebra.h"

using namespace std;

tuple<double, double, double> LinearAlgebra::add(const tuple<double, double, double> &a, const tuple<double, double, double> &b) {
    return make_tuple<double, double, double>(
        get<0>(a) + get<0>(b),
        get<1>(a) + get<1>(b),
        get<2>(a) + get<2>(b));
}

tuple<double, double, double> LinearAlgebra::subtract(const tuple<double, double, double> &a, const tuple<double, double, double> &b) {
    return make_tuple<double, double, double>(
        get<0>(a) - get<0>(b),
        get<1>(a) - get<1>(b),
        get<2>(a) - get<2>(b));
}

tuple<double, double, double> LinearAlgebra::multiply(double a, const tuple<double, double, double> &b) {
    return make_tuple<double, double, double>(
        a*get<0>(b),
        a*get<1>(b),
        a*get<2>(b));
}