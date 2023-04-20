#ifndef TOKEN_H
#define TOKEN_H

#include <string>

enum class TokenType {
  // Keywords
  IF, ELSE, FOR, WHILE, DO, BREAK, CONTINUE, RETURN,

  // Literals
  IDENTIFIER, NUMBER, STRING,

  // Operators
  PLUS, MINUS, ASTERISK, SLASH, PERCENT,
  EQUAL, NOT_EQUAL, GREATER, GREATER_EQUAL, LESS, LESS_EQUAL,
  LOGICAL_AND, LOGICAL_OR, ASSIGN,

  // Punctuators
  LEFT_PAREN, RIGHT_PAREN, LEFT_BRACE, RIGHT_BRACE,
  COMMA, SEMICOLON, COLON
};

struct Token {
  TokenType type;
  std::string lexeme;
  int line;
};

#endif // TOKEN_H
