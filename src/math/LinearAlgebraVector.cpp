#include "LinearAlgebraVector.h"
#include <cmath>

LinearAlgebraVector::LinearAlgebraVector(double x, double y, double z) :
    m_x(x),
    m_y(y),
    m_z(z) {
}

LinearAlgebraVector::LinearAlgebraVector(const LinearAlgebraVector &rhs) :
    m_x(rhs.m_x),
    m_y(rhs.m_y),
    m_z(rhs.m_z) {
}

double LinearAlgebraVector::getX() const {
    return m_x;
}

double LinearAlgebraVector::getY() const {
    return m_y;
}

double LinearAlgebraVector::getZ() const {
    return m_z;
}

double LinearAlgebraVector::norm() const {
    return sqrt(m_x*m_x + m_y*m_y + m_z*m_z);
}

bool LinearAlgebraVector::equalsWithEpsilon(const LinearAlgebraVector &a, const LinearAlgebraVector &b, double epsilon) {
    return 
        fabs(a.getX() - b.getX()) < epsilon &&
        fabs(a.getY() - b.getY()) < epsilon &&
        fabs(a.getZ() - b.getZ()) < epsilon;
}

LinearAlgebraVector LinearAlgebraVector::operator+(const LinearAlgebraVector &rhs) const {
    return LinearAlgebraVector(m_x + rhs.m_x, m_y + rhs.m_y, m_z + rhs.m_z);
}

LinearAlgebraVector LinearAlgebraVector::operator-(const LinearAlgebraVector &rhs) const {
    return LinearAlgebraVector(m_x - rhs.m_x, m_y - rhs.m_y, m_z - rhs.m_z);
}

LinearAlgebraVector LinearAlgebraVector::operator*(double rhs) const {
    return LinearAlgebraVector(m_x*rhs, m_y*rhs, m_z*rhs);
}

LinearAlgebraVector operator*(double a, const LinearAlgebraVector &b) {
    return b*a;
}

LinearAlgebraVector::operator std::tuple<double, double, double>() const {
    return std::make_tuple(m_x, m_y, m_z);
}

const LinearAlgebraVector& LinearAlgebraVector::operator=(const LinearAlgebraVector &rhs) {
    m_x = rhs.m_x;
    m_y = rhs.m_y;
    m_z = rhs.m_z;
    return *this;
}