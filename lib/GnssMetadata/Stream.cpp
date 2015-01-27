/**
 * File: Stream.cpp
 * Author: M.B. Mathews
 *  
 * Copyright(c) 2014 Institute of Navigation
 * http://www.ion.org
 *  
 * This Metadata API is free software; you can redistribute it and/or
 * modify it under the terms of the Lesser GNU General Public License
 * as published by the Free Software Foundation; either version 3
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * Lesser GNU General Public License for more details.
 *
 * You should have received a copy of the Lesser GNU General Public License
 * along with Metadata API.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <GnssMetadata/Stream.h>
using namespace GnssMetadata;


/**
 * Returns a string representation of the object.
 */
String Stream::toString( const String & sFormat )
{
	return AttributedObject::toString(sFormat);
}

/**
 * Virtual function traverses collections of attributed objects looking for object with the
 * specified id.  Returns the count of objects found.
 */
size_t Stream::FindObject( 
	SearchItem::List& listResults, const String& sid, 
	const AttributedObject& rparent, bool bExcludeReference, int nDepth ) const
{
	//Check this object first.
	size_t count = AttributedObject::FindObject( listResults,
		sid, rparent, bExcludeReference, nDepth);

	count += SearchList<Band>( listResults, _bandlist, sid,rparent, bExcludeReference, nDepth);
	return count;
}