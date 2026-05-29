// Student_info.cpp source file
#include "Student_info.h"

using std::istream;
using std::vector;

bool compare(const Student_info &x, const Student_info &y) {
  return x.name < y.name;
}

std::istream &read(std::istream &is, Student_info &s) {
  // Read and store the student's name, midterm, and final exam grades
  is >> s.name >> s.midterm >> s.final;

  read_hw(is, s.homework); // Read and store all the student's homework grades
  return is;
}

std::istream &read_hw(std::istream &in, std::vector<double> &hw) {
  // Read homework grades from an input stream into a vector<double>
  if (in) {
    // Get rid of previous contents
    hw.clear();

    // Read homework grades
    double x;
    while (in >> x) {
      hw.push_back(x);
    }

    // Clear the stream so that inpu will work for the next student
    in.clear();
  }

  return in;
}
