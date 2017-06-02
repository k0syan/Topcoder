#include <iostream>
#include <string>
#include <locale>

using namespace std;

class Genetics {
  public:
    string getOffspring(string g1, string g2, string dom) {
      string answer = "";
      for (int i = 0; i < g1.length(); ++i) {
        if (g1[i] == g2[i]) {
          answer += g1[i];
        } else if (dom[i] == 'D') {
            answer += toupper(g1[i]);
        } else {
            answer += tolower(g1[i]);
        }
      }
      return answer;
    }
};
