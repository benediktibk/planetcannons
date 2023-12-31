#include "GeometryTriangle.h"
#include "GeometryStraight.h"

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

void GeometryTriangle::setPointOne(const LinearAlgebraVector& point) {
    m_pointOne = point;
}

void GeometryTriangle::setPointTwo(const LinearAlgebraVector& point) {
    m_pointTwo = point;
}

void GeometryTriangle::setPointThree(const LinearAlgebraVector& point) {
    m_pointThree = point;
}

std::vector<GeometryTriangle> GeometryTriangle::calculateMidPointSubTriangles() const {
    std::vector<GeometryTriangle> result;
    GeometryStraight edgeOne(m_pointOne, m_pointTwo);
    GeometryStraight edgeTwo(m_pointTwo, m_pointThree);
    GeometryStraight edgeThree(m_pointOne, m_pointThree);
    auto midPointOne = edgeOne.getMidPoint();
    auto midPointTwo = edgeTwo.getMidPoint();
    auto midPointThree = edgeThree.getMidPoint();
    result.push_back(GeometryTriangle(m_pointOne, midPointOne, midPointThree));
    result.push_back(GeometryTriangle(midPointOne, m_pointTwo, midPointTwo));
    result.push_back(GeometryTriangle(midPointThree, midPointTwo, m_pointThree));
    result.push_back(GeometryTriangle(midPointOne, midPointTwo, midPointThree));
    return result;
}

void GeometryTriangle::shift(const LinearAlgebraVector &offset) {
    m_pointOne = m_pointOne + offset;
    m_pointTwo = m_pointTwo + offset;
    m_pointThree = m_pointThree + offset;
}