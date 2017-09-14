
#include<iostream>
using namespace std;

#include"video.h"

Video::Video(string call_number, string title, string subjects,
 	string desc, string notes, string dist)
	: Media(call_number, title, subjects)
{

	m_desc = desc;
	m_notes = notes;
	m_dist = dist;
}


vector<string> Video::getOther(){
	vector<string> other;
	other.push_back(m_desc);
	other.push_back(m_notes);
	other.push_back(m_dist);
	return other;
}

string Video::getType(){
  return "Video";
}

void Video::Display(){
  cout << Media::m_call_number << ", ";
  cout << Media::m_title << ", ";
  cout << Media::m_subjects << ", ";
  cout << m_desc << ", ";
  cout << m_notes << ", ";
  cout << m_dist;
}
