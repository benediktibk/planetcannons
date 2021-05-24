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

LinearAlgebraVector GeometrySphere::calculatePointFromDistanceOnSurface(const LinearAlgebraVector &startingPoint, double x, double y) const {
    double circumference = 2*m_radius*M_PI;
    x = std::fmod(x, circumference);
    y = std::fmod(y, circumference);
    auto startingPointInSphereCoordiantes = startingPoint - m_center;
    auto phiOld = acos(startingPointInSphereCoordiantes.getX()/m_radius);

    if (startingPointInSphereCoordiantes.getY() < 0) {
        phiOld = (-1) * phiOld;
    }

    auto additionalPhi = x/m_radius;
    auto phiNew = phiOld + additionalPhi;
    auto intermediatePoint = LinearAlgebraVector(m_radius*cos(phiNew), m_radius*sin(phiNew), startingPointInSphereCoordiantes.getZ());

    auto thetaOld = acos(intermediatePoint.getY()/m_radius);

    if (intermediatePoint.getZ() < 0) {
        thetaOld = (-1) * thetaOld;
    }

    auto additionalTheta = y/m_radius;
    auto thetaNew = thetaOld + additionalTheta;
    auto resultInSphereCoordinates = LinearAlgebraVector(intermediatePoint.getX(), m_radius*cos(thetaNew), m_radius*sin(thetaNew));
    return resultInSphereCoordinates + m_center;
}