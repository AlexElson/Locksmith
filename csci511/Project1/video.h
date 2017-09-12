 
#ifndef VIDEO_H
#define VIDEO_H

#include"media.h"

#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Video : public Media {
    public:
		Video(string, string, string, string, string, string);
		virtual vector<string> getOther();

    protected:
		string m_desc;
		string m_notes;
		string m_dist;

};

#endif








