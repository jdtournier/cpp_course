# Patient database report generator

Design may involve (remember that there are many other possibilities!):
- a `Database` class to interact with the database
- a `Record` class to hold the data for a single patient
- a `RecordSet` class to hold all the records read from the database, before and after patient selection
- a `SelectionCriterion` class to represent a single selection criterion
- a `Selector` class to select patients based on user criteria
- a `ReportGenerator` class to produce the final report

The `RecordSet` class will be composed of `Record` objects.

The `Selector` class will be composed of `SelectionCriterion` objects.

The `Database`, `Selector`, and `ReportGenerator` classes will all have a dependency relationship with the `RecordSet` class (and therefore also the `Record` class): 
- `Database`: produces a `RecordSet` by reading the database.
- `Selector`: takes a `RecordSet` as input to produce another `RecordSet` matching the selection criteria.
- `ReportGenerator`: takes a `RecordSet` as input to produce the report.

All remaining interactions can be managed within the program itself.


## Specific attributes & methods:

- `Record`:
  - private attributes: 
    - patient name
    - patient DOB
    - patient ID
    - ...
  - public methods:
    - read-only getter methods to query the attributes

- `RecordSet`:
  - private attributes: 
    - vector of `Record` objects
  - public methods:
    - getter method for number of records
    - getter & setter for individual record
    - methods to add/remove specific records

- `Database`:
  - private attributes: 
    - file name or handle, or URL to database
  - public methods:
    - getter to read all records, either one at a time (returns a single `Record`) or in batch (returns `RecordSet`) 

- `Selector`:
  - private attributes: 
    - vector of `SelectionCriterion`
  - public methods:
    - const method to check whether an individual record matches the selection criteria
    - const method using the method above to produce a smaller `RecordSet` from an input `RecordSet`

- `ReportGenerator`:
  - private attributes: 
    - internal parameters regarding formatting (to be determined)
  - public methods:
    - a method to produce the report given a `RecordSet` and the target filename for the report

