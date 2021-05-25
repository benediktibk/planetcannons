#include "GeometryStraight.h"

GeometryStraight::GeometryStraight(const LinearAlgebraVector &start, const LinearAlgebraVector &end) :
    m_start(start),
    m_end(end) {
}

const LinearAlgebraVector& GeometryStraight::getStart() const {
    return m_start;
}

const LinearAlgebraVector& GeometryStraight::getEnd() const {
    return m_end;
}

LinearAlgebraVector GeometryStraight::getMidPoint() const {
    auto direction = m_end - m_start;
    return m_start + direction * 0.5;
}