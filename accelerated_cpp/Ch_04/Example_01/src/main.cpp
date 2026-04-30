#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <stdexcept>
#include <string>
#include <vector>

// Specify which standard library names to use
using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::istream;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

// Compute the median of a vector<double>
double median(vector<double> vec) {
  typedef vector<double>::size_type vec_sz;

  vec_sz size = vec.size();
  if (size == 0) {
    throw domain_error("Median of an empty vector");
  }

  sort(vec.begin(), vec.end());
  vec_sz mid = size / 2;
  return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

// Compute a student's overall grade from the midterm, final exam,
// and homework grade
double grade(double midterm, double final, double homework) {
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// Compute a student's overall grade from the midterm, final exam,
// and vector of homework grades
double grade(double midterm, double final, const vector<double> &hw) {
  if (hw.size() == 0) {
    throw domain_error("Student has done no homework");
  }
  return grade(midterm, final, median(hw));
}

// Read homework grades from an input stream into a vector<double>
istream &read_hw(istream &in, vector<double> &hw) {
  if (in) {
    // Get rid of previous content
    hw.clear();

    // Read homework grades
    double x;
    while (in >> x) {
      hw.push_back(x);
    }

    // Clear the stream so that input will work for the next student
    in.clear();
  }
  return in;
}

int main() {
  // Ask for and read the student's name
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // Ask for and read the midterm and final grades
  cout << "Please enter your midterm and final exam grades: ";
  double midterm, final;
  cin >> midterm >> final;

  // Ask for the homework grades
  cout << "Enter all your homework grades followed by end-of-file: ";
  vector<double> homework;

  // Read the homework grades
  read_hw(cin, homework);

  // Compute and generate the final grade, if possible
  try {
    double final_grade = grade(midterm, final, homework);
    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << final_grade
         << setprecision(prec) << endl;
  } catch (domain_error) {
    cout << endl << " You must enter your grades.   ";
    return 1;
  }

  return 0;
}
