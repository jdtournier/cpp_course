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



// equality operators:
inline bool operator== (const Vector3D& V, double value)
{
  return (V[0]==value) && (V[1]==value) && (V[2]==value);
}
inline bool operator== (double value, const Vector3D& V)
{
  return V==value;
}

// comparison operators: Vector3D - Vector3D
inline bool operator< (const Vector3D& a, const Vector3D& b)
{ return a[0]<b[0] && a[1]<b[1] && a[2]<b[2]; }

inline bool operator<= (const Vector3D& a, const Vector3D& b)
{ return a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2]; }

inline bool operator> (const Vector3D& a, const Vector3D& b)
{ return a[0]>b[0] && a[1]>b[1] && a[2]>b[2]; }

inline bool operator>= (const Vector3D& a, const Vector3D& b)
{ return a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2]; }

// comparison operators: Vector3D - double
inline bool operator< (const Vector3D& a, double b)
{ return a[0]<b && a[1]<b && a[2]<b; }

inline bool operator<= (const Vector3D& a, const double b)
{ return a[0]<=b && a[1]<=b && a[2]<=b; }

inline bool operator> (const Vector3D& a, const double b)
{ return a[0]>b && a[1]>b && a[2]>b; }

inline bool operator>= (const Vector3D& a, const double b)
{ return a[0]>=b && a[1]>=b && a[2]>=b; }

// comparison operators: double - Vector3D
inline bool operator< (double a, const Vector3D& b)
{ return a<b[0] && a<b[1] && a<b[2]; }

inline bool operator<= (double a, const Vector3D& b)
{ return a<=b[0] && a<=b[1] && a<=b[2]; }

inline bool operator> (double a, const Vector3D& b)
{ return a>b[0] && a>b[1] && a>b[2]; }

inline bool operator>= (double a, const Vector3D& b)
{ return a>=b[0] && a>=b[1] && a>=b[2]; }



// stream insertion operator:
inline std::ostream& operator<< (std::ostream& stream, const Vector3D& v)
{
  stream << "[ " << v[0] << " " << v[1] << " " << v[2] << " ]";
  return stream;
}


