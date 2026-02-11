# EEG processing and display software

Design may involve (remember that there are many other possibilities!):
- a `Signal` class to represent one electrode recording, or the difference between recordings
- a `SignalSet` class to represent a collection of raw or difference signals
- a `EEG` class to interact with the hardware and record the raw signal from each electrode
- a `DenoiseAlgorithm` class to represent our denoising filter
- a `MontageScheme` class to represent how each montage is to be assembled (which electrode pairs to subtract, and in what order to show them, etc).
- a `Montage` class to process the signals and produce a new set of signals according to a given montage scheme
- a `Display` class to display the information to the user

The `SignalSet` class will be composed of `Signal` objects.

The `Montage` class will be composed of a `MontageScheme` class, and be dependent on the `SignalSet` class (and hence also the `Signal` class)

The `DenoiseAlgorithm` will depend on the `Signal` class (or `SignalSet` if operating on all raw recordings concurrently). 

The `Display` will depend on the `SignalSet` class (and hence also the `Signal` class), and the `MontageScheme` class.

The `EEG` class will depend on the `SignalSet` class (and hence also the `Signal` class).

All remaining interactions can be managed within the program itself.

## Specific attributes & methods:

- `Signal`:
  - private attributes: 
    - vector of values
  - public methods:
    - getter for the number of samples
    - getter & setter methods for each time sample

- `SignalSet`:
  - private attributes: 
    - vector of `Signal` objects
    - sample rate
  - public methods:
    - getter method for number of records and sample rate
    - getter & setter for individual signal
    - methods to add/remove specific signals

- `EEG`:
  - private attributes: 
    - Hardware-specific information to identify recording device
  - public methods:
    - getter to record all signals and return a `SignalSet`

- `DenoiseAlgorithm`:
  - private attributes: 
    - parameters of algorithm (if any)
  - public methods:
    - const method to perform denoising, taking a `Signal` as input and producing an output `Signal` 

- `MontageScheme`:
  - private attributes: 
    - internal representation including list of pairs of electrodes to compute in montage, in the required order, etc.
  - public methods:
    - const method to compute the signals in the montage, taking a `SignalSet` as input and producing an output `SignalSet`

- `Display`:
  - private attributes: 
    - information about rendering context (window size, etc)
  - public methods:
    - display method to show the montage, taking as input the `SignalSet` produced by the `Montage`, along with the matching `MontageScheme`.

