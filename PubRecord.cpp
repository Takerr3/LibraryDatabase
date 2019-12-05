// Tristan Kerr
// OOP244 NBB
// takerr3@myseneca.ca
// 022975148
// Milestone 4
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "PubRecord.h"
#include "Utils.h"

using namespace std;

namespace sdds {

   void PubRecord::shelfNo(int value) {

      m_shelfNum = value;
   }

   void PubRecord::name(const char* name) {

      if (m_publication != nullptr) {
         delete[] m_publication;
      }
      m_publication = new char[strlen(name) + 1];
      strcpy(m_publication, name);
   }

   const char* PubRecord::name() const {

      return m_publication;
   }
   
   PubRecord::PubRecord() : m_publication(nullptr), m_shelfNum(0), m_mediaType(SDDS_CONSOLE) {}

   PubRecord::PubRecord(const PubRecord& RO) : m_publication(nullptr), m_shelfNum(0), m_mediaType(SDDS_CONSOLE) {

      if (RO.m_publication != nullptr) {
         m_publication = new char[strlen(RO.m_publication) + 1];
         strcpy(m_publication, RO.m_publication);
         m_shelfNum = RO.m_shelfNum;
         m_mediaType = RO.m_mediaType;
      }
   }

   PubRecord& PubRecord::operator=(const PubRecord& RO) {

      if (*this != RO) {
         if (m_publication != nullptr) {
            delete[] m_publication;
         }
         m_publication = new char[strlen(RO.m_publication) + 1];
         strcpy(m_publication, RO.m_publication);
         m_shelfNum = RO.m_shelfNum;
         m_mediaType = RO.m_mediaType;
      }
      return *this;
   }
   
   void PubRecord::mediaType(int type) {

      m_mediaType = type;
   }

   int PubRecord::mediaType() const {

      return m_mediaType;
   }

   int PubRecord::shelfNo() const {

      return m_shelfNum;
   }

   void PubRecord::readShelfNo() {

      bool ok;
      char newline;
      do {
         cin >> m_shelfNum;
         newline = cin.get();
         if (cin.fail() || newline != '\n') {
            ok = false;
            cin.clear();
            cin.ignore(1000, '\n');
         }
         else {
            ok = m_shelfNum <= 999 && m_shelfNum >= 100;
         }
      } while (!ok && cout << "Invalid Shelf Number, Enter again: ");
   }

   bool PubRecord::operator==(char ID) const {

      return (ID == recID());
   }

   bool PubRecord::operator==(const char* name) const {

      bool success = false;
      if (strstr(m_publication, name) != nullptr) {
         success = true;
      }
      return success;
   }

   PubRecord::operator bool() const {

      bool success = false;
      if (m_publication != nullptr) {
         success = true;
      }
      return success;
   }

   PubRecord::~PubRecord() {

      delete[] m_publication;
   }

   istream& operator>>(istream& is, PubRecord& RO) {

      return RO.read(is);
   }

   ostream& operator<<(ostream& os, const PubRecord& RO) {

      return RO.write(os);
   }
}