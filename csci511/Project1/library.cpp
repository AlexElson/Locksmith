
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

#include "library.h"
#include "media.h"

Library::Library(){

	string line;
	ifstream bookfile("Data/book.txt");
	ifstream videofile("Data/video.txt");
	ifstream filmfile("Data/film.txt");
	ifstream perfile("Data/periodical.txt");

	while(getline(bookfile, line, '\n')){
		std::istringstream ss(line);
		string type;
		string f[10];
		int a = 0;
		while(getline(ss, type, '|')){
			f[a] = type; a++;
		}
		m_stack.push_back( new Book(f[0], f[1], f[2], f[4], f[9], f[7]) );
	}
	while(getline(videofile, line, '\n')){
		std::istringstream ss(line);
		string type;
		string f[10];
		int a = 0;
		while(getline(ss, type, '|')){
			f[a] = type; a++;
		}
		m_stack.push_back( new Video(f[0], f[1], f[2], f[3], f[5], f[4]) );
	}
	while(getline(filmfile, line, '\n')){
		std::istringstream ss(line);
		string type;
		string f[10];
		int a = 0;
		while(getline(ss, type, '|')){
			f[a] = type; a++;
		}
		m_stack.push_back( new Film(f[0], f[1], f[2], f[4], f[3], f[5]) );
	}
	while(getline(perfile, line, '\n')){
		std::istringstream ss(line);
		string type;
		string f[12];
		int a = 0;
		while(getline(ss, type, '|')){
			f[a] = type; a++;
		} //desc notes series related
		m_stack.push_back( new Periodical(f[0], f[1], f[2], f[4], f[8], f[7], f[9]) );
	}
	bookfile.close();
	videofile.close();
	filmfile.close();
	perfile.close();



}

Library::~Library(){
	for (std::vector<Media*>::iterator it = m_stack.begin(); it != m_stack.end(); ++it) {
			delete (*it);
    }
}

vector<Media*> Library::callNumberSearch(string key){
	vector<Media*> searched;

	for (std::vector<Media*>::iterator it = m_stack.begin(); it != m_stack.end(); ++it) {
		if ( ((*it)->getCallNumber()).find(key) != std::string::npos){
			searched.push_back(*it);
		}
        //cout << (*it)->getCallNumber() << endl;
    }

	//searched = find(m_stack.begin(), m_stack.end(), m_stack->getCallNumber())
	return searched;
}

vector<Media*> Library::callTitleSearch(string key){
	vector<Media*> searched;

	for (std::vector<Media*>::iterator it = m_stack.begin(); it != m_stack.end(); ++it) {
		if ( ((*it)->getTitle()).find(key) != std::string::npos){
			searched.push_back(*it);
		}
    }
	return searched;
}

vector<Media*> Library::callSubjectsSearch(string key){
	vector<Media*> searched;

	for (std::vector<Media*>::iterator it = m_stack.begin(); it != m_stack.end(); ++it) {
		if ( ((*it)->getSubjects()).find(key) != std::string::npos){
			searched.push_back(*it);
		}
    }

	return searched;
}

vector<Media*> Library::callOtherSearch(string key){
	vector<Media*> searched;

	for (std::vector<Media*>::iterator it = m_stack.begin(); it != m_stack.end(); ++it) {
		//for (std::vector<string>::iterator it2 = (*it).begin(); it2 != (*it).end(); ++it2) {

			vector<string> other = (*it)->getOther();

			std::vector<string>::iterator it2;
			for (it2 = other.begin(); it2 != other.end(); ++it2) {

				//cout << (*it2) << endl;

				if ( (*it2).find(key) != string::npos){
					searched.push_back(*it);
				}

			}
    }

	return searched;
}
