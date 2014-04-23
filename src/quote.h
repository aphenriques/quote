//
//  quote.h
//  quote
//
//  Copyright (C) 2013, 2014  André Pereira Henriques
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

#ifndef quote_quote_h
#define quote_quote_h

#include <initializer_list>
#include <string>
#include "conversion.h"
#include "core.h"
#include "QuoteType.h"
#include "RangeType.h"

namespace quote {
    std::string getLatestQuotesCsv(const std::string &instruments, std::initializer_list<QuoteType> quoteTypes);
    
    inline std::string getHistoricalQuotesCsv(const std::string &instrument, unsigned startYear, unsigned startMonth, unsigned startDay, unsigned endYear, unsigned endMonth, unsigned endDay, RangeType rangeType);
    
    //--
    
    inline std::string getHistoricalQuotesCsv(const std::string &instrument, unsigned startYear, unsigned startMonth, unsigned startDay, unsigned endYear, unsigned endMonth, unsigned endDay, const RangeType rangeType) {
        return detail::core::getHistoricalQuotesCsv(instrument, startYear, startMonth, startDay, endYear, endMonth, endDay, detail::conversion::getString(rangeType));
    }
}

#endif
