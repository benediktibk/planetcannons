#ifndef PLANETCANNONS_GEOMETRYTSTRAIGHT_H
#define PLANETCANNONS_GEOMETRYTSTRAIGHT_H

#include "LinearAlgebraVector.h"

class GeometryStraight {
    public:
        GeometryStraight(const LinearAlgebraVector &start, const LinearAlgebraVector &end);

        const LinearAlgebraVector& getStart() const;
        const LinearAlgebraVector& getEnd() const;
        LinearAlgebraVector getMidPoint() const;

    private:
        LinearAlgebraVector m_start;
        LinearAlgebraVector m_end;
};

#endif