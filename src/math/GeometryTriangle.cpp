#include "GeometryTriangle.h"

GeometryTriangle::GeometryTriangle(const LinearAlgebraVector &pointOne, const LinearAlgebraVector &pointTwo, const LinearAlgebraVector &pointThree) :
    m_pointOne(pointOne),
    m_pointTwo(pointTwo),
    m_pointThree(pointThree) {
}

const LinearAlgebraVector& GeometryTriangle::getPointOne() const {
    return m_pointOne;
}

const LinearAlgebraVector& GeometryTriangle::getPointTwo() const {
    return m_pointTwo;
}

const LinearAlgebraVector& GeometryTriangle::getPointThree() const {
    return m_pointThree;
}