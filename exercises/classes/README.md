# Exercises: classes

## Exercise 1

Write a C++ class to contain the following information about towns:

- the name (a string)
- the population (an integer)
- a Boolean value which indicates whether the town has an airport or not

Make the three data members `private`. Include a constructor that initialises
the data members to sensible values.

Add three new *mutator* member functions that assign values to the three data
members. Also add a *facilitator* member function to print out all the
information about a town. The member functions should all be publicly
accessible. Write a `main()` function which declares two town objects and
assigns the following values to them:

| Name   | Population | Airport |
| ------ | ---------- | ------- |
| London | 8,174,000  | `true`  |
| Bath   | 83,992     | `false` |

After assigning values to the two objects, the driver should print the details of both to the screen.

<br>


## Exercise 2

In electronics, Ohm's law states that the current through a conductor between
two points is directly proportional to the voltage difference between the two
points. The mathematical equation for Ohm's law is:

$$
I = \frac{V}{R},
$$

where $R$ is the resistance, $I$ the current and $V$ the voltage.

Write a C++ class that represents a resistor. It should have the following data
members and member functions:

- a `private` data member for the resistance, $R$
- a `public` *mutator* member function to set the value of $R$
- a `public` member function to calculate the current $I$ given a voltage $V$ as an argument
- a `public` member function to calculate the voltage $V$ given a current $I$ as an argument
- a `public` member function to calculate the power dissipation $W$ given a
  current $I$ as an argument, using the formula $W = I \cdot V$, where $V$ is
  calculated using the previous member function


Write a driver program to test your class.

<br>


## Exercise 3

Write a C++ class called `Sample`. The class should have a `private` data
member that stores an array of floating point numbers. Since the number of
values can vary there should also be a `private` data member indicating how
many values there currently are. There should be a default constructor that
initialises the class to an empty sample, and a *mutator* member function
to initialise the array and the sample size. You should also write the
following:

a `public` member function to display the sample
a `public` member function to compute and return the mean $\bar{x}$ of the sample
a `public` member function to compute and return the standard deviation of the
sample, using the equation:

$$
s=\sqrt{\frac{1}{n-1}\sum_{i=1}^{n}(x_i-\bar{x})^2}
$$

where $x_i$ are the sample values, $\bar{x}$ is the sample mean and $n$ is the
sample size

Write a driver to test your class using the following data sample:

```
18.44 14.18 19.79 15.73 15.36 16.17 13.91 15.35
```

This represents scores, out of 20, for a group of Alzheimer's patients who took
a cognitive impairment test.


<br>


## Exercise 4

In cardiology, a number of useful clinical parameters can be computed from
knowledge of the left ventricle's volume at end-diastole and end-systole
(referred to as EDV and ESV respectively, typically measured in mL). This
information can be measured using imaging data such as echocardiography. For
example, the following parameters can be useful in understanding cardiac
mechanics and detecting abnormalities:

- **Stroke Volume** (SV) is the volume of blood ejected by the ventricle in a
  single contraction: $SV = EDV - ESV$ (in mL)
- **Cardiac Output** (CO) is the amount of blood pumped by the ventricle in
  unit time: $CO = \frac{SV \times HR}{1000}$ (in L/min, HR = Heart Rate)
- **Ejection Fraction** (EF) is the fraction of EDV that is ejected out of the
  ventricle during each contraction: $EF = \frac{SV}{EDV}$\%

Write a C++ class called `Heart` that has private data members for the EDV, ESV
and HR values. There should be a single *mutator* member function to assign
values for all of these. Also write `public` member functions to compute and
return the SV, CO and EF based on these input values. Write a driver program to
test your class using the following values collected from a sample of patients
considered to be at risk of heart failure:

| Patient | HR (bpm) | EDV (mL) | ESV (mL) |
| ------- | -------- | -------- | -------- |
| 1 | 95  | 180 | 157 |
| 2 | 74  | 196 | 105 |
| 3 | 86  | 163 | 69 |
| 4 | 103 | 228 | 50 |

