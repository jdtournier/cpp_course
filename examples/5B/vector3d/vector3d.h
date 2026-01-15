#pragma once

#include <array>
#include <ostream>

class Vector3D {
  public:
    Vector3D() : m_data({ 0.0, 0.0, 0.0 }) { }
    Vector3D (const std::array<double,3>& data) : m_data (data) { }
    Vector3D (const Vector3D&) = default;

    Vector3D& operator= (const Vector3D&) = default;

    double& operator[] (int n) { return m_data[n]; }
    const double& operator[] (int n) const { return m_data[n]; }

    bool operator! () const {
      return m_data[0] == 0.0 && m_data[1] == 0.0 && m_data[2] == 0.0;
    }

    bool operator== (const Vector3D&) const = default;

  private:
    std::array<double,3> m_data;
};




inline std::ostream& operator<< (std::ostream& stream, const Vector3D& v)
{
  stream << "[ " << v[0] << " " << v[1] << " " << v[2] << " ]";
  return stream;
}


