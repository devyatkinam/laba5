#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

bool isp(const string& str) {
    string reversew = str;
    reverse(reversew.begin(), reversew.end());
    return str == reversew;
}

int main() {
    ifstream in("input.txt");
    ofstream palindrom("palindrom.txt");
    ofstream non_palindrom("non_palindrom.txt");
    string line;
    string word;
    int lnum = 0;

    while (getline(in, line)) {
        vector<string> words;
        int n = 0;
        lnum++;
        istringstream stream(line);

        while (stream >> word) {
            words.push_back(word);
            if (isp(word)) {
                n++;
            }
        }

        if (n == 1 && words.size() == 1) {
            palindrom << line << endl;
        }
        if(n == 0){
            non_palindrom << line << endl;
        }
    }

    in.close();
    palindrom.close();
    non_palindrom.close();

    return 0;
}
