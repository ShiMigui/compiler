#pragma once

#include "Picker.hpp"
#include "Token.hpp"

#include <cctype>
#include <stdexcept>
#include <string>
#include <vector>

class Tokenizer {
private:
  std::vector<Token> _tokens{};
  Picker<char> _chars;
  std::string buf;

  inline void addBuf(int (*pred)(int)) {
    do {
      buf.push_back(_chars.data());
    } while (_chars.next().has_value() && pred(_chars.data()));
    _chars.back();
  };

  inline void addToken(TType t = TType::ENDL,
                       std::optional<std::string> v = std::nullopt) {
    _tokens.push_back(Token(t, v));
  };

  inline void verifyByStmts() {
    if (buf == "return")
      addToken(TType::RETURN);
    else
      throw std::runtime_error("Tokenizer: Statement not found!");

    buf.clear();
  };

public:
  inline explicit Tokenizer(const std::string &src) try
      : _chars(std::vector<char>(src.begin(), src.end())) {
  } catch (const std::runtime_error &e) {
    throw std::runtime_error(std::string("Tokenizer: ") + e.what());
  }

  inline std::vector<Token> tokenize() {
    do {
      char c = _chars.data();

      if (std::isalpha(c)) {
        addBuf(std::isalnum);
        verifyByStmts();
      } else if (std::isdigit(c)) {
        addBuf(std::isdigit);
        addToken(TType::INT, buf);
        buf.clear();
      } else if (c == '(')
        addToken(TType::O_PAREN);
      else if (c == ')')
        addToken(TType::C_PAREN);
      else if (c == ';')
        addToken();
      else if (c == ' ') {
      } else
        throw std::runtime_error("Tokenizer: Unknown: " + std::string(1, c));
    } while (_chars.next().has_value());

    return _tokens;
  };
};