//
//  Exception.h
//  quote
//
//  Created by André Henriques on 19/06/14.
//  Copyright (c) 2014 André Henriques. All rights reserved.
//

#ifndef quote_Exception_h
#define quote_Exception_h

#include <stdexcept>
#include <string>

namespace quote {
    class Exception : public std::runtime_error {
    public:
        Exception(const std::string &fileName, unsigned lineNumber, const std::string &functionName, const std::string &errorMessage);
    };
}

#endif
