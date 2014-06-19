//
//  conversion.cpp
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

#include "conversion.h"
#include <stdexcept>
#include "Exception.h"
#include "QuoteType.h"
#include "RangeType.h"

namespace quote {
    namespace detail {
        namespace conversion {
            std::string getString(RangeType rangeType) {
                switch (rangeType) {
                    case RangeType::daily:
                        return "d";
                    case RangeType::weekly:
                        return "w";
                    case RangeType::monthly:
                        return "m";
                    case RangeType::dividendsOnly:
                        return "v";
                }
                throw Exception(__FILE__, __LINE__, __func__, "missing RangeType conversion");
            }
            
            std::string getString(QuoteType quoteType) {
                switch (quoteType) {
                    case QuoteType::ask:
                        return "a";
                    case QuoteType::averageDailyVolume:
                        return "a2";
                    case QuoteType::askSize:
                        return "a5";
                    case QuoteType::bid:
                        return "b";
                    case QuoteType::askRealTime:
                        return "b2";
                    case QuoteType::bidRealTime:
                        return "b3";
                    case QuoteType::bookValue:
                        return "b4";
                    case QuoteType::bidSize:
                        return "b6";
                    case QuoteType::changeAndPercentChange:
                        return "c";
                    case QuoteType::change:
                        return "c1";
                    case QuoteType::commission:
                        return "c3";
                    case QuoteType::changeRealTime:
                        return "c6";
                    case QuoteType::afterHoursChangeRealTime:
                        return "c8";
                    case QuoteType::dividendShare:
                        return "d";
                    case QuoteType::lastTradeDate:
                        return "d1";
                    case QuoteType::tradeDate:
                        return "d2";
                    case QuoteType::earningsShare:
                        return "e";
                    case QuoteType::errorIndication:
                        return "e1";
                    case QuoteType::epsEstimateCurrentYear:
                        return "e7";
                    case QuoteType::epsEstimateNextYear:
                        return "e8";
                    case QuoteType::epsEstimateNextQuarter:
                        return "e9";
                    case QuoteType::floatShares:
                        return "f6";
                    case QuoteType::dayLow:
                        return "g";
                    case QuoteType::dayHigh:
                        return "h";
                    case QuoteType::_52WeekLow:
                        return "j";
                    case QuoteType::_52WeekHigh:
                        return "k";
                    case QuoteType::holdingsGainPercent:
                        return "g1";
                    case QuoteType::annualizedGain:
                        return "g3";
                    case QuoteType::holdingsGain:
                        return "g4";
                    case QuoteType::holdingsGainPercentRealTime:
                        return "g5";
                    case QuoteType::holdingsGainRealTime:
                        return "g6";
                    case QuoteType::moreInfo:
                        return "i";
                    case QuoteType::orderBookRealTime:
                        return "i5";
                    case QuoteType::marketCapitalization:
                        return "j1";
                    case QuoteType::marketCapRealTime:
                        return "j3";
                    case QuoteType::ebitda:
                        return "j4";
                    case QuoteType::changeFrom52WeekLow:
                        return "j5";
                    case QuoteType::percentChangeFrom52WeekLow:
                        return "j6";
                    case QuoteType::lastTradeRealTimeWithTime:
                        return "k1";
                    case QuoteType::changePercentRealTime:
                        return "k2";
                    case QuoteType::lastTradeSize:
                        return "k3";
                    case QuoteType::changeFrom52WeekHigh:
                        return "k4";
                    case QuoteType::percebtChangeFrom52WeekHigh:
                        return "k5";
                    case QuoteType::lastTradeWithTime:
                        return "l";
                    case QuoteType::lastTradePriceOnly:
                        return "l1";
                    case QuoteType::highLimit:
                        return "l2";
                    case QuoteType::lowLimit:
                        return "l3";
                    case QuoteType::dayRange:
                        return "m";
                    case QuoteType::dayRangeRealTime:
                        return "m2";
                    case QuoteType::_50DayMovingAverage:
                        return "m3";
                    case QuoteType::_200DayMovingAverage:
                        return "m4";
                    case QuoteType::changeFrom200DayMovingAverage:
                        return "m5";
                    case QuoteType::percentChangeFrom200DayMovingAverage:
                        return "m6";
                    case QuoteType::changeFrom50DayMovingAverage:
                        return "m7";
                    case QuoteType::percentChangeFrom50DayMovingAverage:
                        return "m8";
                    case QuoteType::name:
                        return "n";
                    case QuoteType::notes:
                        return "n4";
                    case QuoteType::open:
                        return "o";
                    case QuoteType::previousClose:
                        return "p";
                    case QuoteType::pricePaid:
                        return "p1";
                    case QuoteType::changeinPercent:
                        return "p2";
                    case QuoteType::priceSales:
                        return "p5";
                    case QuoteType::priceBook:
                        return "p6";
                    case QuoteType::exDividendDate:
                        return "q";
                    case QuoteType::peRatio:
                        return "r";
                    case QuoteType::dividendPayDate:
                        return "r1";
                    case QuoteType::peRatioRealTime:
                        return "r2";
                    case QuoteType::pegRatio:
                        return "r5";
                    case QuoteType::priceEpsEstimateCurrentYear:
                        return "r6";
                    case QuoteType::priceEpsEstimateNextYear:
                        return "r7";
                    case QuoteType::symbol:
                        return "s";
                    case QuoteType::sharesOwned:
                        return "s1";
                    case QuoteType::shortRatio:
                        return "s7";
                    case QuoteType::lastTradeTime:
                        return "t1";
                    case QuoteType::tradeLinks:
                        return "t6";
                    case QuoteType::tickerTrend:
                        return "t7";
                    case QuoteType::_1yrTargetPrice:
                        return "t8";
                    case QuoteType::volume:
                        return "v";
                    case QuoteType::holdingsValue:
                        return "v1";
                    case QuoteType::holdingsValueRealTime:
                        return "v7";
                    case QuoteType::_52WeekRange:
                        return "w";
                    case QuoteType::dayValueChange:
                        return "w1";
                    case QuoteType::dayValueChangeRealTime:
                        return "w4";
                    case QuoteType::stockExchange:
                        return "x";
                    case QuoteType::dividendYield:
                        return "y";
                }
                throw Exception(__FILE__, __LINE__, __func__, "missing RangeType conversion");
            }
        }
    }
}