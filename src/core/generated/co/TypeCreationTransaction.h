/*
 * Coral - A lightweight C++ component framework
 * See Copyright Notice in Coral.h
 */

#ifndef _CO_TYPECREATIONTRANSACTION_H_
#define _CO_TYPECREATIONTRANSACTION_H_

#include <co/TypeTraits.h>
#include <co/ArrayRange.h>
#include <co/Interface.h>

// Forward Declarations:
namespace co {
	class TypeBuilder;
} // namespace co
// End Of Forward Declarations

// co.TypeCreationTransaction Mapping:
namespace co {

class TypeCreationTransaction : public co::Interface
{
public:
	virtual ~TypeCreationTransaction() {;}

	virtual co::ArrayRange<co::TypeBuilder* const> getTypeBuilders() = 0;

	virtual void commit() = 0;

	virtual void rollback() = 0;
};

} // namespace co

namespace co {
template<> struct kindOf<co::TypeCreationTransaction> : public kindOfBase<TK_INTERFACE> {};
template<> struct nameOf<co::TypeCreationTransaction> { static const char* get() { return "co.TypeCreationTransaction"; } };
template<> struct typeOf<co::TypeCreationTransaction> : public typeOfBase<co::TypeCreationTransaction, InterfaceType> {};
} // namespace co

#endif // _CO_TYPECREATIONTRANSACTION_H_
