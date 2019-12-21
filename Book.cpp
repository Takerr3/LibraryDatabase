// Tristan Kerr
// OOP244 NBB
// December 2019
// https://www.linkedin.com/in/tristan-a-kerr/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Book.h"
#include "Date.h"

using namespace std;
namespace sdds {

   Book::Book() : PubRecord(), m_ISBN(0), m_memberID(0) {}

   Book::Book(const Book& RO) : PubRecord(RO) {
      *this = RO;
   }
   //return recID
   char Book::recID() const {

      return 'B';
   }
   //return member ID
   int Book::memberId() const {

      return m_memberID;
   }
   //check in Book
   void Book::checkIn() {

      m_memberID = 0;
      cout << *this << " checked in!" << endl;
   }

   void Book::read(char* str, int len, const char* errorMessage) {

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

   void Book::read(int& val, int min, int max, const char* errorMessage) {

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

   void Book::read(long long int& val, long long int min, long long int max, const char* errorMessage) {

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
   //assignment operator for copy constructor
   Book& Book::operator=(const Book& RO)
   {
      if (this != &RO) {
         m_dueDate = RO.m_dueDate;
         m_memberID = 0;
         m_ISBN = RO.m_ISBN;
         name(RO.name());
         mediaType(RO.mediaType());
         shelfNo(RO.shelfNo());
      }
      return *this;
   }
   //check out Book
   void Book::checkOut() {
      Date current(2019, 11, 24);
      cout << "Entere Member id: ";
      read(m_memberID, 10000, 99999, "Invalid Member ID, Enter again: ");
      cout << "Enter return date: ";
      cin >> m_dueDate;
      if (m_dueDate < current) {
         do {
            cout << "Pleae enter a future date.";
            cin >> m_dueDate;

         } while (m_dueDate < current);
         if ((m_dueDate - current) > 30) {
            cout << "The return date must be earlier than 30 days away from today." << endl;
            cin >> m_dueDate;
         }
      }
   }
   //read user input for Book
   istream& Book::read(istream& is) {

      if (mediaType() == SDDS_CONSOLE) {
         m_memberID = 0;
         char tempName[40 + 1];
         cout << "Book Name: ";
         read(tempName, 40, "Book name too long, Enter again: ");
         name(tempName);
         cout << "ISBN: ";
         read(m_ISBN, 1000000000000, 9999999999999, "Invalid ISBN, Enter again: ");
         cout << "Shelf Number: ";
         readShelfNo();
      }
      else if(mediaType() == SDDS_FILE) {
         char tempName[40 + 1];
         int tempShelf;
         is.getline(tempName, 40, '\t');
         name(tempName);
         is >> m_ISBN;
         is.ignore();
         is >> tempShelf;
         shelfNo(tempShelf);
         is.ignore();
         is >> m_memberID;
         if(m_memberID != 0) {
            is.ignore();
            is >> m_dueDate;
         }
      }
      return is;
   }
   //console display user input
   ostream& Book::write(ostream& os) const {

      if (mediaType() == SDDS_CONSOLE) {
         cout << setw(41) << left << setfill(' ') << name();
         cout << m_ISBN;
         cout << "  ";
         cout << shelfNo();
         if (m_memberID != 0) {
            cout << " " << m_memberID << "   " << m_dueDate;
         }
      }
      else if (mediaType() == SDDS_FILE) {
         os << recID();
         os << name();
         os << '\t';
         os << m_ISBN;
         os << '\t';
         os << shelfNo();
         os << '\t';
         os << m_memberID;
         if (m_memberID != 0) {
            os << '\t';
            os << m_dueDate;
         }
         os << '\n';
      }
      return os;
   }
}
