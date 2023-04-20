#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "case.h"
#include <vector>

class Lexer {
public:
  Lexer(const std::string& source) : source_(source), current_(0), line_(1) {}

  std::vector<Token> scanTokens();

private:
  void scanToken();

  char advance();
  void addToken(TokenType type);
  void addToken(TokenType type, const std::string& literal);
  bool match(char expected);
  char peek();
  char peekNext();
  bool isDigit(char c);
  bool isAlpha(char c);
  bool isAlphaNumeric(char c);
  void string();
  void number();
  void identifier();

  const std::string& source_;
  std::vector<Token> tokens_;
  int current_;
  int line_;
};

#endif // LEXER_H
