
#ifndef LIBRARY_H
#define LIBRARY_H

#include<iostream>
#include<string>
#include<vector>

#include "media.h"
#include "video.h"
#include "film.h"
#include "book.h"
#include "periodical.h"

using namespace std;

class Library {
    public:
  		Library();
  		~Library();

  		vector<Media*> callNumberSearch(string);
  		vector<Media*> callTitleSearch(string);
  		vector<Media*> callSubjectsSearch(string);
  		vector<Media*> callOtherSearch(string);

    private:
  		vector<Media*> m_stack;

};

#endif
