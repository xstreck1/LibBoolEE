#include <stdexcept>
#include "LibBoolEE.hpp"
#include "LibBoolEE.h"

std::vector<std::string> LibBoolEE::singleParse(const std::string & formula, const char op) {
    int start_pos = -1;
    int parity_count = 0;
    std::vector<std::string> subexpressions;
    for (int i = 0; i < static_cast<int>(formula.size()); i++) {
        if (formula[i] == ')') {
            parity_count--;
        }
        else if (formula[i] == '(') {
            parity_count++;
            if (start_pos == -1) {
                start_pos = i;
            }
        }
        else if (parity_count == 0) {
            if (start_pos == -1) {
                if (belongsToName(formula[i]) || formula[i] == '!') {
                    start_pos = i;
                }
            }
            else if (!(belongsToName(formula[i]) || formula[i] == '!')) {
                if (op == formula[i]) {
                    subexpressions.push_back(formula.substr(start_pos, i - start_pos));
                    start_pos = i+1;
                }
                else if (formula[i] != '&' && formula[i] != '|') {
                    throw std::runtime_error("Unknown operator '" + std::string(1, formula[i]) + "' in the (sub)expression '" + formula + "'.");
                }
            }
        }
    }
    if (start_pos != -1) {
        subexpressions.push_back(formula.substr(start_pos, formula.size() - start_pos));
    }
    if (parity_count != 0) {
        throw std::runtime_error("Wrong parenthesis parity in the (sub)expression '" + formula + "'.");
    }
    return subexpressions;
}

bool LibBoolEE::resolve(const std::string &source, const Vals & valuation) {
    return resolveRec(removeWhitespaces(source), valuation);
}

bool LibBoolEE::resolveRec(const std::string &source, const Vals & valuation) {
    if (source.empty()) {
        throw std::runtime_error("An empty subexpression was encountered");
    }

    std::string formula = source;
    char current_op = '|';
    // Try to divide by |
    std::vector<std::string> subexpressions = singleParse(source, current_op);
    // No | on the top level
    if (subexpressions.size() == 1) {
        current_op = '&';
        subexpressions = singleParse(source, current_op);
    }

    // No valid name found
    if (subexpressions.size() == 0) {
        throw std::runtime_error("The subexpression " + source + " is not a valid formula.");
    }
    // No binary top level operator found
    else if (subexpressions.size() == 1) {
        if (source[0] == '!') {
            return !resolve(source.substr(1), valuation);
        }
        else if (source[0] == '(') {
            return resolve(source.substr(1, source.size() - 2), valuation);
        }
        else if (source == "1") {
            return true;
        }
        else if (source == "0") {
            return false;
        }
        else if (valuation.count(source) == 0) {
            throw std::runtime_error("Variable '" + source + "' not found in the interpretation.");
        }
        else {
            return valuation.at(source);
        }
    }
    else {
        if (current_op == '|') {
            bool result = false;
            for (std::vector<std::string>::iterator it = subexpressions.begin(); it != subexpressions.end(); it++) {
                result |= resolve(*it, valuation);
            }
            return result;
        }
        else { // The operator was set to &
            bool result = true;
            for (std::vector<std::string>::iterator it = subexpressions.begin(); it != subexpressions.end(); it++) {
                result &= resolve(*it, valuation);
            }
            return result;
        }
    }
}

std::string LibBoolEE::trim(const std::string &source) {
    static const std::string WHITESPACES = " \n\r\t\v\f";
    const size_t front = source.find_first_not_of(WHITESPACES);
    return source.substr(front, source.find_last_not_of(WHITESPACES) - front + 1);
}

bool LibBoolEE::belongsToName(const char ch) {
    return isalnum(ch) || ch == '_' || ch == '-';
}

std::string LibBoolEE::removeWhitespaces(const std::string &source) {
    std::string result;
    for (int i = 0; i < static_cast<int>(source.size()); i++) {
        if (!isspace(source.at(i))) {
            result += source.at(i);
        }
    }
    return result;
}

bool LibBoolEEResolve(const char * source, const LibBoolEEVal * const vals, const int len) {
    LibBoolEE::Vals new_vals;
    for (int i = 0; i < len; i++) {
        new_vals.insert(std::make_pair(vals[i].name,vals[i].value));
    }
    return LibBoolEE::resolve(source, new_vals);
}

