//
//  conversion.hpp
//  quote
//
//  Copyright (C) 2013, 2014, 2016  André Pereira Henriques
//  aphenriques (at) outlook (dot) com
//
//  This file is part of quote.
//
//  quote is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  quote is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with quote.  If not, see <http://www.gnu.org/licenses/>.
//

#ifndef quote_conversion_hpp
#define quote_conversion_hpp

#include <string>
#include "QuoteType.hpp"
#include "RangeType.hpp"

namespace quote {
    namespace detail {
        namespace conversion {
            std::string getString(RangeType rangeType);
            std::string getString(QuoteType quoteType);

        }
    }
}

#endif
