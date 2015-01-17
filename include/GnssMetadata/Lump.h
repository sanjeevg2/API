/**
 * File: Lump.h
 * Author: M.B. Mathews
 *  
 * Copyright(c) 2014 Institute of Navigation
 * http://www.ion.org
 *  
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef LUMP_H_H
#define LUMP_H_H

#include "BaseTypes.h"
#include "Stream.h"

namespace GnssMetadata
{
	/**
	 * Class defines a collection of sample words organized into a contiguous block. This is known as a Lump in the 
	 * currente draft specfication.
	 */
	class Lump: public AttributedObject
	{
	public:
		/**
		 * Default constructor for the lump.
		 */
		Lump( )
		{
			
		}

		Lump( const Lump& rhs) : _streamlist(rhs._streamlist)
		{
			
		}

		const Lump& operator=( const Lump& rhs)
		{
			if( &rhs == this)
				return *this;
			AttributedObject::operator =(rhs);
			_streamlist = rhs._streamlist;
			return *this;
		}

		const GnssMetadata::StreamList& Streams( ) const
		{
			return _streamlist;
		}
		GnssMetadata::StreamList& Streams( )
		{
			return _streamlist;
		}

		/**
		 * Returns a string representation of the object.
		 */
		virtual String toString( const String & sFormat = DefaultFormat );

	private:
		GnssMetadata::StreamList _streamlist;		
	};

	typedef std::list<Lump> LumpList;	
	
}


#endif
