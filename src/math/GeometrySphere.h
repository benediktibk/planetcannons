#ifndef PLANETCANNONS_GEOMETRYSPHERE_H
#define PLANETCANNONS_GEOMETRYSPHERE_H

#include "LinearAlgebraVector.h"
#include "GeometryTriangle.h"
#include <vector>

class GeometrySphere {
    public:
        GeometrySphere(const LinearAlgebraVector &center, double radius);

        LinearAlgebraVector calculatePoint(double theta, double phi) const;
        std::vector<GeometryTriangle> approximateWithTriangles(unsigned int searchDepth) const;

    private:
        std::vector<GeometryTriangle> approximateWithTrianglesRecursive(const std::vector<GeometryTriangle> &triangles, unsigned int searchDepth) const;

    private:
        LinearAlgebraVector m_center;
        double m_radius;
};

#endif