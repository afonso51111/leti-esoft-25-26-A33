#include <locale>
#include <algorithm>
#include "headers/domain/shared/StringUtils.h"

wstring StringUtils::toUpperCase(const wstring &value) {
    std::locale::global(std::locale(""));
    wstring copy = value;
    for (int x=0; x < value.size(); x++)
        copy[x] = towupper(value[x]);
    return copy;
}

wstring StringUtils::toLowerCase(const wstring &value) {
    std::locale::global(std::locale(""));
    wstring copy = value;
    for (int x=0; x < value.size(); x++)
        copy[x] = towlower(value[x]);
    return copy;
}

wstring StringUtils::leftTrim(const wstring &value) {
    wstring copy = value;
    copy.erase(copy.begin(), std::find_if(copy.begin(), copy.end(), [](wchar_t ch) {
        return !std::isspace(ch);
    }));
    return copy;
}

wstring StringUtils::rightTrim(const wstring &value) {
    wstring copy = value;
    copy.erase(std::find_if(copy.rbegin(), copy.rend(), [](wchar_t ch) {
        return !std::isspace(ch);
    }).base(), copy.end());
    return copy;
}

wstring StringUtils::trim(const wstring &value) {
    return rightTrim(leftTrim(value));
}

bool StringUtils::ensureNotNullOrEmpty(const wstring &value) {
    return ensureNotNullOrEmpty(value, 1);
}

bool StringUtils::ensureNotNullOrEmpty(const wstring &value, int minLength) {
    if (!value.empty()){
        if (minLength < 1)
            minLength = 1;
        return (trim(value).length() >= minLength);
    }
    return false;
}