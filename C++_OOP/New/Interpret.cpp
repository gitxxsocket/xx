
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
using namespace std;

//抽象的表达式对象以及Context对象
//用于保存计算的中间结果以及当前执行的操作符 用在算法当中
// 解析器模式

class Context {
public:
    int m_value;
    char m_operator;
    Context() : m_value(0), m_operator('\0') {}
protected:
};

//所有表达式的抽象接口
class IExpression {
public:
    virtual void Eval(Context *pContext) = 0;
protected:
};

//拆分元素
class Opreator : public IExpression {
    char m_op;
public:
    Opreator(char mOp) {
        this->m_op = mOp;
    }
    void Eval(Context *pContext) override {
        pContext->m_operator = m_op;
    }
protected:
};

//拆分操作数
class Operand : public IExpression {
public:
    Operand(int num) {
        this->m_num = num;
    }
    void Eval(Context *pContext) override {
        switch (pContext->m_operator) {
            case '\0':
                pContext->m_value = m_num;
                break;
            case '+':
                pContext->m_value += m_num;
                break;
            case '-':
                pContext->m_value -= m_num;
                break;
            default:
                break;
        }
    }
private:
    int m_num;
};

class Calculator {
public:
    int Calc(string expression) {
        auto pContext = new Context;
        vector<IExpression *> tree;
        for (int i = 0; i < expression.size(); i++) {
            if ((expression[i] == '+') || (expression[i] == '-')) {
                tree.push_back(new Operand(expression[i]));
                printf("第%d次压入是 %c\n", i, expression[i]);
            } else {
                tree.push_back(new Operand((int) (expression[i] - 48)));
                printf("第%d次压入是 %d\n", i, ((int) (expression[i] - 48)));
            }
        }
        for (vector<IExpression *>::iterator iter = tree.begin(); iter != tree.end(); iter++) {
            (*iter)->Eval(pContext);
            printf("value = %d ,oper = $c \n", pContext->m_value, pContext->m_operator);
        }
        return pContext->m_value;
    }
protected:
};

int main() {
    auto pCalculator = new Calculator;
    cout <<"1+3-2= " <<pCalculator->Calc("1+3-2")<<endl;
    return 0;
}