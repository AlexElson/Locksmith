
#include<iostream>
using namespace std;

#include"book.h"

Book::Book(string call_number, string title, string subjects,
 	string desc, string notes, string year)
	: Media(call_number, title, subjects)
{
	m_desc = desc;
	m_notes = notes;
	m_year = year;
}

vector<string> Book::getOther(){
	vector<string> other;
	other.push_back(m_desc);
	other.push_back(m_notes);
	other.push_back(m_year);
	return other;
}

string Book::getType(){
  return "Book";
}

void Book::Display(){
  cout << Media::m_call_number << ", ";
  cout << Media::m_title << ", ";
  cout << Media::m_subjects << ", ";
  cout << m_desc << ", ";
  cout << m_notes << ", ";
  cout << m_year;
}
