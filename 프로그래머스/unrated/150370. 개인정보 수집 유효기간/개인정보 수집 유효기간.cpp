#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <map>

using namespace std;

vector<string> split(string origin, char separator) {
    vector<string> words;
    istringstream iss(origin);
    string word;
    
    while (getline(iss, word, separator)) {
        words.push_back(word);
    }
    
    return words;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, string> terms_map;
    
    for (int i = 0; i < terms.size(); i++) {
        string term = terms[i];
        vector<string> words = split(term, ' ');
        terms_map[words[0]] = words[1];
    }
    
    for (int i = 0; i < privacies.size(); i++) {
        string privacy = privacies[i];
        vector<string> words = split(privacy, ' ');
        vector<string> date = split(words[0], '.');
        
        int year = stoi(date[0]);
        int month = stoi(date[1]);
        int valid_term = stoi(terms_map[words[1]]);
        int new_month = month + valid_term;
        
        int real_year = year + (new_month / 12 - (new_month % 12 == 0));
        int real_month = new_month % 12 == 0 ? 12 : new_month % 12;
        
        string valid_date = to_string(real_year);
        if (real_month < 10) {
            valid_date += ".0" + to_string(real_month);
        } else {
            valid_date += "." + to_string(real_month);
        }
        valid_date += "." + date[2];
        
        if (today >= valid_date) {
            answer.push_back(i + 1);
        }
        
        // cout << i << " th: " << valid_date << "\n";
        
    }
    
    return answer;
}