//
//  string_util.hpp
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

#ifndef quote_string_util_hpp
#define quote_string_util_hpp

#include <string>

namespace quote {
    namespace detail {
        namespace string_util {
            // trim functions from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring/217605#217605
            
            // trim from start
            std::string & trimLeft(std::string &s);
            
            // trim from end
            std::string & trimRight(std::string &s);
            
            // trim from both ends
            std::string & trim(std::string &s);
        }
    }
}

#endif
