
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

string Film::getType(){
  return "Film";
}

void Film::Display(){
  cout << Media::m_call_number << ", ";
  cout << Media::m_title << ", ";
  cout << Media::m_subjects << ", ";
  cout << m_notes << ", ";
  cout << m_director << ", ";
  cout << m_year;
}
