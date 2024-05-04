#include <iostream>
#include <fstream>
#include <ctime>
#include<string>
#include <cstdlib>

using namespace std;

// ����ָ����Χ�ڵ��������
int generateRandomNumber(int maxNum) {
    return rand() % (maxNum + 1);
}

// ���ɴ����ŵ�����������ʽ
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
        expression += to_string(rand() % 100); // ����С������
    }

    return expression;
}

// ����ָ������������������Ŀ
void generateExercises(int numExercises, int maxNum, bool withParentheses, bool withDecimal, char op) {
    ofstream outputFile("exercises.txt"); // ����Ŀ������ļ���

    if (!outputFile.is_open()) {
        cout << "�����޷����ļ�����д�롣" << endl;
        return;
    }

    srand(time(0)); // ʹ�õ�ǰʱ����Ϊ�������

    for (int i = 0; i < numExercises; ++i) {
        string expression = generateExpression(maxNum, withParentheses, withDecimal);

        // ����û�ָ������������滻���ʽ�е������
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

    cout << "��Ŀ���ɳɹ������� 'exercises.txt' �ļ���" << endl;
}

int main() {
    int numExercises, maxNum;
    char op;
    bool withParentheses, withDecimal;

    cout << "��������Ŀ������";
    cin >> numExercises;

    cout << "�����������ֵ��";
    cin >> maxNum;

    cout << "�Ƿ���Ҫ���ţ���1 ��ʾ�ǣ�0 ��ʾ�񣩣�";
    cin >> withParentheses;

    cout << "�Ƿ���ҪС������1 ��ʾ�ǣ�0 ��ʾ�񣩣�";
    cin >> withDecimal;

    cout << "�������������+��-��*��/������������ 0 ��������������";
    cin >> op;

    generateExercises(numExercises, maxNum, withParentheses, withDecimal, op);

    return 0;
}
