#include <fstream>
#include <iostream>

/*
 * Algorithm description.
 *
 * We linearly scan the file and store our current candidate for the answer.
 * The 1st number in the file is our 1st candidate. If we encounter a number
 * that's equal to our current candidate when scanning the file, we increment
 * our candidate "frequency" counter, and decrement it otherwise. If the counter
 * hits 0, we change the candidate. In the end, out current candidate is the
 * answer.
 *
 */

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "Filename not provided" << std::endl;
    return 1;
  }

  int cur, res;
  size_t count = 0;
  std::ifstream file(argv[1]);
  if (file >> cur) {
    res = cur;
  } else {
    std::cout << "Can't read from file" << std::endl;
    file.close();
    return 2;
  }

  while (file >> cur) {
    if (cur == res) {
      count++;
    } else if (count) {
      count--;
    } else {
      res = cur;
    }
  }

  /* If our input is not correct, that is there's no element that
     repeats more than N/2, the answer will be incorrect as well. */
  std::cout << "The answer is: " << res << std::endl;

  file.close();
  return 0;
}
