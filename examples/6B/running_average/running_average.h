#include <array>

// A class to keep track of the last 10 values provided via the record()
// method, along with a method to get the corresponding running average.
// This work by holding the values in a fixed-size container, and cycling the
// index (position) of the next value in a ring buffer structure
// (https://en.wikipedia.org/wiki/Circular_buffer).
template <typename X, int N> class RunningAverage {
  public:
    void record (X val) {
      // record value and increment index:
      m_values[m_current++] = val;
      // if index out of bounds, cycle back to zero:
      if (m_current >= N)
        m_current = 0;
    }

    double get_average() const {
      double sum = 0.0;
      for (const auto& x : m_values)
        sum += x;
      return sum / N;
    }

  private:
    std::array<X,N> m_values = { }; // <- initialises values to zero
    int m_current = 0;  // <- the index of the next value to be recorded
};
