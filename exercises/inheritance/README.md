# Exercises: inheritance

## Exercise 1

 You will be provided with 'skeleton' code in the KEATS system for an inheritance hierarchy for part of a medical disease database. However, currently there are no data members or member functions in the hierarchy.

Download and modify the code to implement the following:

- A `string` description of the disease. All diseases should have a description. Also add *mutator* and *inspector* member functions to set/access the description.

- A data member to indicate the type of lung disease. Lung disease can affect either *bronchi*, *alveoli* or *interstitium*, so the data type of this member should reflect this. All lung diseases should have this information stored. Also added *mutator* and *inspector* member functions to set/access this data member.

Skeleton code for this exercise is provided here: [Exercise 1 files](1_DiseaseSkeleton/)

<br>


## Exercise 2

Design and implement simple classes and inheritance hierarchy for medical images.

All medical images should store a `body_part` member indicating the imaged area, and should be an enumeration type that can take any of the following values: `Head`, `Lung`, `Heart` or `Liver`. A driver programme should be able to set and retrieve this info. 

A *pure virtual* `display()` *function* should defined, therefore, all derived classes must provide an implementation of this function to avoid being an *abstract base class*. You should write such implementations but just leave them empty apart from a `cout` statement to print a message to the screen that the program has entered the function.

Your desing should deal with `Ionising` and `Nonionising` modalities differently - `Ionising` (`X-ray` & `CT`) modalities must store the information of a `tipical_dose`.

Also write a driver program that creates instances of each of the `X-ray`, `CT`, `MRI` and `US` classes, assigns the anatomy of the image and calls the `display()` function.

<br>


## Exercise 3

Design and implement simple classes and an inheritance hierarchy for the domain of *numbers*. *Real*, *rational* and *complex* numbers are all types of number.

All numbers can be negated but precisely what negation means is dependent on the type of number. Similarly, it should be possible to display all numbers but exactly how they are displayed will vary.

It should not be possible to create an instance of a *number*, only *real*, *rational* or *complex* numbers. A *real* number is represented by a single floating point value. A complex number comprises two *real* numbers, one for the real (i.e. non-imaginary) and one for the imaginary part. You should be able to compute the *conjugate* of a complex number (i.e. just negate the imaginary part). A *rational* number consists of two integers, one for the numerator and one for the denominator.

The negation operation should be implemented in each of the concrete classes as follows:

- For *real* numbers, simply negate the floating point value
- For *rational* numbers, negate the numerator
- For *complex* numbers, negate both the real and imaginary parts

<br>


## Exercise 4

In physics, the energy E in Joules of a body of mass m kilograms can be either:

- *Potential energy*: PE = mgh where g is the acceleration due to gravity in ms⁻² and h is the height of the body in metres; or
- *Kinetic energy*: KE = ½mv² where v is the velocity of the body in ms⁻¹

For both types of energy the mass of the body must be known. For potential energy the height and gravity must also be known, whereas for kinetic energy the velocity must also be known.

For any type of energy it is necessary to compute the energy of the body given the appropriate parameters, i.e. mass/gravity/height for potential energy and mass/velocity for kinetic energy.

Design and implement simple classes and an inheritance hierarchy to represent these concepts. Your implementation should include both default constructors and constructors that take the appropriate parameters for each type of energy. Also write a driver program to test your classes. The driver should first read the mass of a body from the keyboard. Next, it should read the height and report the potential energy assuming a gravity of 9.8ms⁻². After this, it should read a velocity and report the corresponding kinetic energy.

<br>


## Exercise 5

Design and implement simple classes and an inheritance hierarchy for an information system for managing admission to an Accident and Emergency (A & E) department in a hospital.

A `Patient` should have member variables for their name (first name and last name). A `print()` function for the `Patient` class should display this name. For urgent patients (derive a class from `Patient`) it is also necessary to store the reason for urgent attention being required. The `print()` function for urgent patients should display the reason, but it should also display the patient's name. 

Write a driver to test your code.

<br>


## Exercise 6

In particle physics, there are three basic particles that comprise atoms: *neutrons*, *electrons* and *protons*. All particles have a mass and a charge (both floating point numbers). Electrons also have an energy level (another floating point number). The atomic nucleus contains a number of neutrons and protons (the exception being hydrogen which only has a single proton). An atom consists of a nucleus and a number of electrons.

Design simple classes and an inheritance hierarchy that capture the relationships between particles, neutrons, electrons, protons, nuclei and atoms, then implement your design. 

An atom should be capable of computing its atomic number (i.e. the number of protons in its nucleus) and its total mass. You can assume that no atom will have more than 118 of either protons, neutrons or electrons.

Write a driver program to test your classes by creating a Helium atom (which has 2 protons, 2 neutrons and 2 electrons) and computing its mass and atomic number.

You will need the following additional information:

- Neutrons have mass = 1.00866492 u (unified atomic mass units), charge = 0 *e*
- Electrons have mass = 0.00054875 u, charge = -1 *e*
- Protons have mass = 1.00727647 u, charge = +1 *e*

where *e* = 1.602 × 10⁻¹⁹ Coulombs and 1 unified atomic mass unit u = 1.660538782 × 10⁻²⁷ kilograms.

<br>


## Exercise 7

Design and implement simple classes and an inheritance hierarchy to represent the domain of electrical devices. All electrical devices should have a voltage at which they operate. Scanners are electrical devices which should also store a resolution in pixels per millimetre (an integer). Printers are electrical devices and should also store the number of paper trays that they have (another integer). Finally, photocopiers are both scanners and printers and in addition should store whether or not they have an autofeed feature.

Write a driver to test your classes.

<br>


## Exercise 8

Design and implement simple classes and an inheritance hierarchy to represent information about simultaneous linear equations of the form:

2x + y = 7
3x - y = 8

In this problem domain, all equations should have an *order* (an integer). It should be possible to display all equations, although the exact display format should depend on the type of equation. A linear equation should be a type of equation for which the order is always 1. Linear equations should have three floating point coefficients (e.g. 2, 1 and 7 for the first equation shown above). Simultaneous equations should consist of 2 linear equations.

It should be possible to display such a set of simultaneous linear equations in the form shown above, and also to solve the equations, i.e. display the values of x and y which satisfy the equations.

Write a driver program to test your classes using the pair of simultaneous equations shown above.

<br>


## Exercise 9

In the lecture we introduced classes to represent information about shapes. You will be provided with the source code for these classes and a simple driver program through the KEATS system. Now suppose that a team of developers wish to use these classes in a computer-aided design package. The following requirements exist:

- All shapes should have a flag indicating whether the shape is currently visible or not
- It should be possible to store information about 2-D or 3-D shapes. All 2-D shapes should be able store and compute their area and perimeter (as in the `Shape` class in the existing code), whereas all 3-D shapes should be able store and compute their volume and surface area
- As well and squares and triangles, the software should be able to represent spheres (an example of a 3-D object). The equations for computing the volume and surface area of sphere are: V = (4/3)πr², A = 4πr²

Modify the shapes code to implement the requirements and update the driver program to test your code.

Skeleton code for this exercise is provided here: [Exercise 9 files](9_Geometry/)
