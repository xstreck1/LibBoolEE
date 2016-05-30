Library for Evaluation of Boolean Expressions
=============================================

This is a tiny, C/C++, multiplatform, and dependency-less library that evaluates boolean expressions in a text form.

Example:
--------
    #include "LibBoolEE.hpp"
    int main() {
        LibBoolEE::Vals vals = { { "A", true }, { "B", false } };
        return LibBoolEE::resolve("A|B&B", vals); // returns 1
    }
