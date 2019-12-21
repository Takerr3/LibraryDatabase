// Tristan Kerr
// OOP244 NBB
// December 2019
// https://www.linkedin.com/in/tristan-a-kerr/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Magazine.h"
#include "Utils.h"


using namespace std;
namespace sdds {

   Magazine::Magazine() : PubRecord(), m_volume(0), m_issueNumber(0) {}

   Magazine::Magazine(const Magazine& RO) : PubRecord(RO) {
      *this = RO;
   }
   //return recID
   char Magazine::recID() const {

      return 'M';
   }
   //check in Magazine
   void Magazine::checkIn() {

      cout << "Magazines cannot be checked in or out!" << endl;
   }
   //check out Magazine
   void Magazine::checkOut() {

      cout << "Magazines cannot be checked in or out!" << endl;
   }

   void Magazine::read(char* str, int len, const char* errorMessage) {
      bool ok;
      do {
         ok = true;
         cin.getline(str, len + 1, '\n');
         if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            ok = false;
         }
      } while (!ok && cout << errorMessage);
   }

   void Magazine::read(int& val, int min, int max, const char* errorMessage) {
      bool ok;
      char newline;
      do {
         cin >> val;
         newline = cin.get();
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n');
         }
         else {
            ok = val <= max && val >= min;
         }
      } while (!ok && cout << errorMessage);
   }
   //assignment for copy constructor
   Magazine& Magazine::operator=(const Magazine& RO)
   {
      if (this != &RO) {
         m_issueNumber = RO.m_issueNumber;
         m_volume = RO.m_volume;
         name(RO.name());
         mediaType(RO.mediaType());
         shelfNo(RO.shelfNo());
      }
      return *this;
   }
   //real console and file for magazine
   istream& Magazine::read(istream& is) {

      if (mediaType() == SDDS_CONSOLE) {
         char tempName[40 + 1];
         cout << "Magazine Name: ";
         read(tempName, 40, "Magazine name too long, Enter again: ");
         name(tempName);
         cout << "Volume: ";
         read(m_volume, 1, 99, "Invalid Volume number, Enter again: ");
         cout << "Issue: ";
         read(m_issueNumber, 1, 99, "Invalid Issue number, Enter again: ");
         cout << "Shelf Number: ";
         readShelfNo();
      }
      else if(mediaType() == SDDS_FILE) {
         char tempName[40 + 1];
         int tempShelf;
         is.getline(tempName, 40, '\t');
         name(tempName);
         is >> m_volume;
         is.ignore();
         is >> m_issueNumber;
         is.ignore();
         is >> tempShelf;
         shelfNo(tempShelf);
         is.ignore();
      }
      return is;
   }
   //display Magazine contents
   ostream& Magazine::write(ostream& os) const {

      if (mediaType() == SDDS_CONSOLE) {
         os << setw(41) << left << name();
         os << "       " << right;
         os << setw(2) << setfill('0') << m_volume << setfill(' ') << "(";;
         os << setw(2) << setfill('0') << m_issueNumber << setfill(' ') << ")" << left;
         os << "  ";
         os << shelfNo();
      }
      else if (mediaType() == SDDS_FILE) {
         os << recID();
         os << name();
         os << '\t';
         os << m_volume;
         os << '\t';
         os << m_issueNumber;
         os << '\t';
         os << shelfNo() << endl;
      }
      return os;
   }
}
