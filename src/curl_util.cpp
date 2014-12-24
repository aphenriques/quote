//
//  curl_util.cpp
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

#include "curl_util.h"
#include <memory>
#include <string>
#include <utility>
#include <curl/curl.h>
#include "Exception.h"

namespace quote {
    namespace detail {
        namespace curl_util {
            std::shared_ptr<CURL> createCurlHandle() {
                std::shared_ptr<CURL> curlHandle(curl_easy_init(), curl_easy_cleanup);
                if (curlHandle.get() == nullptr) {
                    throw Exception(__FILE__, __LINE__, __func__, "curl_easy_init() failure");
                }
                return curlHandle;
            };

            void perform(CURL *handle) {
                CURLcode code = curl_easy_perform(handle);
                if (code != CURLE_OK) {
                    throw Exception(__FILE__, __LINE__, __func__, std::string("curl_easy_perform error: ") + curl_easy_strerror(code));
                }
            }
            
            size_t writeToStringCallBack(void *buffer, size_t size, size_t nmemb, void *string) {
                const size_t sizeInBytes = size*nmemb;
                static_cast<std::string *>(string)->append(static_cast<const char * >(buffer), sizeInBytes);
                return sizeInBytes;
            }
            
            std::string getUrlData(const std::string url) {
                std::shared_ptr<CURL> curlHandle = detail::curl_util::createCurlHandle();
                detail::curl_util::setOpt(curlHandle.get(), CURLOPT_URL, url.c_str());
                detail::curl_util::setOpt(curlHandle.get(), CURLOPT_FOLLOWLOCATION, 1L);
                std::string data;
                detail::curl_util::setOpt(curlHandle.get(), CURLOPT_NOBODY, 0L);
                detail::curl_util::setOpt(curlHandle.get(), CURLOPT_WRITEDATA, &data);
                detail::curl_util::setOpt(curlHandle.get(), CURLOPT_WRITEFUNCTION, detail::curl_util::writeToStringCallBack);
                detail::curl_util::perform(curlHandle.get());
                return std::move(data);
            }
        }
    }
}
