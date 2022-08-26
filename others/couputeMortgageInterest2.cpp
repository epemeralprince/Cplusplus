#include <iostream>

using std::cout;
using std::endl;

/*
等额本金,每个月还款
*/

int main(int argc, char* argv[]) {
    if (argc < 3) return 0;
    int oweMoney = std::stoi(argv[1]);
    int months = std::stoi(argv[2]);
    double rate = std::stod(argv[3])/100/12;
    cout << "owe money: " << oweMoney << "w" << endl;
    cout << "monthes: " << months << endl;
    cout << "month rate: " << rate << endl;
    int totalOwe = oweMoney*10000;
    double baseMoney = oweMoney*10000/months;
    double totalInte = 0.0;
    for  (int i = 0; i < months; i++) {
        int curMonthInte = (totalOwe-baseMoney*i)*rate;
        totalInte += curMonthInte;
        cout << i+1 << ": "<< "cur Month Interest = " << curMonthInte << "  total month return = " << curMonthInte+baseMoney << endl;
    }
    cout << "cur Month pay back baseMoney = " << baseMoney << endl;

    cout << "total interest: " << totalInte << endl;
    
}