#pragma once

#include <Parser_.hpp>
#include <Node/Expr/Value/Char.hpp>
#include <Node/Type/Numeric/Integer.hpp>

#include <string>

namespace Parser {

class Char: public Parser_ <Node::Expr::Value::Char> {

public:
    Char(): Parser_ <Node::Expr::Value::Char> () {}

    explicit Numeric_(Node::Expr::Value::Char * value):
            Parser_ <Node::Expr::Value::Char> (value)
    {}

    void parse(std::string && text) override {
        using namespace Node::Expr::Value;

        if (value == nullptr) {
            value = new Value::Chat(nullptr);
        }

        const char * cursor = text.c_str();
        for (int i = 0; * cursor && state != END) {
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

                case END:
                    // Unreachable statement, but compiler warns on this
                    break;
            }

            ++cursor;
        }

        try {
            if (state == END) {
                throw std::string("bad character ") + * cursor;
            }

            if (!hasNumberChars) {
                throw std::string("empty number");
            }

            if (number[0] == '-' && !this->value->type->_signed) {
                // TODO warn
                throw std::string("negative number with unsigned flag");
            }

            if (!length.empty()) {
                int len = std::stoi(length);

                this->value->type->bits = static_cast<Node::Type::Numeric_::BitsType>(len);
                if (static_cast<int>(this->value->type->bits) != len) {
                    throw std::string("bad length");
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

private:
    enum {
        SIGN, PREFIX, NUMBER, UNSIGNED, TYPE, LENGTH, END
    } state = SIGN;

    std::string number, length;
};

template <class T, class V>
constexpr int Numeric_<T, V>::NUMBERS[256];

}
