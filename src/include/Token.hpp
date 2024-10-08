#pragma once

#include <optional>
#include <string>

enum TType { EXIT, RETURN, INT, O_PAREN, C_PAREN, ENDL };

class Token {
private:
  const TType _type;
  const std::optional<std::string> _value;

public:
  inline explicit Token(TType t = TType::ENDL, std::optional<std::string> v = std::nullopt) : _type(t), _value(v){};

  inline std::string value() const {
    return _value.has_value() ? _value.value() : "";
  };
  inline bool is(const TType &type) const { return _type == type; };
  inline TType type() const { return _type; };
};