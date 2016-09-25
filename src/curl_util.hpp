//
//  curl_util.hpp
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

#ifndef quote_curl_util_hpp
#define quote_curl_util_hpp

#include <memory>
#include <string>
#include <curl/curl.h>
#include "exception/Exception.hpp"
#include "win_compatibility.hpp"

namespace quote {
    namespace detail {
        namespace curl_util {
            std::shared_ptr<CURL> createCurlHandle();
            
            template<typename T>
            void setOpt(CURL *handle, CURLoption option, T parameter);
            
            void perform(CURL *handle);
            
            size_t writeToStringCallBack(void *buffer, size_t size, size_t nmemb, void *string);
            
            std::string getUrlData(const std::string url);

            //--

            template<typename T>
            void setOpt(CURL *handle, CURLoption option, T parameter) {
                CURLcode code = curl_easy_setopt(handle, option, parameter);
                if (code != CURLE_OK) {
                    throw exception::LogicException(__FILE__, __LINE__, __func__, std::string("curl_easy_setopt error: ") + curl_easy_strerror(code));
                }
            }
        }
    }
}


#endif
