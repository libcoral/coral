/** \file
 *  This C header file was generated by $ANTLR version 3.3 Nov 30, 2010 12:45:30
 *
 *     -  From the grammar source file : /Users/tbastos/Projects/coral/src/core/csl/CSL.g
 *     -                            On : 2011-01-06 00:14:26
 *     -                for the parser : CSLParserParser *
 * Editing it, at least manually, is not wise. 
 *
 * C language generator and runtime by Jim Idle, jimi|hereisanat|idle|dotgoeshere|ws.
 *
 *
 * The parser CSLParser has the callable functions (rules) shown below,
 * which will invoke the code for the associated rule in the source grammar
 * assuming that the input stream is pointing to a token/text stream that could begin
 * this rule.
 * 
 * For instance if you call the first (topmost) rule in a parser grammar, you will
 * get the results of a full parse, but calling a rule half way through the grammar will
 * allow you to pass part of a full token stream to the parser, such as for syntax checking
 * in editors and so on.
 *
 * The parser entry points are called indirectly (by function pointer to function) via
 * a parser context typedef pCSLParser, which is returned from a call to CSLParserNew().
 *
 * The methods in pCSLParser are  as follows:
 *
 *  - void      pCSLParser->csl_file(pCSLParser)
 *  - void      pCSLParser->specification(pCSLParser)
 *  - void      pCSLParser->import_clause(pCSLParser)
 *  - void      pCSLParser->exception_specification(pCSLParser)
 *  - void      pCSLParser->enum_specification(pCSLParser)
 *  - void      pCSLParser->struct_specification(pCSLParser)
 *  - void      pCSLParser->native_class_specification(pCSLParser)
 *  - void      pCSLParser->identifier_list(pCSLParser)
 *  - void      pCSLParser->interface_specification(pCSLParser)
 *  - void      pCSLParser->component_specification(pCSLParser)
 *  - CSLParser_qualified_identifier_return      pCSLParser->qualified_identifier(pCSLParser)
 *  - CSLParser_cpp_type_return      pCSLParser->cpp_type(pCSLParser)
 *  - void      pCSLParser->native_class_member(pCSLParser)
 *  - CSLParser_struct_member_return      pCSLParser->struct_member(pCSLParser)
 *  - void      pCSLParser->interface_member(pCSLParser)
 *  - void      pCSLParser->inheritance_declaration(pCSLParser)
 *  - CSLParser_attribute_declaration_return      pCSLParser->attribute_declaration(pCSLParser)
 *  - CSLParser_method_declaration_return      pCSLParser->method_declaration(pCSLParser)
 *  - void      pCSLParser->parameter_declaration_list(pCSLParser)
 *  - void      pCSLParser->parameter_declaration(pCSLParser)
 *  - void      pCSLParser->exception_list(pCSLParser)
 *  - CSLParser_component_member_return      pCSLParser->component_member(pCSLParser)
 *  - void      pCSLParser->method_type_spec(pCSLParser)
 *  - void      pCSLParser->type_declaration(pCSLParser)
 *  - void      pCSLParser->pair_of_braces(pCSLParser)
 *  - CSLParser_param_io_return      pCSLParser->param_io(pCSLParser)
 *  - bool      pCSLParser->interface_role(pCSLParser)
 *  - void      pCSLParser->comment(pCSLParser)
 *
 * The return type for any particular rule is of course determined by the source
 * grammar file.
 */
// [The "BSD licence"]
// Copyright (c) 2005-2009 Jim Idle, Temporal Wave LLC
// http://www.temporal-wave.com
// http://www.linkedin.com/in/jimidle
//
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. The name of the author may not be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
// OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
// IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
// NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
// THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#ifndef	_CSLParser_H
#define _CSLParser_H
/* =============================================================================
 * Standard antlr3 C runtime definitions
 */
#include    <antlr3.h>

