#include <iostream>
#include <string>
using namespace std;

struct Roman_Num {
    int I = 1;
    int V = 5;
    int X = 10;
    int L = 50;
    int C = 100;
    int D = 500;
    int M = 1000;
    int E = 5000;
    int F = 10000;
};

class Solution {
public:
    Roman_Num structRomanNum;

    int romanToInt(string s) {
        int splitIdx = 0;

        string s1000 = splitRomanNum(s, 1000, splitIdx);    // 在执行完 splitS1000 后，记录当前遍历到哪个 index，方便 splitS100 使用
        string s100 = splitRomanNum(s, 100, splitIdx);    // 在执行完 splitS100 后，记录当前遍历到哪个 index，方便 splitS10 使用
        string s10 = splitRomanNum(s, 10, splitIdx);      // 在执行完 splitS10 后，记录当前遍历到哪个 index，方便 splitS1 使用
        string s1 = splitRomanNum(s, 1, splitIdx);

        int i1000 = convertToInt(s1000, 1000);     // 第二个参数表示千位数
        int i100 = convertToInt(s100, 100);        // 第二个参数表示百位数
        int i10 = convertToInt(s10, 10);           // 第二个参数表示十位数
        int i1 = convertToInt(s1, 1);              // 第二个参数表示个位数

        return i1000 + i100 + i10 + i1;
    }

    // 把 romanNum 的某位数分离出来
    // 输入：原罗马数字，千/百/十/个位数，index 引用（可理解为用于返回两个数据）
    // 输出：组成对应位数的子字符串
    string splitRomanNum(string romanNum, int scale, int& splitIdx) {
        // 配置
        char one, five, ten;
        if (scale == 1000) {
            one = 'M';
            five = 'E';
            ten = 'F';
        }
        else if (scale == 100) {
            one = 'C';
            five = 'D';
            ten = 'M';
        }
        else if (scale == 10) {
            one = 'X';
            five = 'L';
            ten = 'C';
        }
        else {      // 个位数
            one = 'I';
            five = 'V';
            ten = 'X';
        }

        // split
        string scaleSplit = "";
        int start = splitIdx;
        for (; splitIdx < romanNum.size(); splitIdx++) {
            char c = romanNum[splitIdx];
            if (c == one || c == five || c == ten) {
                if (romanNum[start] != ten) {    // ten 不能开头，可以结尾，要符合这种情况
                    scaleSplit += c;
                }
            }
            else {
                break;
            }
        }
        return scaleSplit;
    }

    // 把罗马数字转为整型数字
    // 输入：罗马数字，进制
    // 输出：整型数字
    int convertToInt(string s, int scale) {
        int len = s.length();
        if (len == 0) {
            return 0;
        }

        // 配置
        char one, five, ten;
        int rOne, rFive, rTen;
        if (scale == 1000) {
            one = 'M';
            five = 'E';
            ten = 'F';
            rOne = structRomanNum.M;
            rFive = structRomanNum.E;
            rTen = structRomanNum.F;
        }
        else if (scale == 100) {
            one = 'C';
            five = 'D';
            ten = 'M';
            rOne = structRomanNum.C;
            rFive = structRomanNum.D;
            rTen = structRomanNum.M;
        }
        else if (scale == 10) {
            one = 'X';
            five = 'L';
            ten = 'C';
            rOne = structRomanNum.X;
            rFive = structRomanNum.L;
            rTen = structRomanNum.C;
        }
        else {      // 个位数
            one = 'I';
            five = 'V';
            ten = 'X';
            rOne = structRomanNum.I;
            rFive = structRomanNum.V;
            rTen = structRomanNum.X;
        }

        // convert
        char headCh = s[0];
        char tailCh = s[len - 1];

        if (headCh == one) {
            if (tailCh == one) {
                return len * rOne;
            }
            else if (tailCh == five) {
                return rFive - rOne;
            }
            else {      // 结束字符是 ten
                return rTen - rOne;
            }
        }
        else {      // 起始字符是 five
            return rFive + (len - 1) * rOne;
        }
    }
};

