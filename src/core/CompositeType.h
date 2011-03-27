/*
 * Coral - A lightweight C++ component framework
 * See Copyright Notice in Coral.h
 */

#ifndef _CO_COMPOSITETYPE_H_
#define _CO_COMPOSITETYPE_H_

#include "Type.h"
#include <co/IMember.h>
#include <co/IClassType.h>
#include <co/IRecordType.h>
#include <co/ICompositeType.h>
#include <co/RefVector.h>

namespace co {

/*!
	Re-usable implementation of ICompositeType, IRecordType and IClassType
 */
class CompositeTypeImpl : public TypeImpl
{
public:
	CompositeTypeImpl();

	virtual ~CompositeTypeImpl();

	//! Appends the given members range to the members list. After calling this
	//! method the members list must be re-sorted using the sortMembers() method.
	void addMembers( Range<IMember* const> members );

	//! Sorts the members list by (type, name) and updates _firstMethodPos.
	void sortMembers( ICompositeType* owner );

	// CompundType methods:
	Range<IMember* const> getMembers();
	IMember* getMember( const std::string& name );

	// IRecordType methods:
	Range<IField* const> getFields();

	// IClassType methods:
	Range<IMethod* const> getMethods();

protected:
	/*!
		Template method for retrieving the array of ancestors of this CompountType.
		Used by the getMembers() method. By default an empty array is returned.
	 */
	virtual Range<ICompositeType* const> getCompositeTypeAncestors();

private:
	typedef RefVector<IMember> MembersVector;
	MembersVector _members;	// mixed container: attributes first, then methods.
	size_t _firstMethodPos;	// dividing point: position of the first method in _members.
};

#define DELEGATE_co_ICompositeType( DELEGATE ) \
	virtual Range<IMember* const> getMembers() { return DELEGATE getMembers(); } \
	virtual IMember* getMember( const std::string& name ) { return DELEGATE getMember( name ); }

#define DELEGATE_co_IRecordType( DELEGATE ) \
	virtual Range<IField* const> getFields() { return DELEGATE getFields(); }

#define DELEGATE_co_IClassType( DELEGATE ) \
	virtual Range<IMethod* const> getMethods() { return DELEGATE getMethods(); }

} // namespace co

#endif