/* End of standard antlr 3 runtime definitions
 * =============================================================================
 */

	#define pANTLR3_PARSER	csl::Parser* parser; pANTLR3_PARSER
	namespace csl {
		class Parser;
	}

 
#ifdef __cplusplus
extern "C" {
#endif

// Forward declare the context typedef so that we can use it before it is
// properly defined. Delegators and delegates (from import statements) are
// interdependent and their context structures contain pointers to each other
// C only allows such things to be declared if you pre-declare the typedef.
//
typedef struct CSLParser_Ctx_struct CSLParser, * pCSLParser;



#ifdef	ANTLR3_WINDOWS
// Disable: Unreferenced parameter,							- Rules with parameters that are not used
//          constant conditional,							- ANTLR realizes that a prediction is always true (synpred usually)
//          initialized but unused variable					- tree rewrite variables declared but not needed
//          Unreferenced local variable						- lexer rule declares but does not always use _type
//          potentially unitialized variable used			- retval always returned from a rule 
//			unreferenced local function has been removed	- susually getTokenNames or freeScope, they can go without warnigns
//
// These are only really displayed at warning level /W4 but that is the code ideal I am aiming at
// and the codegen must generate some of these warnings by necessity, apart from 4100, which is
// usually generated when a parser rule is given a parameter that it does not use. Mostly though
// this is a matter of orthogonality hence I disable that one.
//
#pragma warning( disable : 4100 )
#pragma warning( disable : 4101 )
#pragma warning( disable : 4127 )
#pragma warning( disable : 4189 )
#pragma warning( disable : 4505 )
#pragma warning( disable : 4701 )
#endif
typedef struct CSLParser_qualified_identifier_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;   
}
    CSLParser_qualified_identifier_return;

typedef struct CSLParser_cpp_type_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;   
}
    CSLParser_cpp_type_return;

typedef struct CSLParser_struct_member_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;   
}
    CSLParser_struct_member_return;

typedef struct CSLParser_attribute_declaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;   
}
    CSLParser_attribute_declaration_return;

typedef struct CSLParser_method_declaration_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;   
}
    CSLParser_method_declaration_return;

typedef struct CSLParser_component_member_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;   
}
    CSLParser_component_member_return;

typedef struct CSLParser_param_io_return_struct
{
    /** Generic return elements for ANTLR3 rules that are not in tree parsers or returning trees
     */
    pANTLR3_COMMON_TOKEN    start;
    pANTLR3_COMMON_TOKEN    stop;   
    bool isIn;
    bool isOut;
}
    CSLParser_param_io_return;



/** Context tracking structure for CSLParser
 */
struct CSLParser_Ctx_struct
{
    /** Built in ANTLR3 context tracker contains all the generic elements
     *  required for context tracking.
     */
    pANTLR3_PARSER   pParser;


