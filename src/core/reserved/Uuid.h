/*
 * Coral - A lightweight C++ component framework
 * See Copyright Notice in Coral.h
 */

#ifndef _CO_RESERVED_UUID_H_
#define _CO_RESERVED_UUID_H_

#include <co/Platform.h>
#include <string>

//! Main namespace of this library.
namespace co {

/*!
	\brief A 128-bit Universally Unique IDentifier (UUID).

	Using Universally Unique IDentifiers (UUID) is a standard way to uniquely identify entities in a
	distributed computing environment. A UUID is a 16-byte (128-bit) number generated by some algorithm
	that is meant to guarantee that the UUID will be unique in the distributed computing environment
	where it is used. The acronym GUID is often used instead, Globally Unique IDentifiers, but it refers
	to the same thing. The GUID is one variant of UUID. Multiple variants are in use. Each UUID contains
	a bit field that specifies which type (variant) of UUID.
	This class follow the DCE (Distributed Computing Environment) scheme defined by the Network Working
	Group UUID Specification (see the RFC at http://www.ietf.org/rfc/rfc4122.txt ).
 */
class CORAL_EXPORT Uuid
{
public:
	//! Well-defined UUID version values, according to the DCE standard.
	enum Version
	{
		VerUnknown	= -1,	//!< Version is unknown because the Uuid is null.
		Md5			= 3,	//!< Generated using MD5 hashing.
		Random		= 4,	//!< Generated using random numbers for all sections.
		Sha1		= 5		//!< Generated using SHA-1 hashing.
	};

public:
	/*!
		Returns a new UUID with version Uuid::Random, generated using the system's
		pseudo-random number generator.
		\see CryptoHash::createFromHash().
	 */
	static Uuid createRandom();

	//! Returns the immutable global 'null' Uuid (i.e. "00000000-0000-0000-0000000000000000").
	static const Uuid& null();

public:
	//! Creates a null UUID (i.e. "00000000-0000-0000-0000000000000000").
	Uuid();

	//! Copy constructor.
	Uuid( const Uuid &other );

	/*!
		Creates an UUID with the value specified by the DCE-compliant parameters: \a timeLow, \a timeMid,
		\a timeHiAndVersion, \a clockSeqHiAndReserved, \a clockSeqLow and \a node. Example:
		\code
		// {67C8770B-44F1-410A-AB9AF9B5446F13EE}
		Uuid MyInterface( 0x67c8770b, 0x44f1, 0x410a, 0xab, 0x9a, 0xf9, 0xb5, 0x44, 0x6f, 0x13, 0xee )
		\endcode
	 */
	Uuid( uint32 timeLow, uint16 timeMid, uint16 timeHiAndVersion, uint8 clockSeqHiAndReserved, uint8 clockSeqLow, uint8 node[6] );

	/*!
		Creates an Uuid from a string (by calling setString()).
		\see getString(), setString().
	 */
	Uuid( const std::string& str );

	//! Returns whether this is the null UUID (i.e. "00000000-0000-0000-0000000000000000").
	bool isNull() const;

	//! Returns the version field of the UUID, or Uuid::VerUnknown if this Uuid is null.
	int getVersion() const;

	//! Sets the contents of this UUID based on the given array of 16 bytes and the specified version.
	void set( uint8 bytes[], Version v );

	/*!
		Returns the string representation of this Uuid. UUIDs are formatted according to the
		pattern "xxxxxxxx-xxxx-xxxx-xxxxxxxxxxxxxxxx", where 'x' is an hexadecimal digit.
	 */
	void getString( std::string& str ) const;

	/*!
		Sets the contents of this Uuid based on a string formatted according to the pattern
		"{xxxxxxxx-xxxx-xxxx-xxxxxxxxxxxxxxxx}", where 'x' is an hexadecimal digit.
		The curly braces shown here are optional, but it is safe to include them.
		If the string is malformed, the Uuid will become null.
	 */
	void setString( const std::string& str );

	//! Makes this Uuid a null UUID. \sa isNull().
	void clear();

	//! Assignment operator. Copies all data from other Uuid to this Uuid.
	Uuid& operator=( const Uuid& other );

	//! Returns true if this Uuid and the other Uuid are identical; Otherwise returns false.
	inline bool operator==( const Uuid& other ) const
	{
		return other._data.dwords[0] == _data.dwords[0] &&
			   other._data.dwords[1] == _data.dwords[1] &&
			   other._data.dwords[2] == _data.dwords[2] &&
			   other._data.dwords[3] == _data.dwords[3];
	}
	
	//! Returns true if this Uuid and the other Uuid are NOT identical; Otherwise returns false.
	inline bool operator!=( const Uuid& other ) const
	{
		return !( *this == other );
	}

	//! Returns true if this Uuid is 'lesser than' another Uuid.
	inline bool operator<( const Uuid& other ) const
	{
		return _data.dwords[0] < other._data.dwords[0] ||
			( _data.dwords[0] == other._data.dwords[0] &&
				( _data.dwords[1] < other._data.dwords[1] ||
					( _data.dwords[1] == other._data.dwords[1] &&
						( _data.dwords[2] < other._data.dwords[2] ||
							( _data.dwords[2] == other._data.dwords[2] && _data.dwords[3] < other._data.dwords[3] )
						)
					)
				)
			);
	}

private:
	void setVersion( Version version );

private:
	union
	{
		uint32 dwords[4];
		uint8 bytes[16];
		struct
		{
			uint32 timeLow;
			uint16 timeMid;
			uint16 timeHiAndVersion;
			uint8 clockSeqHiAndReserved;
			uint8 clockSeqLow;
			uint8 node[6];
		} dce;
	} _data;
};

} // namespace co

CORAL_EXPORT std::ostream& operator<<( std::ostream& out, const co::Uuid& uuid );

#endif // _CO_RESERVED_UUID_H_
