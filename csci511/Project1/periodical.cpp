#include<iostream>
using namespace std;

#include"media.h"
#include"periodical.h"

Periodical::Periodical(string call_number, string title, string subjects,
 	string desc, string notes, string series, string related_titles)
	: Media(call_number, title, subjects)
{
	m_desc = desc;
	m_notes = notes;
	m_series = series;
	m_related_titles = related_titles;
}

vector<string> Periodical::getOther(){
	vector<string> other;
	other.push_back(m_desc);
	other.push_back(m_notes);
	other.push_back(m_series);
	other.push_back(m_related_titles);
	return other;
}

string Periodical::getType(){
  return "Periodical";
}

void Periodical::Display(){
  cout << Media::m_call_number << ", ";
  cout << Media::m_title << ", ";
  cout << Media::m_subjects << ", ";
  cout << m_desc << ", ";
  cout << m_notes << ", ";
  cout << m_series << ", ";
  cout << m_related_titles;
}
