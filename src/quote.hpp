//
//  quote.hpp
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

#ifndef quote_quote_hpp
#define quote_quote_hpp

#include <initializer_list>
#include <string>
#include <vector>
#include "core.hpp"
#include "MultipleInheritancePack.hpp"
#include "QuoteType.hpp"
#include "QuoteTypeWrapper.hpp"
#include "RangeType.hpp"

//! \file quote.h
//! \brief This header contains all `quote` functionality
//!
//! This is the only file that should be included to use `quote`

//! \namespace quote
//! \brief Namespace where all quote functionality resides
//!
//! \warning \{
//! `quote` is thread safe provided the following:
//! Manual curl initialization (curl_global_init) must be performed before using quote functions in a multi-threaded context, otherwise it can be ignored. Check <http://curl.haxx.se/libcurl/c/curl_easy_init.html>
//! \}
namespace quote {
    // For the folowwing functions: an exception is thrown if the required data can not be obtained. (FIXME doxygen documentation format)
    
    //! \brief Get quotes in csv string
    //!
    //! Throws a std::runtime_error if retrieval fails (it is not uncommon)
    //! \param instruments instrument string (e.g "MSFT" for Microsoft quotes)
    //! \param quoteTypes quotes list. \sa quote::QuoteType
    //! \return quotes in csv format
    inline std::string getLatestQuotesCsv(const std::string &instruments, std::vector<QuoteType> quoteTypes);
    
    
    //! \copydoc getLatestQuotesCsv(const std::string &instruments, std::vector<QuoteType> quoteTypes)
    inline std::string getLatestQuotesCsv(const std::string &instruments, std::initializer_list<QuoteType> quoteTypes);
    
    //! \brief Get quotes in csv string
    //!
    //! Throws a std::runtime_error if retrieval fails (it is not uncommon)
    //! \param instruments instrument string (e.g "MSFT" for Microsoft quotes)
    //! \tparam quoteTypes quotes list. \sa quote::QuoteType
    //! \return quotes in csv format
    template<QuoteType ...quoteTypes>
    inline std::string getLatestQuotesCsv(const std::string &instruments);
    
    //! \brief Get historical quotes
    //!
    //! Throws a std::runtime_error if retrieval fails (it is not uncommon)
    //! \param instruments instrument string (e.g "MSFT" for Microsoft quotes)
    //! \param rangeType daily, weekly, monthly or dividends only historical quotes \sa quote::RangeType
    //! \return historical quotes in csv format. Includes csv header
    inline std::string getHistoricalQuotesCsv(const std::string &instrument, unsigned startYear, unsigned startMonth, unsigned startDay, unsigned endYear, unsigned endMonth, unsigned endDay, RangeType rangeType);
    
    //--
    
    inline std::string getLatestQuotesCsv(const std::string &instruments, std::vector<QuoteType> quoteTypes) {
        return detail::core::getLatestQuotesCsv(instruments, quoteTypes);
    }
    
    inline std::string getLatestQuotesCsv(const std::string &instruments, std::initializer_list<QuoteType> quoteTypes) {
        return detail::core::getLatestQuotesCsv(instruments, quoteTypes);
    }
    
    template<QuoteType ...quoteTypes>
    inline std::string getLatestQuotesCsv(const std::string &instruments) {
        static_assert(sizeof...(quoteTypes) != 0, "at least one quoteType should be provided");
        // check if quote types arguments are unique
        detail::MultipleInheritancePack<detail::QuoteTypeWrapper<quoteTypes>...>();
        return detail::core::getLatestQuotesCsv<std::initializer_list<QuoteType>>(instruments, {quoteTypes...});
    }
    
    inline std::string getHistoricalQuotesCsv(const std::string &instrument, unsigned startYear, unsigned startMonth, unsigned startDay, unsigned endYear, unsigned endMonth, unsigned endDay, const RangeType rangeType) {
        return detail::core::getHistoricalQuotesCsv(instrument, startYear, startMonth, startDay, endYear, endMonth, endDay, detail::conversion::getString(rangeType));
    }
}

#endif
