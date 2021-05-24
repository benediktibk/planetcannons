#include "LinearAlgebraVector.h"

LinearAlgebraVector::LinearAlgebraVector(double x, double y, double z) :
    m_x(x),
    m_y(y),
    m_z(z) {
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