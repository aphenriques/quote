//
//  Exception.cpp
//  quote
//
//  Created by André Henriques on 19/06/14.
//  Copyright (c) 2014 André Henriques. All rights reserved.
//

#include "Exception.h"

namespace quote {
    Exception::Exception(const std::string &fileName, unsigned lineNumber, const std::string &functionName, const std::string &errorMessage) : std::runtime_error(errorMessage + " at " + fileName + ":" + std::to_string(lineNumber) + ":(" + functionName + ")") {}
}