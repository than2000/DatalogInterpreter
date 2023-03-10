#ifndef PROJECT1_T2K_SCANNER_H
#define PROJECT1_T2K_SCANNER_H

#include <cctype>
#include <queue>
#include <vector>
#include <fstream>
#include "Token.h"

class Scanner
{
public:
    Scanner(const std::string &_input) : input(_input), reachedEOF(false), currentLine(1){};
    Scanner(std::ifstream &ifs);
    void scan(std::vector<Token> &tokens); // Scan all tokens into the given vector
    Token scanToken();
    bool hasNext();

private:
    std::string input;
    bool reachedEOF;
    int currentLine;

    MaybeToken scanForWordTokens(); // ID, SCHEMES, FACTS, RULES, and QUERIES tokens

    MaybeToken scanForCharTokens();  // COMMA, PERIOD, Q_MARK, LEFT_PAREN, RIGHT_PAREN, ADD, and MULTIPLY tokens
    MaybeToken scanForColonTokens(); // COLON and COLON_DASH tokens

    MaybeToken scanForEOFToken();     // END_OF_FILE token
    MaybeToken scanForStringToken();  // STRING token
    MaybeToken scanForCommentToken(); // COMMENT token
    MaybeToken scanBlockComment();

    void removeWhitespace();

};

#endif
