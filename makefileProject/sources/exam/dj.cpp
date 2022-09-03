#include <iostream>
#include <vector>

using namespace std;

int main() {
  string str;
  cin >> str;
  int len = str.size();
  if (len == 0)
    return 0;
  if (str.size()/2%3==1)
    str += "00";
  else if (str.size()/2%3==2)
    str += "0";
  vector<char> res;
  for (int i = 0; i < str.size(); i+=6) {
    unsigned int cur = 0;
    if (str[i] >= 'a') {
      if (str[i] >= 'A')
        cur += 16*256*256*(str[i]-'A');
      else
        cur += 16*256*256*(str[i]-'a');
    } else cur += 16*256*256*(str[i]-'0');
    if (str[i+1] >= 'a') {
      if (str[i+1] >= 'A')
        cur += 256*256*(str[i+1]-'A');
      else
        cur += 256*256*(str[i+1]-'a');
    } else cur += 256*256*(str[i+1]-'0');
    if (str[i+2] >= 'a') {
      if (str[i+2] >= 'A')
        cur += 16*256*(str[i+2]-'A');
      else
        cur += 16*256*(str[i+2]-'a');
    } else cur += 16*256*(str[i+2]-'0');
    if (str[i+3] >= 'a') {
      if (str[i+3] >= 'A')
        cur += 256*(str[i+3]-'A');
      else
        cur += 256*(str[i+3]-'a');
    } else cur += 256*(str[i+3]-'0');
    if (str[i+4] >= 'a') {
      if (str[i+4] >= 'A')
        cur += 16*(str[i+4]-'A');
      else
        cur += 16*(str[i+4]-'a');
    } else cur += 16*(str[i+4]-'0');
    if (str[i+5] >= 'a') {
      if (str[i+5] >= 'A')
        cur += (str[i+5]-'A');
      else
        cur += (str[i+5]-'a');
    } else cur += (str[i+5]-'0');
    cout << "cur = " << cur << "  " << 4096*64 << endl;
    vector<unsigned int> nn = {cur/262144, cur/4096, cur/64, cur%64};
    for (int j = 0; j < 4; j++) {
      int n1 = nn[j];
      if (n1<=25) {
        char ch = n1-0+'A';
        res.push_back(ch);
      } else if (n1<=51) {
        char ch = n1-26+'a';
        res.push_back(ch);
      } else {
        if (n1=62)
          res.push_back('+');
        if (n1=63)
          res.push_back('/');
      }
    }
  }
  if (len/2%3==1) {
    res[res.size()-1] = '=';
    res[res.size()-2] = '=';
  } else if (len/2%3==2)
    res[res.size()-1] = '=';
  for (int i = 0; i < res.size(); i++) {
      cout << res[i];
  }
}