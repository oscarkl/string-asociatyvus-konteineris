#include "Header.h"
char mazosios(const char& c) {
    string ltdidz = "ĄČĘĖĮŠŲŪŽ";
    string ltmaz = "ąčęėįšųūž";

    for (int i = 0; i < ltdidz.size(); i++) {
        if (c == ltmaz[i])
            return ltmaz[i];
    }

    return std::tolower(c);
}

void process_word(string& word) {
    string symbols = "(),.[]-„“\"\'\\:;%!?/<>|{}+=-*&^%$#@~`”•€–0123456789°½¢£";

    while (symbols.find(*(word.end() - 1)) < symbols.size()) {
        for (char c : symbols) {
            if (*(word.begin()) == c)
                word.erase(word.begin());

            if (*(word.end() - 1) == c)
                word.erase(word.end() - 1);
        }
    }

}
bool isletter(const char& r) {
    string abecele = "aąbcčdeęėfghiįyjklmnoprsštuųūvzž";
    //string symbols = "";
    for (char l : abecele) {
        if (r == l)
            return true;
    }
    return false;
}
bool isword(const string& word) {
    for (char r : word) {
        if (isletter(r)) {
            return true;
        }
    }
    return false;
}
bool isurl(const string& word) {
    string www = "www.";
    string lt = ".lt";
    string com = ".com";
    if (word.find(www) != std::string::npos) {
        return true;
    }
    if (word.find(lt) != std::string::npos) {
        return true;
    }
    if (word.find(com) != std::string::npos) {
        return true;
    }
    return false;
}
