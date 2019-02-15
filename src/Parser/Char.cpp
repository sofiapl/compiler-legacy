#include "Char.hpp"

#include <sstream>

std::u16string Parser::Char::prepareUnicode(const std::string & text) {
    static std::wstring_convert <std::codecvt_utf8_utf16 <char16_t>, char16_t> converter;
    std::u16string u16text = converter.from_bytes(text);

    std::u16string ret;
    for (auto it = u16text.begin(); it != u16text.end(); ++it) {
        bool fail = false;
        auto start = it;

        do {
            if (* it != u'\\') {
                fail = true;
                break;
            }
            ++it;

            if (* it != u'u') {
                fail = true;
                break;
            }

            ++it;

            std::stringstream numStream;
            for (int i = 0; it != ret.end() && i < 4; ++i, ++it) {
                if (
                    (* it < u'0' || * it > u'9') &&
                    (* it < u'A' || * it > u'F') &&
                    (* it < u'a' || * it > u'f')
                ) {
                    fail = true;
                    break;
                }

                numStream << * it;
            }

            if (!fail) {
                uint16_t charCode;
                numStream >> std::hex >> charCode;

                ret.push_back(static_cast<char16_t>(charCode));
            }
        } while (false);

        if (fail) {
            ret.append(start, it + 1);
        }
    }

    return ret;
}

void Parser::Char::parse(const std::string & text) {
    using namespace Node::Expr;

    if (value == nullptr) {
        value = new Value::Char(nullptr);
    }

    // TODO

    auto cursor = text.begin();
    for (int i = 0; cursor != text.end(); ++i) {
        // TODO One char parsing

        ++cursor;
    }
}
