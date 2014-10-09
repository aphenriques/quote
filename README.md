# quote

`quote` is a C++ library to get Yahoo! Finance data. It gets historical data and the latest quotes strings in csv format.

# Source

`quote`'s Git repository is available on GitHub, which can be browsed at:

    http://github.com/aphenriques/quote

and cloned with:

    git clone git://github.com/aphenriques/quote.git

# Example

```cpp
#include <iostream>
#include "quote.h"

int main(int argc, const char * argv[]) {
     // all Yahoo! Finance quote types are implemented (this is just a sample)
    std::string petr4Quotes = quote::getLatestQuotesCsv("petr4.sa", {quote::QuoteType::symbol,
                                                                     quote::QuoteType::name,
                                                                     quote::QuoteType::lastTradePriceOnly,
                                                                     quote::QuoteType::lastTradeDate,
                                                                     quote::QuoteType::lastTradeTime});
    std::cout << petr4Quotes << std::endl;
    // quote ranges can be daily, weekly, monthly, or dividends only
    std::string petr4HistoricalPrices = quote::getHistoricalQuotesCsv("petr4.sa",
                                                                      2014, 4, 2,
                                                                      2014, 4, 7,
                                                                      quote::RangeType::daily);
    std::cout << petr4HistoricalPrices << std::endl;
    return 0;
}
// prints:
// "PETR4.SA","PETROBRAS   -PN",15.96,"4/22/2014","4:07pm"
// Date,Open,High,Low,Close,Volume,Adj Close
// 2014-04-07,15.70,16.46,15.70,16.46,50400200,16.46
// 2014-04-04,15.62,15.71,15.35,15.44,33173500,15.44
// 2014-04-03,15.53,15.65,15.12,15.40,56189100,15.40
// 2014-04-02,15.71,16.60,15.70,15.56,66007000,14.59
```
# Dependencies

`quote` depends on libcurl to build (<http://www.curl.haxx.se/libcurl/>).

# Thread-safety

`quote` is thread safe provided the following observation:

Manual curl initialization (curl_global_init) must be performed before using quote functions in a multi-threaded context, otherwise it can be ignored. Check <http://curl.haxx.se/libcurl/c/curl_easy_init.html>.

# Install

`quote` builds on Linux and MacOSX (Windows has not been tested yet). It requires a C++11 compatible compiler. The library has been successfully built with:

* Apple LLVM version 5.0; and
* gcc (Debian 4.7.2-5) 4.7.2

Modify `common.mk` for `quote` install configuration.

Any of the following make invocations can be executed with the `-j` option (`make -j`) for parallel compilation (builds faster).

To build the library:

    $ make

The shared and static library files will be on `src/` directory. The include files needed to use `quote` are on `src/` directory.

To install:

    $ sudo make install

To uninstall:

    $ sudo make uninstall

To build the samples:

    $ make samples

To clean everything compiled (including samples):

    $ make clean


# Usage

Set the compiler standard to C++11, include `quote` headers in the search path and link to its library. E.g:

    compiler flags: `-std=c++11 -I/usr/local/quote`
    linker flags: `-L/usr/local/lib -lquote`

Include the library header `quote.h` (`namespace quote`).

Check the `samples` directory for examples.


# Documentation

See doc/html/index.html for the doxygen generated quote API reference.


# Author

`quote` was made by André Pereira Henriques [aphenriques (at) outlook (dot) com].


# License

Copyright (C) 2013, 2014  André Pereira Henriques.

quote is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

quote is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

See file `COPYING` included with this distribution or check <http://www.gnu.org/licenses/> for license information.

![gplv3 logo](http://www.gnu.org/graphics/gplv3-127x51.png)
