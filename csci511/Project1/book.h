
#ifndef BOOK_H
#define BOOK_H

#include"media.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Book : public Media {
    public:
		Book(string, string, string, string, string, string);//(int x, int y);
		virtual vector<string> getOther();
		//void draw(Grid &grid);
    protected:
		string m_desc;
		string m_notes;
		string m_year;

};

#endif








