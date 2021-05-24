#ifndef PLANETCANNONS_LINEARALGEBRAVECTOR_H
#define PLANETCANNONS_LINEARALGEBRAVECTOR_H

#include <tuple>

class LinearAlgebraVector {
    public:
        LinearAlgebraVector(double x, double y, double z);

        double getX() const;
        double getY() const;
        double getZ() const;

    private:
        double m_x;
        double m_y;
        double m_z;
};

#endif