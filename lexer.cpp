#include <fstream>
#include <iostream>
#include <vector>

enum TokenType {
    NUMBER,
    PLUS,
};

typedef struct {
    TokenType type;
    std::string value;
} Token;

std::vector<Token> tokenize(std::ifstream& source_code) {
    std::vector<Token> tokens;

    char character = source_code.get();

    while (source_code.good()) {
        if (character != ' ') {
            if (std::isdigit(character)) {
                Token number;
                number.type = NUMBER;
                number.value = std::to_string(character - '0');
                tokens.push_back({number.type, number.value});
            }
            if (character == '+') {
                Token plus_sign;
                plus_sign.type = PLUS;
                plus_sign.value = "+";
                tokens.push_back({plus_sign.type, plus_sign.value});
            }
        }
        character = source_code.get();
    }
    return tokens;
}

std::string tokentype_to_string(int enum_type) {
    switch (enum_type) {
    case 0:
        return "NUMBER";
    case 1:
        return "PLUS";
    }
    return "UNCLASSIFIED_TOK";
}

int main() {
    std::string filename = "print_expr.nv";
    std::ifstream source_code(filename);

    std::vector<Token> tokens = tokenize(source_code);

    source_code.close();
    std::cout << "parsed " << filename << std::endl;

    for (const auto& token : tokens) {
        std::string token_type = tokentype_to_string(token.type);
        std::cout << "Token Type: (" << token_type << ") : Token Value: " << token.value << std::endl;
    }

    return 0;
}
