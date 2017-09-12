
#include<iostream>
using namespace std;

#include"media.h"

Media::Media(string call_number, string title, string subjects) :
	m_call_number(call_number), m_title(title), m_subjects(subjects)

{
}

string Media::getCallNumber(){
	return m_call_number;
}
string Media::getTitle(){
	return m_title;
}
string Media::getSubjects(){
	return m_subjects;
}


