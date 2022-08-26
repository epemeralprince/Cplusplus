#include <iostream>
#include <tuple>
#include <vector>
#include <iomanip>

using std::cout;
using std::endl;
using std::tuple;
using std::vector;

using std::left;
using std::right;
using std::setw;

static double rate_y = 5.88;

/*
等额本息,每个月还款
*/
tuple<double, double> fun1(int totalLoan, int totalMonths, double rate_year=rate_y) {
    double rate = rate_year/100/12;
    //cout << "owe money: " << totalLoan << " yuan" << endl;
    //cout << "monthes: " << totalMonths << endl;
    //cout << "month rate: " << rate << endl;
    double a = 1.0;
    for  (int i = 0; i < totalMonths; i++) {
        a *= (1+rate);
        //cout << i+1 << ": "<< "a = " << a << endl;
    }
    //cout << "a = " << a << endl;
    double everyMonthInterest = totalLoan*10000*(rate*a)/(a-1);
    //cout << "every month pay back a debt: " << everyMonthInterest << endl;
    double totalInterest = everyMonthInterest*totalMonths-totalLoan*10000;
    //cout << "total interest: " << totalInterest << endl;
    return {totalInterest, everyMonthInterest};
}


/*
等额本金,每个月还款
*/
tuple<double, vector<double>> fun2(int totalLoan, int totalMonths, double rate_year=rate_y) {
    double rate = rate_year/100/12;
    //cout << "owe money: " << totalLoan << " yuan" << endl;
    //cout << "monthes: " << totalMonths << endl;
    //cout << "month rate: " << rate << endl;
    int totalOwe = totalLoan*10000;
    double baseMoney = totalLoan*10000/totalMonths;
    double totalInte = 0.0;
    vector<double> everyMonthInterest(totalMonths);
    for  (int i = 0; i < totalMonths; i++) {
        int curMonthInte = (totalOwe-baseMoney*i)*rate;
        everyMonthInterest[i] = baseMoney+curMonthInte;
        totalInte += curMonthInte;
        //cout << i+1 << ": "<< "cur Month Interest = " << curMonthInte << "  total month return = " << curMonthInte+baseMoney << endl;
    }
    //cout << "cur Month pay back baseMoney = " << baseMoney << endl;
    //cout << "total interest: " << totalInte << endl;
    return {totalInte, everyMonthInterest};
}

int main() {
    for (int loan = 20; loan <= 200; loan+=20) {
        for (int year = 5; year <= 30; year+=5) {
            tuple<double, double> res1 = fun1(loan, year*12);
            tuple<double, vector<double>> res2 = fun2(loan, year*12);
            double totalInterest1 = std::get<0>(res1), totalInterest2 = std::get<0>(res2);
            double EMInte1 = std::get<1>(res1);
            vector<double> EMInte2 = std::get<1>(res2);
            double startDis = EMInte1-EMInte2[0], endDis = EMInte1-EMInte2[EMInte2.size()-1];
            int minDis = startDis, minIndex = 0;
            for (int i = 0; i < EMInte2.size(); i++) {
                double curDis = EMInte1-EMInte2[i];
                if (abs(curDis) < abs(minDis)) {
                    minDis = curDis;
                    minIndex = i+1;
                }
            }
            cout << "loan=" << left << setw(3) << loan << "  year=" << setw(2) << year <<": " << right << 
            setw(7) << int(totalInterest1) << " " << setw(7) << int(totalInterest2) << " " << 
            setw(7) << int(totalInterest1 - totalInterest2) << "  " <<
            setw(7) << int(EMInte1) << " " << setw(7) << int(EMInte2[0]) << "  " <<  setw(7) << int(EMInte2[EMInte2.size()-1]) <<
            setw(7) << int(startDis) << " " << setw(7) << int(endDis) << "  " << 
            setw(4) << int(minDis) << "  " << setw(3) << minIndex << '/' << left << setw(3) << year*12 << endl;;
        }
        cout << endl;
    }
}