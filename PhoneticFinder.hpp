 #pragma once
 #include <string>
 #include <vector>
 #include <string>
 using namespace std;
namespace phonetic {
string find(string text ,string word );


}

std::vector<std::string> split(std::string txt, std::string delimeter );
void printString ( std::vector<std::string> vec);
void printInttArr ( std::vector<int> vec) ;
std::string toLowerCase(std::string str);
std::vector<int> catagoryChar(std::string  str);
bool similiar (std::string str1  , std::string str2);
bool checkValidWord(string word );


