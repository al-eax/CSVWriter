#ifndef CSVWRITER_H
#define CSVWRITER_H
#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;
class CSVWriter
{
    public:
        CSVWriter(){
            this->firstRow = true;
            this->seperator = ";";
            this->columnNum = -1;
            this->valueCount = 0;
        }
        template<typename T>
        CSVWriter& add(T str){
            if(this->columnNum > -1){
                if(this->valueCount == this->columnNum ){
                    this->newRow();
                }
            }
            if(valueCount > 0)
                this->ss << this->seperator;
            this->ss << str;
            this->valueCount++;

            return *this;
        }
        template<typename T>
        friend CSVWriter& operator<<(CSVWriter & csv, const T& t)
        {
            return csv.add(t);
        }

        string toString(){
            return ss.str();
        }

        friend ostream& operator<<(std::ostream& os, CSVWriter & csv){
            return os << csv.toString();
        }

        CSVWriter& newRow(){
            if(!this->firstRow || this->columnNum > -1){
                 ss << endl;
            }else{
                this->firstRow = false;
            }
            valueCount = 0;
            return *this;
        }
        bool writeToFile(string filename){
            return writeToFile(filename,false);
        }
        bool writeToFile(string filename, bool append){
            ofstream file;
            if(append)
                file.open(filename.c_str(),ios::out | ios::app);
            else
                file.open(filename.c_str(),ios::out | ios::trunc);
            if(!file.is_open())
                return false;
            if(append)
                file << endl;
            file << this->toString();
            file.close();
            return file.good();
        }
        void enableAutoNewRow(int numberOfColumns){
            this->columnNum = numberOfColumns;
        }
        void disableAutoNewRow(){
            this->columnNum = -1;
        }
        stringstream ss;
    private:
        bool firstRow;
        string seperator;
        int columnNum;
        int valueCount;
};

#endif // CSVWRITER_H
