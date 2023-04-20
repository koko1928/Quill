#ifndef CASE_H
#define CASE_H

#include "token.h"
#include <unordered_map>

class Case {
public:
  static TokenType getKeywordType(const std::string& keyword) {
    static const std::unordered_map<std::string, TokenType> keywordMap = {
      {"if", TokenType::IF},
      {"else", TokenType::ELSE},
      {"for", TokenType::FOR},
      {"while", TokenType::WHILE},
      {"do", TokenType::DO},
      {"break", TokenType::BREAK},
      {"continue", TokenType::CONTINUE},
      {"return", TokenType::RETURN}
    };
    auto it = keywordMap.find(keyword);
    return it != keywordMap.end() ? it->second : TokenType::IDENTIFIER;
  }
};

#endif // CASE_H
