#ifndef PLANETCANNONS_GEOMETRYSPHERE_H
#define PLANETCANNONS_GEOMETRYSPHERE_H

#include "LinearAlgebraVector.h"

class GeometrySphere {
    public:
        GeometrySphere(const LinearAlgebraVector &center, double radius);

        LinearAlgebraVector calculatePoint(double theta, double phi) const;
        LinearAlgebraVector calculatePointFromDistanceOnSurface(const LinearAlgebraVector &startingPoint, double x, double y) const;

    private:
        LinearAlgebraVector m_center;
        double m_radius;
};

#endif