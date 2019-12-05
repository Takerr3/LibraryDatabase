 // Tristan Kerr
// OOP244 NBB
// takerr3@myseneca.ca
// 022975148
// Milestone 4

#ifndef SDDS_PUBRECORD_H__
#define SDDS_PUBRECORD_H__

#include <iostream>
#include "ReadWriteable.h"
#include "Date.h"

namespace sdds {

   const int SDDS_CONSOLE = 1;
   const int SDDS_FILE = 2;

   class PubRecord : public ReadWriteable
   {
      char* m_publication;
      int m_shelfNum;
      int m_mediaType;
   protected:
      virtual void name(const char* name);
      virtual const char* name() const;
      void shelfNo(int value);
   public:
      PubRecord();
      PubRecord(const PubRecord& RO);
      virtual void checkIn() = 0;
      virtual void checkOut() = 0;
      virtual char recID() const = 0;
      virtual PubRecord& operator=(const PubRecord& RO);
      virtual void mediaType(int type); //assign m_mediaType
      virtual int mediaType() const; //return m_mediaType
      virtual int shelfNo() const; //return m_shelfNum
      virtual void readShelfNo(); //read the shelfNum from console
      bool operator==(char ID) const;
      bool operator==(const char* name) const;
      operator bool() const;
      virtual ~PubRecord();
   };
   std::istream& operator>>(std::istream& is, PubRecord& RO);
   std::ostream& operator<<(std::ostream& os, const PubRecord& RO);
}

#endif