The driver should define an array of `Heart` instances, assign the appropriate
input values to them and use an iteration statement to display the computed
parameters for all patients.

According to the American Heart Association, an EF above 75% may indicate a
heart condition such as hypertrophic cardiomyopathy, whereas an EF of below
40% may be evidence of heart failure or cardiomyopathy.  Therefore, your
driver should detect and report those patients whose EF is below 40% or above
75%.

<br>


## Exercise 5

Write a C++ class for storing 2×2 matrices. The class should store the matrix
coefficients in a `private` data member, and include the following member
functions:

- a single constructor that takes four `float` values and uses them to
  initialise the matrix coefficients (if arguments are not provided they should
  default to the identity matrix)
- a `public` member function to display the matrix
- a `public` member function to perform matrix multiplication: the function
  should take a matrix as its single argument, multiply it by the current
  instance, and return another matrix as its result (the current instance
  should not be modified)

Write a driver program to test your new class.

<br>


## Exercise 6

You are provided with code for classes called `Vector` and `Point` to store
information about vectors, along with a simple driver program.  Modify this
'skeleton' code to add the following `public` member functions:

- `float mag()` - returns the magnitude of the vector when expressed in polar coordinates
- `float angle()` - returns the angle of the vector in degrees when expressed in polar coordinates

The magnitude of the vector can be found using Pythagoras' theorem. The angle
can be calculated using basic trigonometry and the `<cmath>` standard library.
You should make appropriate use of the `const` keyword when writing your new
member functions. You may also need access to mathematical constants such as
$\pi$, which are defined in [the `<numbers>`
header](https://www.geeksforgeeks.org/cpp-20-numbers-header/), within the `std::numbers`
namespace.

Expand the driver program to test the new functions.

<br>


## Exercise 7

Write a C++ class for storing complex numbers. The class should have two
`private` data members representing the real and imaginary parts of
the complex number. There should be a single constructor that takes values for
the real and imaginary parts of the number and assigns them to the data
members. If arguments are not provided to the constructor, both the real and
imaginary parts should default to zero. You should also implement the following
member functions:

- *Inspectors* and *mutators* for the two data members
- a `public` member function to display the complex number
- a `public` member function to perform complex addition: the function should
  take a complex number as its single argument, add it to the current instance,
  and return another complex number as its result (the current instance should
  not be modified)
- a `public` member function to perform complex multiplication: the function
  should take a complex number as its single argument, multiply it by the
  current instance, and return another complex number as its result (the current
  instance should not be modified)

Write a driver to test your class.

<br>


## Exercise 8

In Exercise 6, we introduced a class called `Point`, which stores the `x` and
`y` coordinates of 2-D points. 

Write a new class called `Triangle`. A triangle consists of 3 points, so you
will need to make use of *composition* to define data members of the `Point`
class. The `Triangle` class should have one default constructor and another
constructor that initialises the three points of the triangle. It should also
have a member function that calculates the area of the triangle according to
the formula

$$
\mbox{Area} = \sqrt{s(s-a)(s-b)(s-c)}
$$

where `a`, `b` and `c` are the lengths of the three sides, and `s` is half of
the sum of the three sides.

Write a driver that inputs three points from the user, and prints out the area
of the triangle they form.

<br>


## Exercise 9

In Exercise 3 you wrote a C++ class to store information about a data sample
and to compute some simple statistics from the sample (i.e. mean and standard
deviation). Expand this class to include an extra `public` member function to
*sort* the data sample so that its values are in ascending order in the array.

A simple algorithm for sorting is called *bubble sort*. Some pseudocode for the
bubble sort algorithm on a list `x` of length `n` is:

```
repeat:
  loop over all elements:
    if current element and next element are out of order:
      swap the values of the current and next elements
  if no swaps have been made:
    stop
```

Test your new member function using the same data sample introduced in Exercise
3 (i.e. the Alzheimer's patients' cognitive impairment scores).

