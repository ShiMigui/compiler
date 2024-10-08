#pragma once

#include "Token.hpp"
#include <string>
namespace utils {
std::string read(const std::string &path);
std::string format(const std::string &src);
void verifyArguments(int argc, char *argv[]);
std::string readAndFormat(const std::string &path);
void write(const std::string &path, const std::string &src);
std::string literalTokenType(TType t);
}