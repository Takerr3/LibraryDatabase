// Tristan Kerr
// OOP244 NBB
// takerr3@myseneca.ca
// 022975148
// Milestone 4

#ifndef SDDS_MAGAZINE_H__
#define SDDS_MAGAZINE_H__

#include <iostream>
#include "PubRecord.h"

namespace sdds {

   class Magazine : public PubRecord
   {
      int m_volume;
      int m_issueNumber;
   public:
      Magazine();
      Magazine(const Magazine& RO);
      char recID() const;
      void checkIn(); //unable to check in Magazine
      void checkOut(); //unable to check out Magazine
      Magazine& operator=(const Magazine& RO);
      void read(char* str, int len, const char* errorMessage = "");
      void read(int& val, int min, int max, const char* errorMessage = "");
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout) const;
   };

}

#endif