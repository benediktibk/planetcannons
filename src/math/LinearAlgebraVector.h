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
        static LinearAlgebraVector crossProduct(const LinearAlgebraVector &a, const LinearAlgebraVector &b);
        static double dotProduct(const LinearAlgebraVector &a, const LinearAlgebraVector &b);

        LinearAlgebraVector operator+(const LinearAlgebraVector &rhs) const;
        LinearAlgebraVector operator-(const LinearAlgebraVector &rhs) const;
        LinearAlgebraVector operator*(double rhs) const;
        LinearAlgebraVector operator/(double rhs) const;
        operator std::tuple<double, double, double>() const;
        operator std::tuple<float, float, float>() const;
        const LinearAlgebraVector& operator=(const LinearAlgebraVector &rhs);

    private:
        double m_x;
        double m_y;
        double m_z;
};

LinearAlgebraVector operator*(double a, const LinearAlgebraVector &b);

#endif