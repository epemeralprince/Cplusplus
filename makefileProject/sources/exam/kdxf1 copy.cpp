#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


 struct Point {
	int x;
	int y;
	Point(int xx, int yy) : x(xx), y(yy) {}
 };
 
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 求四个点的面积
     * @param p1 Point类 点1
     * @param p2 Point类 点2
     * @param p3 Point类 点3
     * @param p4 Point类 点4
     * @return long长整型
     */
    long long getArea(Point p1, Point p2, Point p3, Point p4) {
        // write code here
        vector<Point> points = {p1, p2, p3, p4};
        for (int i = 0; i < 4-1; i++) {
            for (int j = i+1; j < 4; j++) {
                if (points[i].x > points[j].x) {
                    Point temp = points[i];
                    points[i] = points[j];
                    points[j] = temp;
                }    
            }
        }
        long double a = sqrt(pow(points[0].x-points[1].x, 2)+pow(points[0].y-points[1].y, 2));
        long double b = sqrt(pow(points[1].x-points[3].x, 2)+pow(points[1].y-points[3].y, 2));
        long double c = sqrt(pow(points[0].x-points[3].x, 2)+pow(points[0].y-points[3].y, 2));
        long double p = (a+b+c)/2;
        long double s1 = sqrt(p*(p-a)*(p-b)*(p-c));
        cout << "s1  = " << s1 << endl;
        a = sqrt(pow(points[0].x-points[2].x, 2)+pow(points[0].y-points[2].y, 2));
        b = sqrt(pow(points[2].x-points[3].x, 2)+pow(points[2].y-points[3].y, 2));
        c = sqrt(pow(points[0].x-points[3].x, 2)+pow(points[0].y-points[3].y, 2));
        p = (a+b+c)/2;
        long double s2 = sqrt(p*(p-a)*(p-b)*(p-c));
        cout << "s2  = " << s2 << endl;

        long double s = s1 + s2;
        cout << "s = " << s << endl;
        return s;
    }
};


int main() {
    Point p1(1, 1);
    Point p2(2, 2);
    Point p3(1, 3);
    Point p4(0, 2);
    Solution solution;
    long long res = solution.getArea(p1, p2, p3, p4);
    cout << res << endl;
}