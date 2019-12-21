// Tristan Kerr
// OOP244 NBB
// December 2019
// https://www.linkedin.com/in/tristan-a-kerr/

#ifndef SDDS_READWRITEABLE_H__
#define SDDS_READWRITEABLE_H__

#include <iostream>

namespace sdds {

   class ReadWriteable
   {
   public:
      virtual std::istream& read(std::istream& is = std::cin) = 0;
      virtual std::ostream& write(std::ostream& is = std::cout) const = 0;
   };

   std::istream& operator>>(std::istream& is, ReadWriteable& RO);
   std::ostream& operator<<(std::ostream& os, ReadWriteable& RO);
}

#endif
