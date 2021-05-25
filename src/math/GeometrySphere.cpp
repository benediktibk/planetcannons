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

std::vector<GeometryTriangle> GeometrySphere::approximateWithTriangles(unsigned int searchDepth) const {
    std::vector<GeometryTriangle> result;
    const double a = sqrt(3)*m_radius;
    const double h = a * sin(M_PI/3);

    result.push_back(GeometryTriangle(
        LinearAlgebraVector((-1)*a/2, (-1)*(h - 1), 0),
        LinearAlgebraVector(a/2, (-1)*(h - 1), 0),
        LinearAlgebraVector(0, 0, 1)));

    result.push_back(GeometryTriangle(
        LinearAlgebraVector(0, 0, 1),
        LinearAlgebraVector(a/2, (-1)*(h - 1), 0),
        LinearAlgebraVector(0, 1, 0)));

    result.push_back(GeometryTriangle(
        LinearAlgebraVector((-1)*a/2, (-1)*(h - 1), 0),
        LinearAlgebraVector(0, 0, 1),
        LinearAlgebraVector(0, 1, 0)));

    result.push_back(GeometryTriangle(
        LinearAlgebraVector((-1)*a/2, (-1)*(h - 1), 0),
        LinearAlgebraVector(a/2, (-1)*(h - 1), 0),
        LinearAlgebraVector(0, 0, -1)));

    result.push_back(GeometryTriangle(
        LinearAlgebraVector(0, 0, -1),
        LinearAlgebraVector(a/2, (-1)*(h - 1), 0),
        LinearAlgebraVector(0, 1, 0)));

    result.push_back(GeometryTriangle(
        LinearAlgebraVector((-1)*a/2, (-1)*(h - 1), 0),
        LinearAlgebraVector(0, 0, -1),
        LinearAlgebraVector(0, 1, 0)));

    return approximateWithTrianglesRecursive(result, searchDepth);
}

std::vector<GeometryTriangle> GeometrySphere::approximateWithTrianglesRecursive(const std::vector<GeometryTriangle> &triangles, unsigned int searchDepth) const {
    if (searchDepth == 0) {
        return triangles;
    }

    return triangles;
}