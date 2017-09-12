
#ifndef FILM_H
#define FILM_H

#include "media.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Film : public Media {
    public:
		Film(string, string, string, string, string, string);
		virtual vector<string> getOther();

    protected:

		string m_notes;
		string m_director;
		string m_year;

};

#endif








