#include <iostream>
#include <vector>
using  namespace std;
static int    charsCategory[] = {
        1,    /* A */
        2,    /* B */
        3,    /* C */
        4,    /* D */
        5,    /* E */
        2,    /* F */
        7,    /* G */
        8,    /* H */
        9,    /* I */
        7,    /* J */
        3,    /* K */
        12,    /* L */
        13,    /* M */
        14,    /* N */
        15,    /* O */
        2,    /* P */
        3,    /* Q */
        18,    /* R */
        19,    /* S */
        4,    /* T */
        15,    /* U */
        22,    /* V */
        22,    /* W */
        24,    /* X */
        9,    /* Y */
        19,    /* Z */
};


class wordNotFoundException: public exception
{
    virtual const char* what() const throw()
    {
        return "The word your searching appears to be missing ";
    }
} wordNotFoundException;

class notValidWordException: public exception
{
    virtual const char* what() const throw()
    {
        return "Not valid world for search ";
    }
} notValidWordException;




std::vector<std::string> split(std::string txt, std::string delimeter ) {

    int start =0 ;
    int end = 0 ;
    std::vector<std::string>  ans;

    for (int i = 0; i < txt.length(); i++) {

        for(int j = 0; j < delimeter.length(); j++) {
            if(txt[i]==delimeter[j]) {
                ans.push_back(txt.substr(start,end-start));
                start=end+1;
            }
        }
        end++;
    }
    ans.push_back(txt.substr(start,end-start));
    return ans;
}


void printString ( std::vector<std::string> vec) {

    for (int i = 0; i < vec.size(); ++i) {
        std::cout<<"["<<vec.at(i)<<"]";
    }
    std::cout<<std::endl;
}

void printInttArr ( std::vector<int> vec) {
    for (int i = 0; i < vec.size(); ++i) {
        std::cout<<"["<<vec.at(i)<<"]";
    }
}


std::string toLowerCase(std::string str){
    for (int i = 0; i <str.size() ; ++i) {
        str[i]=tolower(str[i]);

    }
    return str;
}

std::vector<int> catagoryChar(std::string  str) {
    std::vector<int> ans;
    str=toLowerCase(str);
    for (int i = 0; i <str.size() ; ++i) {
        int index = (int)str[i]-(int)'a';
        if(index>26||index<0){
            std::cout<<"index is not valid , its : "<<index<<std::endl;
            return ans;
        }

        ans.push_back(charsCategory[index]);

    }

    return ans;


}

bool similiar (std::string str1  , std::string str2) {

    std::vector<int> a = catagoryChar(str1);
    std::vector<int> b = catagoryChar(str2);

    return (a==b);


}


bool checkValidWord(string word ){

    //case muliple word's
    if (word.find_first_of(' ') != string::npos||word.find_first_of('\n') != string::npos||word.find_first_of('\t') != string::npos)
        return false;

return true;
}




namespace phonetic {
/**
 * Function to find Phonetic match
 * @param text :the text to search in
 * @param word : the word to search for
 * @return sting if there is a match and throw an error otherwise.
 */
    string find(string text ,string word ){

        if(checkValidWord(word)) { //if it's an empty word , or more than one word , or contain symbol's different than a-Z throw an error
            throw notValidWordException;
        }
        std::string del  = " \n\t";
        std::vector<std::string>  sTxt = split(text,del);
        for (int i = 0; i < sTxt.size(); ++i) {
            if(sTxt.at(i).size()!=word.size()) continue;
            if(similiar(sTxt.at(i),word)) {
                return sTxt[i];
            }
        }

        std::cout<<"cant find "<<word<<"in the text";
        throw wordNotFoundException;

    }
}




//  int main() {
//      string text = "Dond vorri be haffy";
//      cout << phonetic::find(text, "dont") << endl;   // should print "Dond"
//      cout << phonetic::find(text, "worry") << endl;   // should print "vorri"
//      cout << phonetic::find(text, "Be") << endl;   // should print "be"
//      cout << phonetic::find(text, "happy") << endl;   // should print "haffy"

//      return 0;
//  }
