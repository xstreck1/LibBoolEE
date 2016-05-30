Library for Evaluation of Boolean Expressions
=============================================

This is a tiny, C++, dependency-less library that evaluates boolean expressions in a text form.

Example:
--------
    #include "LibBoolEE.hpp"
    int main() {
        LibBoolEE::Vals vals = { { "A", true }, { "B", false } };
        return LibBoolEE::resolve("A|B&B", vals); // returns 1
    }
For further examples see test.cpp.

Compiling:
---------
It is sufficient to add `LibBoolEE.cpp` and `LibBoolEE.h` to your project.

Formula syntax:
---------------
* `tt` (true) and `ff` (false) are formulas representing true and false respectively,
* any variable is a formula,
* for `φ` formula is `!φ`   formula,
* for `φ`, `ψ` formulas are `(φ|ψ)`, `(φ&ψ)` formulas representing logical disjunction and conjunction respectively,
* nothing else is a formula.
* whitespaces are ignored

API:
----
    LibBoolEE::Val
    
is a shortcut for `std::pair<std::string, bool>` and represents a pair `(variable name, variable value)`, e.g. `(VarA, true)`.


    LibBoolEE::Vals
    
is a map of `LibBoolEE::Val`.

    bool LibBoolEE::resolve(const std::string & formula, const LibBoolEE::Vals & vals)
    
is a function that returns true if and only if the `formula` is true in the valuation given by vals. Every variable present in the formula must have the corresponding key in `vals`. 

Licence:
--------
The code is released under [GNU lGPLv3](http://www.gnu.org/licenses/lgpl-3.0.en.html).
