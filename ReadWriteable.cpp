// Tristan Kerr
// OOP244 NBB
// December 2019
// https://www.linkedin.com/in/tristan-a-kerr/

#include <iostream>
#include "ReadWriteable.h"
using namespace std;

namespace sdds {


   istream& operator>>(istream& is, ReadWriteable& RO) {

      return RO.read(is);
   }

   ostream& operator<<(ostream& os, ReadWriteable& RO) {

      return RO.write(os);
   }
}
