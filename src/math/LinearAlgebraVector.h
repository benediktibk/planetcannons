#ifndef PLANETCANNONS_LINEARALGEBRAVECTOR_H
#define PLANETCANNONS_LINEARALGEBRAVECTOR_H

#include <tuple>

class LinearAlgebraVector {
    public:
        LinearAlgebraVector(double x, double y, double z);
        LinearAlgebraVector(const LinearAlgebraVector &rhs);

        double getX() const;
        double getY() const;
        double getZ() const;
        double norm() const;

        static bool equalsWithEpsilon(const LinearAlgebraVector &a, const LinearAlgebraVector &b, double epsilon);

        LinearAlgebraVector operator+(const LinearAlgebraVector &rhs) const;
        LinearAlgebraVector operator-(const LinearAlgebraVector &rhs) const;
        LinearAlgebraVector operator*(double rhs) const;
        operator std::tuple<double, double, double>() const;

    private:
        double m_x;
        double m_y;
        double m_z;
};

LinearAlgebraVector operator*(double a, const LinearAlgebraVector &b);

#endif