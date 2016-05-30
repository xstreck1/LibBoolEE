/******************************************************************************
Created by Adam Streck, 2016, adam.streck@gmail.com

This file is part of the LibBoolEE library.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU lesser General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.
This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.  See the GNU General Public License for more details.
You should have received a copy of the GNU General Public License along with
this program.  If not, see <http://www.gnu.org/licenses/>.
******************************************************************************/

#include "LibBoolEE.h"

#define CPP_TEST(expr, vals) \
    if(!LibBoolEE::resolve(expr,vals)){ \
        throw std::runtime_error(std::string(expr) + " does not yield the expected value in Cpp test.\n"); \
    };

int main() {
    // Test the library via Cpp interface
    LibBoolEE::Vals vals;
    vals.insert(std::make_pair("A", true));
    vals.insert(std::make_pair("B", false));
    CPP_TEST("A", vals);
    CPP_TEST("A|B", vals);
    CPP_TEST("!(A&B)", vals);
    CPP_TEST("(!B&A)", vals);
    CPP_TEST("(A&B&B&A)|A|B", vals);
    CPP_TEST(("!(\n(A&B ) \t | (B&A)|!(A|B))"), vals); // Whitespace
    CPP_TEST("A|B&B", vals); // operator precedence
    CPP_TEST("!((A|B)&B)", vals); // operator precedence - cont'd
    CPP_TEST("!(!B&!A|A&B)", vals); // negation binding
}
