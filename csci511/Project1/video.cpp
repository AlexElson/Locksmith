
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