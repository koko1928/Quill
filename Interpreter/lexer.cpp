vector<Token> Lexer::tokenize(string code) {
    vector<Token> tokens;

    string buffer;
    TokenType type = TokenType::IDENTIFIER;

    for (char c : code) {
        if (isspace(c)) {
            if (!buffer.empty()) {
                add_token(tokens, type, buffer);
                buffer.clear();
                type = TokenType::IDENTIFIER;
            }
        } else if (isalpha(c)) {
            if (type == TokenType::NUMBER) {
                buffer += c;
            } else {
                if (type == TokenType::IDENTIFIER) {
                    buffer += c;
                } else {
                    add_token(tokens, type, buffer);
                    buffer.clear();
                    type = TokenType::IDENTIFIER;
                    buffer += c;
                }
            }
        } else if (isdigit(c)) {
            if (type == TokenType::IDENTIFIER || type == TokenType::NUMBER) {
                buffer += c;
            } else {
                add_token(tokens, type, buffer);
                buffer.clear();
                type = TokenType::NUMBER;
                buffer += c;
            }
        } else if (c == '"') {
            if (!buffer.empty()) {
                add_token(tokens, type, buffer);
                buffer.clear();
            }
            string_literal(tokens);
        } else {
            if (!buffer.empty() && is_operator_char(c)) {
                add_token(tokens, type, buffer);
                buffer.clear();
                operator_literal(tokens, c);
            } else {
                buffer += c;
            }
        }
    }

    if (!buffer.empty()) {
        add_token(tokens, type, buffer);
    }

    return tokens;
}
