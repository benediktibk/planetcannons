#include "GeometrySphere.h"
#include <cmath>

GeometrySphere::GeometrySphere(const LinearAlgebraVector &center, double radius) :
    m_center(center),
    m_radius(radius) {
}

LinearAlgebraVector GeometrySphere::calculatePoint(double theta, double phi) const {
    auto x = m_center.getX() + m_radius * sin(theta) * cos(phi);
    auto y = m_center.getY() + m_radius * sin(theta) * sin(phi);
    auto z = m_center.getZ() + m_radius * cos(theta);
    return LinearAlgebraVector(x, y, z);
}