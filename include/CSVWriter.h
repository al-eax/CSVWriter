#ifndef CSVWRITER_H
#define CSVWRITER_H

/***********************************************************************************************
 *
 *    Classe qui permet de gérer l'écriture sous le format CSV
 *    Licence : BSD 2-Clause "Simplified" License
 *    Url : https://github.com/jojo58fr/CSVWriter
 *
 *********************************************************************************************/

#include <fstream>
#include <iostream>
#include <sstream>
#include <typeinfo>

using namespace std;
class CSVWriter
{
    public:
        
        /*
        * Déclarations des différents constructeurs
        */
        CSVWriter(){
            this->firstRow = true;
            this->seperator = ";";
            this->columnNum = -1;
            this->valueCount = 0;

            //Clear Stream
            ss.str(std::string());
        }

        CSVWriter(int numberOfColums){
            this->firstRow = true;
            this->seperator = ";";
            this->columnNum = numberOfColums;
            this->valueCount = 0;

            //Clear Stream
            ss.str(std::string());
        }

        CSVWriter(string seperator){
            this->firstRow = true;
            this->seperator = seperator;
            this->columnNum = -1;
            this->valueCount = 0;

            //Clear Stream
            ss.str(std::string());
        }

        CSVWriter(string seperator, int numberOfColums){
            this->firstRow = true;
            this->seperator = seperator;
            this->columnNum = numberOfColums;
            this->valueCount = 0;
            cout << this->seperator << endl;

            //Clear Stream
            ss.str(std::string());
        }

        /*
        * Ajout de texte par l'intermédiaire d'une fonction
        */
        CSVWriter& add(const char *str){
            return this->add(string(str));
        }

        CSVWriter& add(char *str){
            return this->add(string(str));
        }

        CSVWriter& add(string str){
            //if " character was found, escape it
            size_t position = str.find("\"",0);
            bool foundQuotationMarks = position != string::npos;
            while(position != string::npos){
                str.insert(position,"\"");
                position = str.find("\"",position + 2);
            }
            if(foundQuotationMarks){
                str = "\"" + str + "\"";
            }else if(str.find(this->seperator) != string::npos){
                //if seperator was found and string was not escapted before, surround string with "
                str = "\"" + str + "\"";
            }
            return this->add<string>(str);
        }

        template<typename T>
        CSVWriter& add(T str){
            if(this->columnNum > -1){
                //if autoNewRow is enabled, check if we need a line break
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
        CSVWriter& operator<<(const T& t){
            return this->add(t);
        }

        /*
        * Ajout de texte par l'intermédiaire d'opérateurs
        */
        void operator+=(CSVWriter &csv){
            this->ss << endl << csv;
        }

        friend ostream& operator<<(std::ostream& os, CSVWriter & csv){
            return os << csv.toString();
        }

        /*
        * Retour du format CSV sous forme de chaine de caractère
        */
        string toString(){
            return ss.str();
        }

        /*
        * Préparation d'une nouvelle ligne 
        */
        CSVWriter& newRow(){
            if(!this->firstRow || this->columnNum > -1){
                ss << endl;
            }else{
                //if the row is the first row, do not insert a new line
                this->firstRow = false;
            }
            valueCount = 0;
            return *this;
        }

        /*
        * Gestion de l'écriture dans un document 
        */
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

        /*
        * Gestion d'uns système de colonnes automatique par rapport à un nombre prédéfini 
        */
        void enableAutoNewRow(int numberOfColumns){
            this->columnNum = numberOfColumns;
        }

        // Désactivation du système de colonnes automatique
        void disableAutoNewRow(){
            this->columnNum = -1;
        }
    protected:
        bool firstRow; //Si la première ligne
        string seperator; //Gestion du séparateur
        int columnNum; //Numéro de colomne
        int valueCount; //Nombre de valeurs renseigné CAD nombre de colomnes renseigné actuel
        stringstream ss; //Flux d'écriture

};

#endif // CSVWRITER_H
