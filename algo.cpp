#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc < 2) {
    cout << "Filename not provided" << endl;
    return 1;
  }

  int cur, res, count = 0;
  ifstream file;
  file.open(argv[1]);
  if (file >> cur) {
    res = cur;
  } else {
    cout << "Can't read from file" << endl;
    file.close();
    return 2;
  }

  while (file >> cur) {
    if (cur == res)
      count++;
    else if (count)
      count--;
    else
      res = cur;
  }

  /* If our input is not correct, that is there's no element that
     repeats more than N/2, the answer will be incorrect as well. */
  cout << "The answer is: " << res << endl;

  file.close();
  return 0;
}
