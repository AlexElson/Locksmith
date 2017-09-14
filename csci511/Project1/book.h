
#ifndef BOOK_H
#define BOOK_H

#include"media.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Book : public Media {
    public:
  		Book(string, string, string, string, string, string);
  		virtual vector<string> getOther();
      virtual string getType();
      virtual void Display();

    protected:
  		string m_desc;
  		string m_notes;
  		string m_year;

};

#endif
