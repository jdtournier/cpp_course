#include <iostream>

#include "vector3d.h"

int main ()
{
  Vector3D v, v2 ({1,2,3});

  v[0] = 1.0;
  std::cout << "v: " << v << "\n";
  std::cout << "!v: " << !v << "\n";
  std::cout << "v==v2: " << (v==v2) << "\n";

  v[1] = v[2] = 1.0;
  std::cout << "v==1: " << (v==1.0) << "\n";
  std::cout << "v2==1: " << (v2==1.0) << "\n";

  std::cout << "v!=v2: " << (v!=v2) << "\n";
  std::cout << "v!=1: " << (v!=1.0) << "\n";
  std::cout << "2!=v2: " << (2!=v2) << "\n";

  std::cout << "v<v2: " << (v<v2) << "\n";
  std::cout << "v<=v2: " << (v<=v2) << "\n";
  std::cout << "v<1: " << (v<1) << "\n";
  std::cout << "v<=1: " << (v<=1) << "\n";
  std::cout << "3>v2: " << (3>v2) << "\n";
  std::cout << "3>=v2: " << (3>=v2) << "\n";

  std::cout << "v+v2: " << (v+v2) << "\n";
  std::cout << "v-v2: " << (v-v2) << "\n";

  std::cout << "v2+1: " << (v2+1) << "\n";
  std::cout << "v2-2: " << (v2-2) << "\n";
  std::cout << "v2*3: " << (v2*3) << "\n";
  std::cout << "v2/2: " << (v2/2) << "\n";

  std::cout << "1+v2: " << (1+v2) << "\n";
  std::cout << "2-v2: " << (2-v2) << "\n";
  std::cout << "3*v2: " << (3*v2) << "\n";
  std::cout << "2/v2: " << (2/v2) << "\n";

  return 0;
}
