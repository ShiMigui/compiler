#include "./include/utils.hpp"

#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <sstream>
#include <string>

namespace utils {
std::string read(const std::string &path) {
  std::stringstream buf;
  std::fstream in(path, std::ios::in);
  buf << in.rdbuf();
  return buf.str();
};
std::string format(const std::string &src) {
  std::string buf;
  bool lastWasSpace = false;
  for (char c : src) {
    if (c == ' ' || c == '\n' || c == '\t') {
      if (lastWasSpace)
        continue;
      lastWasSpace = true;
    } else
      lastWasSpace = false;
    buf.push_back(c);
  }

  return buf;
};
void verifyArguments(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "Invalid operation! Try: " << argv[0] << " <input>";
    exit(EXIT_FAILURE);
  }
};
std::string readAndFormat(const std::string &path) {
  return format(read(path));
};
void write(const std::string &path, const std::string &src) {
  std::fstream out(path, std::ios::out);
  out << src;
};
} // namespace utils