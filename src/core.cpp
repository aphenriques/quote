//
//  core.cpp
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

#include "core.hpp"
#include <sstream>
#include <string>
#include "exception/Exception.hpp"
#include "curl_util.hpp"
#include "string_util.hpp"
#include "win_compatibility.hpp"

namespace quote {
    namespace detail {
        namespace core {
            std::string getLatestQuotesCsv(const std::string &instruments, const std::string &quoteTypes) {
                if (instruments.empty() == false) {
                    if (quoteTypes.empty() == false) {
                        std::stringstream url;
                        url << "http://finance.yahoo.com/d/quotes.csv?s="
                            << instruments
                            << "&f="
                            << quoteTypes;
                        std::string latestQuotesCsv = detail::curl_util::getUrlData(url.str());
                        detail::string_util::trim(latestQuotesCsv);
                        if (latestQuotesCsv.empty() || latestQuotesCsv.at(0) != '<') { // leading '<' indicates server error
                            return std::move(latestQuotesCsv);
                        } else {
                            throw exception::RuntimeException(__FILE__, __LINE__, __func__, "server (Yahoo! Finance) error");
                        }
                    } else {
                        throw exception::LogicException(__FILE__, __LINE__, __func__, "empty quoteTypes");
                    }
                } else {
                    throw exception::LogicException(__FILE__, __LINE__, __func__, "empty instruments parameter");
                }
            }
            
            std::string getHistoricalQuotesCsv(const std::string &instrument, unsigned startYear, unsigned startMonth, unsigned startDay, unsigned endYear, unsigned endMonth, unsigned endDay, const std::string &rangeType) {
                if (instrument.empty() == false) {
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
                    std::string historicalQuotesCsv = detail::curl_util::getUrlData(url.str());
                    detail::string_util::trim(historicalQuotesCsv);
                    if (historicalQuotesCsv.empty() || historicalQuotesCsv.at(0) != '<') { // leading '<' indicates server error
                        return std::move(historicalQuotesCsv);
                    } else {
                        throw exception::RuntimeException(__FILE__, __LINE__, __func__, "server (Yahoo! Finance) error");
                    }
                } else {
                    throw exception::LogicException(__FILE__, __LINE__, __func__, "empty instrument parameter");
                }
            }
        }
    }
}
