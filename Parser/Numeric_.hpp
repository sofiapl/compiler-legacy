#pragma once

#include <Parser_.hpp>
#include <Node/Expr/Value/Numeric_.hpp>
#include <Node/Type/Numeric/Integer.hpp>

#include <string>

namespace Parser {

template <class T, class V>
class Numeric_: public Parser_ <Node::Expr::Value::Numeric_ <T, V> > {

public:
    typedef T TypeType;
    typedef V ValueType;

    static constexpr int NUMBERS[256] {
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            0, // 0
            1, // 1
            2, // 2
            3, // 3
            4, // 4
            5, // 5
            6, // 6
            7, // 7
            8, // 8
            9, // 9
            -1, -1, -1, -1, -1, -1, -1,
            10, // A
            11, // B
            12, // C
            13, // D
            14, // E
            15, // F
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            10, // a
            11, // b
            12, // c
            13, // d
            14, // e
            15, // f
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
            -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1
    };

    Numeric_(): Parser_ <Node::Expr::Value::Numeric_ <T, V> > () {}

    explicit Numeric_(Node::Expr::Value::Numeric_ <T, V> * value):
            Parser_ <Node::Expr::Value::Numeric_ <T, V> > (value)
    {}

    void parse(std::string && text) override {
        if (this->value == nullptr) {
            initValue();
        }

        bool hasNumberChars = false;
        const char * cursor = text.c_str();
        while (* cursor && state != END) {
            switch (state) {
                case SIGN:
                    if (* cursor == '-') {
                        number = '-';
                    } else {
                        --cursor;
                    }

                    state = PREFIX;
                    break;

                case PREFIX:
                    if (* cursor == '0') {
                        ++cursor;

                        switch (* cursor) {
                            case 'x':
                                this->value->radix = 16;
                                break;

                            case 'b':
                                this->value->radix = 2;
                                break;

                            case '0':
                            case '1':
                            case '2':
                            case '3':
                            case '4':
                            case '5':
                            case '6':
                            case '7':
                                this->value->radix = 8;
                                --cursor;
                                break;

                            default:
                                // The first "0" isn't a prefix
                                --cursor;
                                --cursor;
                        }
                    } else {
                        // There is no prefix
                        --cursor;
                    }

                    state = NUMBER;
                    break;

                case NUMBER:
                    if (isNumberChar(* cursor)) {
                        hasNumberChars = true;
                        number += * cursor;
                    } else {
                        state = UNSIGNED;
                        --cursor;
                    }

                    break;

                case UNSIGNED:
                    if (* cursor == 'u') {
                        this->value->type->_signed = false;
                    } else {
                        --cursor;
                    }

                    state = TYPE;
                    break;

                case TYPE:
                    if (handleTypeChar(* cursor)) {
                        state = LENGTH;
                    } else {
                        --cursor;
                        state = END;
                    }

                    break;

                case LENGTH:
                    if (* cursor >= '0' && * cursor <= '9') {
                        length += * cursor;
                    } else {
                        state = END;
                        --cursor;
                    }

                    break;
            }

            ++cursor;
        }

        try {
            if (state == END) {
                throw std::string("bad character ") + * cursor;
            }

            if (!hasNumberChars) {
                throw "empty number";
            }

            if (number[0] == '-' && !this->value->type->_signed) {
                // TODO warn
                throw "negative number with unsigned flag";
            }

            if (!length.empty()) {
                int len = std::stoi(length);

                this->value->type->bits = static_cast<Node::Type::Numeric_::BitsType>(len);
                if (static_cast<int>(this->value->type->bits) != len) {
                    throw "bad length";
                }
            }

            makeNumberValue(number);
        } catch (const std::string & e) {
            delete this->value->type;
            delete this->value->value;
            delete this->value;
            this->value = nullptr;

            throw e;
        }
    }

protected:
    virtual void initValue() = 0;
    virtual bool isNumberChar(char c) = 0;
    virtual bool handleTypeChar(char c) = 0;
    virtual void makeNumberValue(const std::string & number) = 0;

private:
    enum {
        SIGN, PREFIX, NUMBER, UNSIGNED, TYPE, LENGTH, END
    } state = SIGN;

    std::string number, length;
};

template <class T, class V>
constexpr int Numeric_<T, V>::NUMBERS[256];

}
