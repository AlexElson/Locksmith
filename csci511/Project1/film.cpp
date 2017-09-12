
#include<iostream>
using namespace std;

#include"film.h"

Film::Film(string call_number, string title, string subjects,
 	string notes, string director, string year)
	: Media(call_number, title, subjects)
{
	m_notes = notes;
	m_director = director;
	m_year = year;
}

vector<string> Film::getOther(){
	vector<string> other;
	other.push_back(m_notes);
	other.push_back(m_director);
	other.push_back(m_year);
	return other;
}