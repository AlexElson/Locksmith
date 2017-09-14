
#ifndef PERIODICAL_H
#define PERIODICAL_H

#include"media.h"
#include"periodical.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Periodical : public Media {
    public:
  		Periodical(string, string, string, string, string, string, string); //(int x, int y, int size);
  		virtual vector<string> getOther();
      virtual string getType();
      virtual void Display();

    protected:
  		string m_desc;
  		string m_notes;
  		string m_series;
  		string m_related_titles;

};

#endif
