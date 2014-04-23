//
//  cvs_string.cpp
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

#include <iostream>
#include "quote.h"

int main(int argc, const char * argv[]) {
    try {
        std::cout << "downloading..." << std::endl;
        std::cout << quote::getLatestQuotesCsv("petr4.sa", {quote::QuoteType::symbol, quote::QuoteType::name, quote::QuoteType::lastTradePriceOnly, quote::QuoteType::lastTradeDate, quote::QuoteType::lastTradeTime, quote::QuoteType::open, quote::QuoteType::dayLow, quote::QuoteType::dayHigh, quote::QuoteType::dayRange, quote::QuoteType::dividendShare, quote::QuoteType::peRatio}) << std::endl;
        std::cout << quote::getLatestQuotesCsv("MSFT", {quote::QuoteType::symbol, quote::QuoteType::name, quote::QuoteType::lastTradePriceOnly, quote::QuoteType::lastTradeDate, quote::QuoteType::lastTradeTime, quote::QuoteType::open, quote::QuoteType::dayLow, quote::QuoteType::dayHigh, quote::QuoteType::dayRange, quote::QuoteType::dividendShare, quote::QuoteType::peRatio}) << std::endl;
        std::cout << quote::getHistoricalQuotesCsv("petr4.sa", 2010, 4, 1, 2014, 4, 21, quote::RangeType::dividendsOnly) << std::endl;
    } catch (const std::exception& exception) {
        std::cerr << "Error: " << exception.what() << std::endl;
        return 1;
    } catch (...) {
        std::cerr << "Error: unknown exception" << std::endl;
        return 1;
    }
    std::cout << "end of sample" << std::endl;
    return 0;
}
