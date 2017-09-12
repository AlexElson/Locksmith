#include "Report.h"
#include "Date.h"
#include "Time.h"

Report::Report(int day, int month, int year, int hour, int min, std::string desc)
	: rep_date(month, day, year), rep_time(hour, min), rep_desc(desc)
{
	//rep_date =  new Date(month, day, year);
	//rep_time = new Time(hour, min);
}

void Report::display() const{
	rep_date.display();
	rep_time.display();
}
// constructor to create a report

// write a display function