int main() {
    Solution sol;

    // 1-10
    cout << sol.romanToInt("I") << endl;
    cout << sol.romanToInt("II") << endl;
    cout << sol.romanToInt("III") << endl;
    cout << sol.romanToInt("IV") << endl;
    cout << sol.romanToInt("V") << endl;
    cout << sol.romanToInt("VI") << endl;
    cout << sol.romanToInt("VII") << endl;
    cout << sol.romanToInt("VIII") << endl;
    cout << sol.romanToInt("IX") << endl;
    cout << sol.romanToInt("X") << endl;
    cout << endl;

    // 10-20
    cout << sol.romanToInt("XI") << endl;
    cout << sol.romanToInt("XII") << endl;
    cout << sol.romanToInt("XIII") << endl;
    cout << sol.romanToInt("XIV") << endl;
    cout << sol.romanToInt("XV") << endl;
    cout << sol.romanToInt("XVI") << endl;
    cout << sol.romanToInt("XVII") << endl;
    cout << sol.romanToInt("XVIII") << endl;
    cout << sol.romanToInt("XIX") << endl;
    cout << sol.romanToInt("XX") << endl;
    cout << endl;

    // 20-30
    cout << sol.romanToInt("XXI") << endl;
    cout << sol.romanToInt("XXII") << endl;
    cout << sol.romanToInt("XXIII") << endl;
    cout << sol.romanToInt("XXIV") << endl;
    cout << sol.romanToInt("XXV") << endl;
    cout << sol.romanToInt("XXVI") << endl;
    cout << sol.romanToInt("XXVII") << endl;
    cout << sol.romanToInt("XXVIII") << endl;
    cout << sol.romanToInt("XXIX") << endl;
    cout << sol.romanToInt("XXX") << endl;
    cout << endl;

    // 30-40
    cout << sol.romanToInt("XXXI") << endl;
    cout << sol.romanToInt("XXXII") << endl;
    cout << sol.romanToInt("XXXIII") << endl;
    cout << sol.romanToInt("XXXIV") << endl;
    cout << sol.romanToInt("XXXV") << endl;
    cout << sol.romanToInt("XXXVI") << endl;
    cout << sol.romanToInt("XXXVII") << endl;
    cout << sol.romanToInt("XXXVIII") << endl;
    cout << sol.romanToInt("XXXIX") << endl;
    cout << sol.romanToInt("XL") << endl;
    cout << endl;

    // 40-50
    cout << sol.romanToInt("XLI") << endl;
    cout << sol.romanToInt("XLII") << endl;
    cout << sol.romanToInt("XLIII") << endl;
    cout << sol.romanToInt("XLIV") << endl;
    cout << sol.romanToInt("XLV") << endl;
    cout << sol.romanToInt("XLVI") << endl;
    cout << sol.romanToInt("XLVII") << endl;
    cout << sol.romanToInt("XLVIII") << endl;
    cout << sol.romanToInt("XLIX") << endl;
    cout << sol.romanToInt("L") << endl;
    cout << endl;

    // 50-60
    cout << sol.romanToInt("LI") << endl;
    cout << sol.romanToInt("LII") << endl;
    cout << sol.romanToInt("LIII") << endl;
    cout << sol.romanToInt("LIV") << endl;
    cout << sol.romanToInt("LV") << endl;
    cout << sol.romanToInt("LVI") << endl;
    cout << sol.romanToInt("LVII") << endl;
    cout << sol.romanToInt("LVIII") << endl;
    cout << sol.romanToInt("LIX") << endl;
    cout << sol.romanToInt("L") << endl;
    cout << endl;

    // 60-70
    cout << sol.romanToInt("LXI") << endl;
    cout << sol.romanToInt("LXII") << endl;
    cout << sol.romanToInt("LXIII") << endl;
    cout << sol.romanToInt("LXIV") << endl;
    cout << sol.romanToInt("LXV") << endl;
    cout << sol.romanToInt("LXVI") << endl;
    cout << sol.romanToInt("LXVII") << endl;
    cout << sol.romanToInt("LXVIII") << endl;
    cout << sol.romanToInt("LXIX") << endl;
    cout << sol.romanToInt("LX") << endl;
    cout << endl;

    // 70-80
    cout << sol.romanToInt("LXXI") << endl;
    cout << sol.romanToInt("LXXII") << endl;
    cout << sol.romanToInt("LXXIII") << endl;
    cout << sol.romanToInt("LXXIV") << endl;
    cout << sol.romanToInt("LXXV") << endl;
    cout << sol.romanToInt("LXXVI") << endl;
    cout << sol.romanToInt("LXXVII") << endl;
    cout << sol.romanToInt("LXXVIII") << endl;
    cout << sol.romanToInt("LXXIX") << endl;
    cout << sol.romanToInt("LXX") << endl;
    cout << endl;

    // 80-90
    cout << sol.romanToInt("LXXXI") << endl;
    cout << sol.romanToInt("LXXXII") << endl;
    cout << sol.romanToInt("LXXXIII") << endl;
    cout << sol.romanToInt("LXXXIV") << endl;
    cout << sol.romanToInt("LXXXV") << endl;
    cout << sol.romanToInt("LXXXVI") << endl;
    cout << sol.romanToInt("LXXXVII") << endl;
    cout << sol.romanToInt("LXXXVIII") << endl;
    cout << sol.romanToInt("LXXXIX") << endl;
    cout << sol.romanToInt("LXXX") << endl;
    cout << endl;

    // 90-99
    cout << sol.romanToInt("XCI") << endl;
    cout << sol.romanToInt("XCII") << endl;
    cout << sol.romanToInt("XCIII") << endl;
    cout << sol.romanToInt("XCIV") << endl;
    cout << sol.romanToInt("XCV") << endl;
    cout << sol.romanToInt("XCVI") << endl;
    cout << sol.romanToInt("XCVII") << endl;
    cout << sol.romanToInt("XCVIII") << endl;
    cout << sol.romanToInt("XCIX") << endl;
    cout << endl;
    
    cout << sol.romanToInt("C") << endl;        // 100
    cout << sol.romanToInt("CC") << endl;       // 200
    cout << sol.romanToInt("CCC") << endl;      // 300
    cout << sol.romanToInt("CD") << endl;       // 400
    cout << sol.romanToInt("D") << endl;        // 500
    cout << sol.romanToInt("DC") << endl;       // 600
    cout << sol.romanToInt("DCC") << endl;      // 700
    cout << sol.romanToInt("DCCC") << endl;     // 800
    cout << sol.romanToInt("CM") << endl;       // 900
    cout << sol.romanToInt("CMXCIX") << endl;   // 999
    cout << endl;
    
    cout << sol.romanToInt("M") << endl;            // 1000
    cout << sol.romanToInt("MM") << endl;           // 2000
    cout << sol.romanToInt("MMM") << endl;          // 3000
    cout << sol.romanToInt("MMMCMXCIX") << endl;    // 3999
    cout << endl;
}