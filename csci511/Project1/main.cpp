
#include <iostream>
#include <vector>
using namespace std;

#include "media.h"
#include "video.h"
#include "film.h"
#include "library.h"
#include "book.h"
#include "periodical.h"

int main()
{
    string search;

    Library library;
    vector<Media*> results;

    cout << "Search by Call Number, type 'callnumber' " << endl;
    cout << "Search by Title, type 'title' " << endl;
    cout << "Search by Subject, type 'subjects' " << endl;
    cout << "Search by Other, type 'other' " << endl;

    while (search != "quit"){
        cout << "Enter: ";
        cin >> search;
        if (search == "callnumber"){

            cout << "Type the Search Keyword" << endl;
            string key;
            cin >> key;

            vector<Media*> all = library.callNumberSearch(key);

            for (std::vector<Media*>::iterator it = all.begin(); it != all.end(); ++it) {
                cout << "- " << (*it)->getTitle() << endl;
            }
        }
        if (search == "title"){
            
            cout << "Type the Search Keyword" << endl;
            string key;
            cin >> key;

            vector<Media*> all = library.callTitleSearch(key);

            for (std::vector<Media*>::iterator it = all.begin(); it != all.end(); ++it) {
                cout << "- " << (*it)->getTitle() << endl;
            }
        }
        if (search == "subjects"){
            
            cout << "Type the Search Keyword" << endl;
            string key;
            cin >> key;

            vector<Media*> all = library.callSubjectsSearch(key);

            for (std::vector<Media*>::iterator it = all.begin(); it != all.end(); ++it) {
                cout << "- " << (*it)->getTitle() << endl;
            }
        }
        if (search == "other"){
            
            cout << "Type the Search Keyword" << endl;
            string key;
            cin >> key;

            vector<Media*> all = library.callOtherSearch(key);

            for (std::vector<Media*>::iterator it = all.begin(); it != all.end(); ++it) {
                cout << "- " <<  (*it)->getTitle() << endl;
            }
        }
        cout << endl;

    }
    return 0;
}
