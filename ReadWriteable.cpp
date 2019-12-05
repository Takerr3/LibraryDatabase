// Tristan Kerr
// OOP244 NBB
// takerr3@myseneca.ca
// 022975148
// Milestone 4

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
