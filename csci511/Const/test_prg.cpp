#include "Report.h"
void func(const Report& r) //copy ctor
{
  r.display();
}


int main()
{
  Report r = Report(1970, 1, 1, 0, 0, "Epoch");
  func(r);
}
