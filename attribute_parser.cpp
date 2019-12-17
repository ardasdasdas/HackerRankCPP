#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int c, q;
  cin >> c;
  cin >> q;

  // Presetup for parsing
  unordered_map<string, string> attrs = {};
  string prefix = "";

  // Loop through the input
  for (int i = 0; i <= c; ++i) {
    // Get line
    string input;
    getline(cin, input);
    // cout << input << endl;

    // Split line into tokens (words)
    vector<string> tokens;
    istringstream iss(input);
    copy(istream_iterator<string>(iss), istream_iterator<string>(),
         back_inserter(tokens));

    // Loop through the tokens vector
    string nametag = "";
    for_each(tokens.begin(), tokens.end(), [&](string token) {
      if (token[0] == '<' && token[1] != '/') {
        // Check for opening tag
        size_t pos = token.find('>') - 1;
        prefix += ((prefix == "") ? "" : ".") + token.substr(1, pos);
      } else if (token[0] == '<' && token[1] == '/') {
        // Check for closing tag
        size_t pos = prefix.find_last_of('.');
        prefix = (pos != string::npos) ? prefix.substr(0, pos) : "";
      } else if (token[0] == '"') {
        // Check for value tag
        attrs[nametag] = token.substr(1, token.find_last_of('"') - 1);
      } else if (token[0] != '=') {
        // We found a name tag
        nametag = prefix + "~" + token;
      }
    });
  }

  // Loop through the queries
  for (int i = 0; i < q; ++i) {
    // Get line
    string query;
    getline(cin, query);

    // Execute query
    if (attrs.find(query) != attrs.end()) {
      cout << attrs[query] << endl;
    } else {
      cout << "Not Found!" << endl;
    }
  }
  return 0;
}
