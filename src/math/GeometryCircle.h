#ifndef PLANETCANNONS_GEOMETRYCIRCLE_H
#define PLANETCANNONS_GEOMETRYCIRCLE_H

#include "LinearAlgebraVector.h"

class GeometryCircle {
    public:
        GeometryCircle(const LinearAlgebraVector &center, double radius);

        LinearAlgebraVector calculatePoint(double angle) const;

    private:
        LinearAlgebraVector m_center;
        double m_radius;
};

#endif