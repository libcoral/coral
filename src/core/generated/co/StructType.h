/*******************************************************************************
** C++ mapping generated for type 'co.StructType'
**
** Created: Thu Jun 10 20:53:30 2010
**      by: Coral Compiler version 0.1.0
**
** WARNING! All changes made in this file will be lost when recompiling!
********************************************************************************/

#ifndef _CO_STRUCTTYPE_H_
#define _CO_STRUCTTYPE_H_

#include <co/TypeTraits.h>
#include <co/AttributeContainer.h>
#include <co/CompoundType.h>

// co.StructType Mapping:
namespace co {

class StructType : public co::CompoundType, public co::AttributeContainer
{
public:
	virtual ~StructType() {;}

	CORAL_DISAMBIGUATE_CO_INTERFACE( co::CompoundType );
};

} // namespace co

namespace co {
template<> struct kindOf<co::StructType> : public kindOfBase<TK_INTERFACE> {};
template<> struct nameOf<co::StructType> { static const char* get() { return "co.StructType"; } };
template<> struct typeOf<co::StructType> : public typeOfBase<co::StructType, InterfaceType> {};
namespace traits {
	template<> struct hasAmbiguousBase<co::StructType, co::Interface> : public TrueType {};
	template<> struct disambiguateBase<co::StructType, co::Interface> { typedef co::CompoundType Super; };
} // namespace traits
} // namespace co

#endif // _CO_STRUCTTYPE_H_
