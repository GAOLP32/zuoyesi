#include <iostream>
#include <fstream>
#include <ctime>
#include<string>
#include <cstdlib>

using namespace std;

// 生成指定范围内的随机整数
int generateRandomNumber(int maxNum) {
    return rand() % (maxNum + 1);
}

// 生成带括号的四则运算表达式
string generateExpression(int maxNum, bool withParentheses, bool withDecimal) {
    int num1 = generateRandomNumber(maxNum);
    int num2 = generateRandomNumber(maxNum);
    int num3 = generateRandomNumber(maxNum);
    char op1 = "+-*/"[rand() % 4];
    char op2 = "+-*/"[rand() % 4];

    string expression;

    if (withParentheses && rand() % 2 == 0) {
        expression += "(";
    }

    expression += to_string(num1);
    expression += op1;
    expression += to_string(num2);

    if (withParentheses && rand() % 2 == 0) {
        expression += ")";
    }

    expression += op2;
    expression += to_string(num3);

    if (withDecimal && rand() % 2 == 0) {
        expression += ".";
        expression += to_string(rand() % 100); // 生成小数部分
    }

    return expression;
}

// 生成指定数量的四则运算题目
void generateExercises(int numExercises, int maxNum, bool withParentheses, bool withDecimal, char op) {
    ofstream outputFile("exercises.txt"); // 将题目输出到文件中

    if (!outputFile.is_open()) {
        cout << "错误：无法打开文件进行写入。" << endl;
        return;
    }

    srand(time(0)); // 使用当前时间作为随机种子

    for (int i = 0; i < numExercises; ++i) {
        string expression = generateExpression(maxNum, withParentheses, withDecimal);

        // 如果用户指定了运算符，替换表达式中的运算符
        if (op != '\0') {
            for (char& c : expression) {
                if (c == '+' || c == '-' || c == '*' || c == '/') {
                    c = op;
                }
            }
        }

        outputFile << expression << " =" << endl;
    }

    outputFile.close();

    cout << "题目生成成功，请检查 'exercises.txt' 文件。" << endl;
}

int main() {
    int numExercises, maxNum;
    char op;
    bool withParentheses, withDecimal;

    cout << "请输入题目数量：";
    cin >> numExercises;

    cout << "请输入最大数值：";
    cin >> maxNum;

    cout << "是否需要括号？（1 表示是，0 表示否）：";
    cin >> withParentheses;

    cout << "是否需要小数？（1 表示是，0 表示否）：";
    cin >> withDecimal;

    cout << "请输入运算符（+、-、*、/），或者输入 0 生成随机运算符：";
    cin >> op;

    generateExercises(numExercises, maxNum, withParentheses, withDecimal, op);

    return 0;
}
