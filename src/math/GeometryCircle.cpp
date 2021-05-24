#include "GeometryCircle.h"
#include <cmath>

GeometryCircle::GeometryCircle(const LinearAlgebraVector &center, double radius) :
    m_center(center),
    m_radius(radius) {
}

LinearAlgebraVector GeometryCircle::calculatePoint(double angle) const {
    auto x = m_center.getX() + m_radius * cos(angle);
    auto y = m_center.getY() + m_radius * sin(angle);
    auto z = m_center.getZ();
    return LinearAlgebraVector(x, y, z);
}