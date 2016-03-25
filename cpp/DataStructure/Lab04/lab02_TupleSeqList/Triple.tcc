#pragma once

template <typename T>
Triple<T>::Triple() :
    m_row(0),
    m_col(0),
    m_value()
{
}

template <typename T>
Triple<T>::Triple(int row, int col, T value) :
    m_row(row),
    m_col(col),
    m_value(value)
{
}

template <typename T>
Triple<T>::~Triple() {
}
