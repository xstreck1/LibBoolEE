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
