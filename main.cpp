#include <iostream>
#include "include/CSVWriter.h"
using namespace std;

void test1(){
    CSVWriter csv(",");
    csv << "this" << "is" << "a" << "row";
    cout << csv << endl;
}

void test2(){
    CSVWriter csv;
    csv.newRow() << "this" << "is" << "the" << "first" << "row";
    csv.newRow() << "this" << "is" << "the" << "second" << "row";
    cout << csv << endl;
}

void test3(){
    CSVWriter csv;
    csv.enableAutoNewRow(5);
    csv << "this" << "is" << "the" << "first" << "row" << "this" << "is" << "the" << "second" << "row";
    cout << csv << endl;
}

void test4(){
    CSVWriter csv;
    csv.newRow() << "this" << "is" << "the" << "first" << "row";
    csv.newRow() << "this" << "is" << "the" << "second" << "row";
    cout << csv.writeToFile("foobar.csv") << endl;
}

void test5(){
    CSVWriter csv;
    csv << "append" << "this" << "row" << "please" << ":)";
    cout << csv.writeToFile("foobar.csv",true) << endl;
}

void test6(){
    CSVWriter csv_a;
    CSVWriter csv_b;
    csv_a << "this" << "comes" << "from" << "csv_a";
    csv_b << "this" << "is" << "from" << "csv_b";

    csv_b += csv_a;
    cout << csv_b << endl;
}

int main()
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}
