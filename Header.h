#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <set>
#include <iomanip>
#include <algorithm>
#include <regex>

using std::ifstream;
using std::ofstream;
using std::string;
using std::cout;
using std::endl;
using std::getline;
using std::stringstream;
using std::multiset;
using std::pair;
using std::vector;
using std::left;
using std::setw;

char mazosios(const char& c);
void besymbol(string& word);
bool isletter(const char& r);
bool isword(const string& word);
bool isurl(const string& word);
