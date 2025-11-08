#include <iostream>

#include "generator.h"

int main() {
    auto entries = read_unicode_data("unicodedata/UnicodeData.txt");
    auto properties = parse_unicode_data(entries);

    uint32_t cp = 0x0041;
    std::cout << (properties[cp] & PROP_UPPER) << std::endl;
    return 0;
}
