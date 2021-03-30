#include <iostream>
#include <string>
#include <vector>

class Token
{
public:
    enum
    {
        INT,
        CHAR,
        DBL,
        STR,
    } tok;
    union
    {
        int ival;
        char cval;
        double dval;
        std::string sval;
    };
    Token() : tok(INT), ival{0} { std::cout << "Token() : tok(INT), ival{0}" << std::endl; }
    Token(const Token &t) : tok(t.tok)
    {
        std::cout << "Token(const Token &t) : tok(t.tok)" << std::endl;
        copyUnion(t);
    }
    Token &operator=(const Token &);
    ~Token()
    {
        if (tok == STR)
        {
            sval.std::string::~string();
        }
    };
    Token &operator=(const std::string &);
    Token &operator=(char);
    Token &operator=(int);
    Token &operator=(double);

private:
    void copyUnion(const Token &);
};
Token &Token::operator=(int i)
{
    if (tok == STR)
    {
        sval.std::string::~string();
    }
    ival = i;
    tok = INT;
    return *this;
};
Token &Token::operator=(char i)
{
    if (tok == STR)
    {
        sval.std::string::~string();
    }
    cval = i;
    tok = CHAR;
    return *this;
};

Token &Token::operator=(double i)
{
    if (tok == STR)
    {
        sval.std::string::~string();
    }
    dval = i;
    tok = DBL;
    return *this;
};
Token &Token::operator=(const std::string &s)
{
    if (tok == STR)
    {
        sval = s;
    }
    else
    {
        new (&sval) std::string(s);
    }
    tok = STR;
    return *this;
};

void Token::copyUnion(const Token &t)
{
    switch (t.tok)
    {
    case Token::INT:
        ival = t.ival;
        break;
    case Token::CHAR:
        cval = t.cval;
        break;
    case Token::DBL:
        dval = t.dval;
        break;
    case Token::STR:
        new (&sval) std::string(t.sval);
        break;
    };
};

Token &Token::operator=(const Token &t)
{
    if (tok == STR && t.tok != STR)
    {
        sval.std::string::~string();
    }
    else if (tok == STR && t.tok == STR)
    {
        sval = t.sval;
    }
    else
    {
        copyUnion(t);
    }
    tok = t.tok;
    return *this;
}

int main()
{

    std::vector<Token> container;

    Token temp1;
    int data1 = 1000;
    temp1 = data1;
    container.push_back(temp1);

    Token temp2;
    std::string data2 = "字符串";
    temp2 = data2;
    container.push_back(temp2);

    Token temp3;
    double data3 = 0.001;
    temp3 = data3;
    container.push_back(temp3);

    Token temp4;
    char data4 = 'p';
    temp4 = data4;
    container.push_back(temp4);

    std::cout << "---------装载完毕，开始迭代----------" << std::endl;
    for (Token oneToken : container)
    {
        std::cout << oneToken.tok << std::endl;
    }
}