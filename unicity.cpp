#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

map<int, char> revcode = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}};

void print_unicities(vector<vector<int>> columns, string set, int set_size) {
  string element;
  map<string, int> freq_tracker;
  map<string, vector<string>> final_ans;

  unsigned int pow_set_size = pow(2, 4);
  int counter, j;

  for (counter = 0; counter < pow_set_size; counter++) {
    for (j = 0; j < set_size; j++) {
      if (counter & (1 << j)) element += set[j];
    }
    // `element` has an element of powerset
    for (int i = 0; i < columns.size(); i++) {
      string key_val = "";
      for (int j = 0; j < element.size(); j++) {
        key_val += to_string(columns[i][revcode[element[j]]]);
      }
      if (freq_tracker.find(key_val) == freq_tracker.end()) {
        freq_tracker.insert(pair<string, int>(key_val, 1));
      } else {
        freq_tracker[key_val]++;
      }
    }
    for (const auto& sm_pair : freq_tracker) {
      if (sm_pair.second == 1) {
        if (final_ans.find(element) == final_ans.end()) {
          final_ans.insert(
              pair<string, vector<string>>(element, vector<string>()));
          final_ans[element].push_back(sm_pair.first);
        } else {
          final_ans[element].push_back(sm_pair.first);
        }
      }
    }
    element = "";
    freq_tracker.clear();
  }

  for (const auto& sm_pair : final_ans) {
    cout << sm_pair.first << endl;
    for (int i = 0; i < sm_pair.second.size(); i++) {
      cout << sm_pair.second[i] << endl;
    }
    cout << "------------------------" << endl;
  }
}

int main() {
  string a =
      "11111 1 1 1 1\n\
12222 1 2 2 2\n\
13333 2 1 3 3\n\
14444 2 2 1 4\n\
15555 3 1 2 1\n\
16666 3 2 3 2\n\
17777 1 3 1 3\n\
18888 2 3 2 4\n\
19999 3 3 3 1\n\
20000 1 1 1 2\n\
21111 2 2 2 3\n\
22222 3 3 3 4\n\
22223 4 1 1 1\n\
22224 4 2 2 2\n\
22225 4 3 3 3\n\
22226 4 4 4 4";

  vector<vector<int>> cols;

  istringstream ss(a);
  string token;

  vector<int> temp;
  while (getline(ss, token, '\n')) {
    temp.clear();
    istringstream inner(token);
    string t;
    while (getline(inner, t, ' ')) {
      temp.push_back(stoi(t));
    }
    cols.push_back(temp);
  }
  string set = "abcd";
  int set_size = 4;
  print_unicities(cols, set, set_size);
}
