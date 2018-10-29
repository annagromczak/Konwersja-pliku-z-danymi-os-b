#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include <vector>

using namespace std;

void conversionFile (string sourceFileName) {
    string line, allInformation;
    vector <string> words;

    fstream sourceFile;
    sourceFile.open((sourceFileName+".txt").c_str());

    if (sourceFile.good() == true) {
        while(getline(sourceFile,line)) {
            words.push_back(line);
        }
    } else {
        cout << "Nie mozna otworzyc pliku!" << endl;
        system("pause");
    }
    sourceFile.close();

    fstream newFile;
    newFile.open("ksiazka_adresowa_nowy_format.txt", ios::out);

    if(newFile.good() == true) {
        for (int i=0; i<words.size(); i++) {
            allInformation = words[i] + "|" + words[i+1] + "|" + words[i+2] + "|" + words[i+3] + "|" + words[i+4] + "|" + words[i+5] + "|";
            newFile << allInformation << endl;
            allInformation = "";
            i += 5;
        }
        newFile.close();

    } else {
        cout << "Nie mozna utworzyc pliku!" << endl;
        system("pause");
    }

}

int main() {
    string sourceFileName;
    cout << "Podaj nazwe zrodlowego pliku tekstowego: " << endl;
    cin >> sourceFileName;

    conversionFile(sourceFileName);

    return 0;
}
