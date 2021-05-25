#ifndef PLANETCANNONS_GEOMETRYTRIANGLE_H
#define PLANETCANNONS_GEOMETRYTRIANGLE_H

#include "LinearAlgebraVector.h"
#include <vector>

class GeometryTriangle {
    public:
        GeometryTriangle(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree);

        const LinearAlgebraVector& getPointOne() const;
        const LinearAlgebraVector& getPointTwo() const;
        const LinearAlgebraVector& getPointThree() const;
        std::vector<GeometryTriangle> calculateMidPointSubTriangles() const;
        void shift(const LinearAlgebraVector &offset);

    private:
        LinearAlgebraVector m_pointOne;
        LinearAlgebraVector m_pointTwo;
        LinearAlgebraVector m_pointThree;
};

#endif