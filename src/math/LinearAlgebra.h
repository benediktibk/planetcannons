#ifndef PLANETCANNONS_LINEARALGEBRA_H
#define PLANETCANNONS_LINEARALGEBRA_H

#include <tuple>

class LinearAlgebra {
    public:
        static std::tuple<double, double, double> add(const std::tuple<double, double, double> &a, const std::tuple<double, double, double> &b);

        static std::tuple<double, double, double> subtract(const std::tuple<double, double, double> &a, const std::tuple<double, double, double> &b);

        static std::tuple<double, double, double> multiply(double a, const std::tuple<double, double, double> &b);

        static double norm(const std::tuple<double, double, double> &a);
};

#endif