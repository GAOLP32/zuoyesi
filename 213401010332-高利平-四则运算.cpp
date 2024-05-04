#include <iostream>
#include <cstdlib>
#include <ctime>

// 生成一个随机整数
int generate_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// 生成一年级的加法或减法运算式
void generate_grade_one_exercise(int count, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int num1 = generate_random(min, max);
        int num2 = generate_random(min, max);
        int operation = generate_random(0, 1); // 0表示加法，1表示减法
        char oper;
        if (operation == 0) {
            oper = '+';
        }
        else {
            oper = '-';
        }
        std::cout << num1 << " " << oper << " " << num2 << " = " << std::endl;
    }
}

// 生成二年级的加法和减法混合运算式
void generate_grade_two_exercise(int count, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int num1 = generate_random(min, max);
        int num2 = generate_random(min, max);
        int operation = generate_random(0, 1); // 0表示加法，1表示减法
        char oper;
        if (operation == 0) {
            oper = '+';
        }
        else {
            oper = '-';
        }
        std::cout << num1 << " " << oper << " " << num2 << " = " << std::endl;
    }
}

// 生成三年级的加法、减法和乘法混合运算式
void generate_grade_three_exercise(int count, int min, int max) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int num1 = generate_random(min, max);
        int num2 = generate_random(min, max);
        int operation = generate_random(0, 2); // 0表示加法，1表示减法，2表示乘法
        char oper;
        if (operation == 0) {
            oper = '+';
        }
        else if (operation == 1) {
            oper = '-';
        }
        else {
            oper = '*';
        }
        std::cout << num1 << " " << oper << " " << num2 << " = " << std::endl;
    }
}

// 生成四到六年级的复杂运算式
void generate_high_grade_exercise(int count, int min, int max, bool need_parentheses) {
    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        int num1 = generate_random(min, max);
        int num2 = generate_random(min, max);
        int num3 = generate_random(min, max);
        char ops[4] = { '+', '-', '*', '/' };
        char op1 = ops[generate_random(0, 3)];
        char op2 = ops[generate_random(0, 3)];

        if (need_parentheses) {
            std::cout << "(" << num1 << " " << op1 << " " << num2 << ") " << op2 << " " << num3 << " = " << std::endl;
        }
        else {
            std::cout << num1 << " " << op1 << " " << num2 << " " << op2 << " " << num3 << " = " << std::endl;
        }
    }
}

int main() {
    int grade, num_questions, min_range, max_range;

    std::cout << "请输入年级（1-6）：";
    std::cin >> grade;

    std::cout << "请输入题目数量：";
    std::cin >> num_questions;

    std::cout << "请输入最小范围：";
    std::cin >> min_range;

    std::cout << "请输入最大范围：";
    std::cin >> max_range;

    switch (grade) {
    case 1:
        generate_grade_one_exercise(num_questions, min_range, max_range);
        break;
    case 2:
        generate_grade_two_exercise(num_questions, min_range, max_range);
        break;
    case 3:
        generate_grade_three_exercise(num_questions, min_range, max_range);
        break;
    case 4:
    case 5:
    case 6:
        generate_high_grade_exercise(num_questions, min_range, max_range, true); // 需要括号
        break;
    default:
        std::cout << "请输入有效的年级（1-6）！" << std::endl;
        break;
    }

    return 0;
}
