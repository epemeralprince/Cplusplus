#include <iostream>

using std::cout;
using std::endl;

/*
等额本息,每个月还款
*/

int main(int argc, char* argv[]) {
    if (argc < 3) return 0;
    int oweMoney = std::stoi(argv[1]);
    int months = std::stoi(argv[2]);
    double rate = std::stod(argv[3])/100/12;
    cout << "owe money: " << oweMoney << "w" << endl;
    cout << "monthes: " << months << endl;
    cout << "month rate: " << rate << endl;
    double a = 1.0;
    for  (int i = 0; i < months; i++) {
        a *= (1+rate);
        //cout << i+1 << ": "<< "a = " << a << endl;
    }
    cout << "a = " << a << endl;
    double everyMonth = oweMoney*10000*(rate*a)/(a-1);
    cout << "every month pay back a debt: " << everyMonth << endl;
    double totalInterest = everyMonth*months-oweMoney*10000;
    cout << "total interest: " << totalInterest << endl;

}