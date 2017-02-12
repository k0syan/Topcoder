#include <iostream>
#include <string>
#include <locale>
using namespace std;

class Genetics() {
  public string getOffspring(string g1, string g2, string dom) {
    string returnString = "";

    for(int i = 0; i < string.length(); ++i) {
      if (g1[i] == g2[i]) {
        returnString += g1[i];
      } else {
        if(dom[i] == "D") {
          returnString += toupper(g1[i]);
        } else {
          returnString += tolower(g2[i]); 
        }
      }
    }
    return returnString;
  }
};


void main() {
  
}
