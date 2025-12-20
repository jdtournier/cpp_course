## Sample Marking Scheme

| | |
|:-:|:----|
|   | **Functionality** |
| 5 | Read Fragment data (3 marks only if not implemented in base class) |
| 2 | Find largest fragment and set as initial estimate |
| 5 | Compute overlap between current estimate and another fragment |
| 4 | Consider reverse direction of fragment when computing overlap |
| 5 | Merge current and incoming fragments correctly to produce updated estimate |
| 3 | Keep track of unmerged fragments |
| 3 | Iterate until no further fragments |
| 2 | Report length of final estimate on terminal |
| 3 | Save final estimate to file |
| | |
|   | **Program design/use of language features** |
| 8 | Classes (e.g. `Sequence`, `Fragment`) |
| 5 | Relationships (e.g. `Sequence` has-many `Fragment`s) | 
| 5 | Attributes (e.g. public/private, in appropriate class, etc.) |
| 8 | Use of language features (& no code duplication) |
| 5 | Use of existing functionality in the standard (STL) |
| 3 | Error handling using exceptions |
| | |
|   | **Written report** |
| 3 | Clarity/conciseness of writing |
| 9 | UML class diagram correct |
| 3 | Design and implementation correspond |
| | |
|   | **Readability** |
| 1 | Variable/function names |
| 2 | Comments (inc. help/usage data for functions) |
| 2 | Indentation |
