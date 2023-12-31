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
    std::vector<GeometryTriangle> start;
    const double a = sqrt(3)*m_radius;
    const double h = a * sin(M_PI/3);

    // upper side
    start.push_back(GeometryTriangle(
        LinearAlgebraVector((-1)*a/2, (-1)*(h - m_radius), 0),
        LinearAlgebraVector(a/2, (-1)*(h - m_radius), 0),
        LinearAlgebraVector(0, 0, m_radius)));
    start.push_back(GeometryTriangle(
        LinearAlgebraVector(0, 0, m_radius),
        LinearAlgebraVector(a/2, (-1)*(h - m_radius), 0),
        LinearAlgebraVector(0, m_radius, 0)));
    start.push_back(GeometryTriangle(
        LinearAlgebraVector((-1)*a/2, (-1)*(h - m_radius), 0),
        LinearAlgebraVector(0, 0, m_radius),
        LinearAlgebraVector(0, m_radius, 0)));

    // lower side
    start.push_back(GeometryTriangle(
        LinearAlgebraVector((-1)*a/2, (-1)*(h - m_radius), 0),
        LinearAlgebraVector(a/2, (-1)*(h - m_radius), 0),
        LinearAlgebraVector(0, 0, (-1)*m_radius)));
    start.push_back(GeometryTriangle(
        LinearAlgebraVector(0, 0, (-1)*m_radius),
        LinearAlgebraVector(a/2, (-1)*(h - m_radius), 0),
        LinearAlgebraVector(0, m_radius, 0)));
    start.push_back(GeometryTriangle(
        LinearAlgebraVector((-1)*a/2, (-1)*(h - m_radius), 0),
        LinearAlgebraVector(0, 0, (-1)*m_radius),
        LinearAlgebraVector(0, m_radius, 0)));

    auto result = approximateWithTrianglesRecursive(start, searchDepth);

    for (auto triangle = result.begin(); triangle != result.end(); ++triangle) {
        triangle->shift(m_center);
    }

    return result;
}

std::vector<GeometryTriangle> GeometrySphere::approximateWithTrianglesRecursive(const std::vector<GeometryTriangle> &triangles, unsigned int searchDepth) const {
    if (searchDepth == 0) {
        return triangles;
    }

    std::vector<GeometryTriangle> result;

    for (auto triangle = triangles.begin(); triangle != triangles.end(); ++triangle) {
        auto subTriangles = triangle->calculateMidPointSubTriangles();
        result.insert(result.end(), subTriangles.begin(), subTriangles.end());
    }

    for (auto triangle = result.begin(); triangle != result.end(); ++triangle) {
        LinearAlgebraVector pointOne = triangle->getPointOne();
        LinearAlgebraVector pointTwo = triangle->getPointTwo();
        LinearAlgebraVector pointThree = triangle->getPointThree();

        pointOne = m_radius/pointOne.norm()*pointOne;
        pointTwo = m_radius/pointTwo.norm()*pointTwo;
        pointThree = m_radius/pointThree.norm()*pointThree;

        triangle->setPointOne(pointOne);
        triangle->setPointTwo(pointTwo);
        triangle->setPointThree(pointThree);
    }

    return approximateWithTrianglesRecursive(result, searchDepth - 1);
}