#include "Header.h"

int main() {
    setlocale(LC_ALL, "Lithuanian");
    ifstream fd("input.txt");
    ofstream fr("ats.txt");

    multiset< pair<string, int>> zodziai;
    string data = "";
    string word = "";
    string a = "\"a";
    string symbol = "\"";
    besymbol(a);
    cout << a;
    vector <string> linkai;
    int eilesnr = 0;
    while (getline(fd, data))
    {
        eilesnr++;
        stringstream line;
        line << data;
        
        while (!line.eof()) {
            line >> word; 
            std::transform(word.begin(), word.end(), word.begin(), mazosios);      
            if (isurl(word)) {
                linkai.push_back(word);
            }
            if(isword(word)){
                besymbol(word);
                zodziai.insert({ word, eilesnr });               
            }       
        }
    }

    fr << left << setw(16) << "Žodis" << left << setw(8) << "| Pasikartojimo sk" << left << setw(16) << "| Eiles kuriose kartojasi" << endl;
    string praeitas = (*(zodziai.begin())).first;
    std::vector<int> kartai;
    for (auto iter = zodziai.begin()++; iter != zodziai.end(); iter++) {  
        if (praeitas == (*iter).first)
        {
            kartai.push_back((*iter).second);
        }      
        else {
                if (kartai.size() > 1) {
                   fr << "-----------------------------------------------------------------" << endl;
                   fr << left << setw(16) << praeitas << "| " << left << setw(8) << kartai.size() << left << setw(16)<<"| ";
                   for (int i = 0; i < kartai.size(); i++) {
                       fr << kartai[i]<<" ";
                   }
                   fr << endl;
                }
            praeitas = (*iter).first;
            kartai.clear();
            kartai.push_back((*iter).second);
        }
    }
    if (linkai.size() > 0) {
        fr << endl << "Linkai";

        for (int i = 0; i < linkai.size(); i++) {
            fr << "-----------------------------------------------------------------" << endl;
            fr << linkai[0] << endl;
        }
    }
    fd.close();
    fr.close();
    return 0;
}
