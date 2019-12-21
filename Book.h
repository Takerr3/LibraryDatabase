// Tristan Kerr
// OOP244 NBB
// December 2019
// https://www.linkedin.com/in/tristan-a-kerr/

#ifndef SDDS_BOOK_H__
#define SDDS_BOOK_H__

#include <iostream>
#include "PubRecord.h"

namespace sdds {

   class Book : public PubRecord
   {
      long long int m_ISBN;
      int m_memberID;
      Date m_dueDate;
   public:
      Book();
      Book(const Book& RO);
      char recID() const;
      int memberId() const;
      Book& operator=(const Book& RO);
      void checkIn(); //check in user Book
      void checkOut(); //check out user Book and assign return date
      void read(char* str, int len, const char* errorMessage);
      void read(int& val, int min, int max, const char* errorMessage = "");
      void read(long long int& val, long long int min, long long int max, const char* errorMessage = "");
      std::istream& read(std::istream& is = std::cin);
      std::ostream& write(std::ostream& os = std::cout) const;
   };

}

#endif
