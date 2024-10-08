#include "include/Token.hpp"
#include "include/Tokenizer.hpp"
#include "include/utils.hpp"

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
int main(int argc, char *argv[]) {
  {
    try {
      utils::verifyArguments(argc, argv);
      const std::string &src = utils::readAndFormat(argv[1]);

      Tokenizer tokenizer(src);
      std::vector<Token> vec = tokenizer.tokenize();
    } catch (std::runtime_error &e) {
      std::cerr << e.what() << std::endl;
      exit(EXIT_FAILURE);
    }
  }
  /*
  [OK] read file
  [OK] format text
  [OK] tokenize
  parse
  generate
  write
  nasm
  ld
  */

  return EXIT_SUCCESS;
}