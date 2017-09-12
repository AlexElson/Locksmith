

#ifndef MEDIA_H
#define MEDIA_H

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Media {
    public:
    	Media(string, string, string);
    	string getCallNumber();
    	string getTitle();
    	string getSubjects();
    	virtual vector<string> getOther(){};

    protected:
    	string m_call_number;
    	string m_title;
    	string m_subjects;

};

#endif








