//
//  core.cpp
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

#include "core.h"
#include <sstream>
#include <string>
#include "curl_util.h"

namespace quote {
    namespace detail {
        namespace core {
            std::string getLatestQuotesCsv(const std::string &instruments, const std::string &quoteTypes) {
                std::stringstream url;
                url << "http://finance.yahoo.com/d/quotes.csv?s="
                    << instruments
                    << "&f="
                    << quoteTypes;
                return detail::curl_util::getUrlData(url.str());
            }
            
            std::string getHistoricalQuotesCsv(const std::string &instrument, unsigned startYear, unsigned startMonth, unsigned startDay, unsigned endYear, unsigned endMonth, unsigned endDay, const std::string &rangeType) {
                std::stringstream url;
                url << "http://ichart.yahoo.com/table.csv?s="
                    << instrument
                    << "&a="
                    << startMonth - 1
                    << "&b="
                    << startDay
                    << "&c="
                    << startYear
                    << "&d="
                    << endMonth - 1
                    << "&e="
                    << endDay
                    << "&f="
                    << endYear
                    << "&g="
                    << rangeType
                    << "&ignore=.csv";
                return detail::curl_util::getUrlData(url.str());
            }

        }
    }
}