     void (*csl_file)	(struct CSLParser_Ctx_struct * ctx);
     void (*specification)	(struct CSLParser_Ctx_struct * ctx);
     void (*import_clause)	(struct CSLParser_Ctx_struct * ctx);
     void (*exception_specification)	(struct CSLParser_Ctx_struct * ctx);
     void (*enum_specification)	(struct CSLParser_Ctx_struct * ctx);
     void (*struct_specification)	(struct CSLParser_Ctx_struct * ctx);
     void (*native_class_specification)	(struct CSLParser_Ctx_struct * ctx);
     void (*identifier_list)	(struct CSLParser_Ctx_struct * ctx);
     void (*interface_specification)	(struct CSLParser_Ctx_struct * ctx);
     void (*component_specification)	(struct CSLParser_Ctx_struct * ctx);
     CSLParser_qualified_identifier_return (*qualified_identifier)	(struct CSLParser_Ctx_struct * ctx);
     CSLParser_cpp_type_return (*cpp_type)	(struct CSLParser_Ctx_struct * ctx);
     void (*native_class_member)	(struct CSLParser_Ctx_struct * ctx);
     CSLParser_struct_member_return (*struct_member)	(struct CSLParser_Ctx_struct * ctx);
     void (*interface_member)	(struct CSLParser_Ctx_struct * ctx);
     void (*inheritance_declaration)	(struct CSLParser_Ctx_struct * ctx);
     CSLParser_attribute_declaration_return (*attribute_declaration)	(struct CSLParser_Ctx_struct * ctx);
     CSLParser_method_declaration_return (*method_declaration)	(struct CSLParser_Ctx_struct * ctx);
     void (*parameter_declaration_list)	(struct CSLParser_Ctx_struct * ctx);
     void (*parameter_declaration)	(struct CSLParser_Ctx_struct * ctx);
     void (*exception_list)	(struct CSLParser_Ctx_struct * ctx);
     CSLParser_component_member_return (*component_member)	(struct CSLParser_Ctx_struct * ctx);
     void (*method_type_spec)	(struct CSLParser_Ctx_struct * ctx);
     void (*type_declaration)	(struct CSLParser_Ctx_struct * ctx);
     void (*pair_of_braces)	(struct CSLParser_Ctx_struct * ctx);
     CSLParser_param_io_return (*param_io)	(struct CSLParser_Ctx_struct * ctx);
     bool (*interface_role)	(struct CSLParser_Ctx_struct * ctx);
     void (*comment)	(struct CSLParser_Ctx_struct * ctx);
    // Delegated rules

    const char * (*getGrammarFileName)();
    void            (*reset)  (struct CSLParser_Ctx_struct * ctx);
    void	    (*free)   (struct CSLParser_Ctx_struct * ctx);
        
};

// Function protoypes for the constructor functions that external translation units
// such as delegators and delegates may wish to call.
//
ANTLR3_API pCSLParser CSLParserNew         (pANTLR3_COMMON_TOKEN_STREAM instream);
ANTLR3_API pCSLParser CSLParserNewSSD      (pANTLR3_COMMON_TOKEN_STREAM instream, pANTLR3_RECOGNIZER_SHARED_STATE state);

/** Symbolic definitions of all the tokens that the parser will work with.
 * \{
 *
 * Antlr will define EOF, but we can't use that as it it is too common in
 * in C header files and that would be confusing. There is no way to filter this out at the moment
 * so we just undef it here for now. That isn't the value we get back from C recognizers
 * anyway. We are looking for ANTLR3_TOKEN_EOF.
 */
#ifdef	EOF
#undef	EOF
#endif
#ifdef	Tokens
#undef	Tokens
#endif 
#define EOF      -1
#define IMPORT      4
#define SEMICOLON      5
#define EXCEPTION_TOKEN      6
#define ID      7
#define ENUM      8
#define OPEN_BLOCK      9
#define CLOSE_BLOCK      10
#define STRUCT      11
#define NATIVE      12
#define CLASS      13
#define OPEN_PAREN      14
#define CPP_TAG      15
#define CLOSE_PAREN      16
#define COMMA      17
#define INTERFACE      18
#define COMPONENT      19
#define DOT      20
#define CPP_SCOPE      21
#define CPP_BLOCK      22
#define COLON      23
#define READONLY      24
#define ATTRIBUTE      25
#define RAISES      26
#define TOK_VOID      27
#define BASIC_TYPE      28
#define OPEN_BRACE      29
#define CLOSE_BRACE      30
#define TOK_IN      31
#define TOK_OUT      32
#define TOK_INOUT      33
#define PROVIDES      34
#define RECEIVES      35
#define COMMENT      36
#define WS      37
#ifdef	EOF
#undef	EOF
#define	EOF	ANTLR3_TOKEN_EOF
#endif

#ifndef TOKENSOURCE
#define TOKENSOURCE(lxr) lxr->pLexer->rec->state->tokSource
#endif

/* End of token definitions for CSLParser
 * =============================================================================
 */
/** \} */

#ifdef __cplusplus
}
#endif

#endif

/* END - Note:Keep extra line feed to satisfy UNIX systems */
