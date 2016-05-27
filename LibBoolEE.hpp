#pragma once

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// @brief Class able to resolve any logical function in propositional logic.
///
/// This is a static helper class able of resolving any preposition logic formula.
/// Formula construction:
///   -# \f$tt\f$ (true) and \f$ff\f$ (false) are formulas representing true and false respectively,
///	-# any variable is a formula,
///   -# for \f$\varphi\f$ formula is \f$!\varphi\f$ formula,
///   -# for \f$\psi, \varphi\f$ formulas are \f$(\psi|\varphi)\f$, \f$(\psi\&\varphi)\f$ formulas representing logical disjunction and conjunction respectively,
///   -# nothing else is a formula.
///
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <map>
#include <string>
#include <vector>
#include <utility>

#include "shared_export_def.h"

class SHARED_EXPORT LibBoolEE {
public:
    typedef std::map<std::string, bool> Vals; ///< Valuation of atomic propositions
    typedef std::pair<std::string, bool> Val; ///< A single proposition valuation

    // @return	true iff the formula is true under the valuation (where the valuation are pairs (variable,value))
    static bool resolve(const std::string & source, const Vals & valuation);

private:
    static std::vector<std::string> singleParse(const std::string & formula, const char op);

    // @return	true iff ch is possibly part of a valid name
    static bool belongsToName(const char ch);

    // @return	true iff the formula is true under the valuation (where the valuation are pairs (variable,value))---used internally
    static bool resolveRec(const std::string & source, const Vals & valuation);


    // @return	new string made from the source by removing the leading and trailing white spaces
    static std::string trim(const std::string & source);

    // @return  new string made from the source by removing whitespaces
    static std::string removeWhitespaces(const std::string & source);
};
