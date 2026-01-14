#include <ostream>
#include <format>

#include "matrix.h"


std::ostream& operator<< (std::ostream& stream, const Matrix& M)
{
  // Note this displays the matrix content over 3 lines.
  // There are other ways to display this if you wish!
  stream << std::format (
      "3x3 matrix with contents:\n"
      "    {:6.4f} {:6.4f} {:6.4f}\n"
      "    {:6.4f} {:6.4f} {:6.4f}\n"
      "    {:6.4f} {:6.4f} {:6.4f}\n",
      M(0,0), M(0,1), M(0,2),
      M(1,0), M(1,1), M(1,2),
      M(2,0), M(2,1), M(2,2));

  return stream;
}

float compute_determinant (const Matrix& M)
{
  return M(0,0) * ( M(1,1)*M(2,2) - M(2,1)*M(1,2) )
       - M(1,0) * ( M(0,1)*M(2,2) - M(2,1)*M(0,2) )
       + M(2,0) * ( M(0,1)*M(1,2) - M(1,1)*M(0,2) );
}
