/*
 * Coral - Lightweight C++ Component Framework
 * See Copyright Notice in Coral.h
 */

#ifndef _CO_REFPTR_H_
#define _CO_REFPTR_H_

#include <ostream>

namespace co {

/*!
	\brief A smart-pointer that provides reference counting for Coral services.
	\tparam T a service type (co::IService).
 */
template<class T>
class RefPtr
{
public:
	//! Default constructor.
	inline RefPtr() : _ptr( 0 )
	{;}

	//! Constructor taking a raw pointer.
	inline RefPtr( T* p ) : _ptr( p )
	{
		tryRetain();
	}

	//! Copy constructor.
	inline RefPtr( const RefPtr& other ) : _ptr( other._ptr )
	{
		tryRetain();
	}

	//! Destructor.
	inline ~RefPtr()
	{
		tryRelease();
		#ifndef CORAL_NDEBUG
			_ptr = 0;
		#endif
	}

	//! Assignment operator.
	inline RefPtr& operator = ( const RefPtr& other )
	{
		if( _ptr != other._ptr )
		{
			T* old = _ptr;
			_ptr = other._ptr;
			tryRetain();

			// always release last
			if( old )
				old->serviceRelease();
		}
		return *this;
	}

	//! Pointer assignment operator.
	inline RefPtr& operator = ( T* p )
	{
		if( _ptr == p )
			return *this;

		T* old = _ptr;
		_ptr = p;
		tryRetain();

		// always release last
		if( old )
			old->serviceRelease();

		return *this;
	}

	//! Comparison operator for RefPtr's.
	//@{
	inline bool operator == ( const RefPtr& other ) const { return _ptr == other._ptr; }
	inline bool operator != ( const RefPtr& other ) const { return _ptr != other._ptr; }
	inline bool operator < (const RefPtr& other ) const { return _ptr < other._ptr; }
	inline bool operator > (const RefPtr& other) const { return _ptr > other._ptr; }
	//@}

	//! Comparison operator for pointers.
	//@{
	inline bool operator == ( const T* p ) const { return _ptr == p; }
	inline bool operator != ( const T* p ) const { return _ptr != p; }
	inline bool operator < ( const T* p ) const { return _ptr < p; }
	inline bool operator > ( const T* p ) const { return _ptr > p; }
	//@}

	//! Dereference operator.
	inline T& operator * () const { return *_ptr; }

	//! Member access operator.
	inline T* operator -> () const { return _ptr; }

	//! Invalid (i.e. null) internal pointer test operator.
	inline bool operator!() const { return _ptr == 0; }

	//! Returns whether the internal pointer is valid (i.e. not null).
	inline bool isValid() const { return _ptr != 0; }

	//! Returns the internal pointer stored in this smart pointer.
	inline T* get() const { return _ptr; }

	/*!
		Efficiently swaps the internal pointers of two co::RefPtr's.
		This saves two serviceRetain() and two serviceRelease() calls.
	 */
	inline void swap( RefPtr& other )
	{
		T* temp = _ptr;
		_ptr = other._ptr;
		other._ptr = temp;
	}

	//! ADL-based overload for swap().
	friend inline void swap( RefPtr& a, RefPtr& b ) { a.swap( b ); }

private:
	inline void tryRetain()
	{
		if( _ptr )
			_ptr->serviceRetain();
	}

	inline void tryRelease()
	{
		if( _ptr )
			_ptr->serviceRelease();
	}

private:
	T* _ptr;
};

} // namespace co

#ifndef DOXYGEN
//! Output stream operator overload.
template<typename T>
inline std::ostream& operator << ( std::ostream& stream, const co::RefPtr<T>& rp )
{
	return stream << "co::RefPtr( " << rp.get() << " )";
}
#endif

#endif // _CO_REFPTR_H_
