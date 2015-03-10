#include <iostream>
#include "include/CSVWriter.h"
using namespace std;

int main()
{
    CSVWriter csv;
    csv.enableAutoNewRow(3);
    csv.enableAutoEmptyFileds(true);
    csv << 123<<234<<234;
    csv << 1 ;
    csv.newRow();
    csv << 324 << 234;
    csv.newRow();
    cout << csv;
    return 0;
}
