#include "include/utils.hpp"
#include <cstdlib>
#include <string>
int main(int argc, char *argv[]) {
  {
    utils::verifyArguments(argc, argv);
    const std::string &src = utils::readAndFormat(argv[1]);
  }
  /*
  [OK] read file
  [OK] format text
  tokenize
  parse
  generate
  write
  nasm
  ld
  */

  return EXIT_SUCCESS;
}