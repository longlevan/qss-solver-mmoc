/*****************************************************************************

 This file is part of QSS Solver.

 QSS Solver is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 QSS Solver is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with QSS Solver.  If not, see <http://www.gnu.org/licenses/>.

 ******************************************************************************/

#ifndef MMO_MODEL_CHECKER_H_
#define MMO_MODEL_CHECKER_H_

#include <string>

#include "../ast/ast_types.h"
#include "../util/ast_util.h"
#include "../util/util_types.h"

/**
 *
 */
class AST_MicroModelica_: public AST_Visitor_
{
  public:
    /**
     *
     * @param name
     */
    AST_MicroModelica_(string name);
    /**
     *
     */
    ~AST_MicroModelica_();
    /**
     *
     * @param x
     */
    void
    visit(AST_Class x);
    /**
     *
     * @param x
     */
    void
    leave(AST_Class x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Composition x);
    /**
     *
     * @param x
     */
    void
    leave(AST_Composition x);
    /**
     *
     * @param x
     */
    void
    visit(AST_CompositionElement x);
    /**
     *
     * @param x
     */
    void
    leave(AST_CompositionElement x);
    /**
     *
     * @param x
     */
    void
    visit(AST_CompositionEqsAlgs x);
    /**
     *
     * @param x
     */
    void
    leave(AST_CompositionEqsAlgs x);
    /**
     *
     * @param
     */
    void
    visit(AST_External_Function_Call);
    /**
     *
     * @param x
     */
    void
    visit(AST_Element x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Modification x);
    /**
     *
     * @param x
     */
    void
    leave(AST_Modification x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Comment x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Equation x);
    /**
     *
     * @param x
     */
    void
    visit(AST_ForIndex x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Equation_Else x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Expression x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Argument x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Statement x);
    /**
     *
     * @param x
     */
    void
    leave(AST_Statement x);
    /**
     *
     * @param x
     */
    void
    visit(AST_Statement_Else x);
    /**
     *
     * @param x
     */
    void
    visit(AST_StoredDefinition x);
    /**
     *
     * @param x
     */
    void
    leave(AST_StoredDefinition x);
    /**
     *
     * @param x
     * @return
     */
    int
    apply(AST_Node x);
    private:
    void
    _checkIndex(AST_Expression exp);
    bool
    _whenStatement(AST_Expression cond);
    bool
    _lValue(AST_Expression left);
    string *_className;
    string *_fatherName;
    string *_childName;
    bool _classModification;
    bool _elseWhen;
    bool _inWhen;
    AST_ClassPrefix _childPrefix;
    AST_ClassPrefix _classPrefix;
    AST_ClassPrefix _fatherPrefix;
};
/**
 *
 * @param name
 * @return
 */
AST_MicroModelica
newAST_MicroModelica(string name);
/**
 *
 * @param m
 */
void
deleteAST_MicroModelica(AST_MicroModelica m);

#endif  /* MMO_MODEL_CHECKER_H_ */
