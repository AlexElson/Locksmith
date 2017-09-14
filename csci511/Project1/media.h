

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
      virtual string getType(){};
    	virtual vector<string> getOther(){};
      virtual void Display(){};

    protected:
      string m_type;
    	string m_call_number;
    	string m_title;
    	string m_subjects;

};

#endif
