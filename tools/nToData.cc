// Convert gold number behind school card to M1Card sector 0 data.
// Proof-Of-Concept.
//   by Recolic Keghart <root@recolic.net>, Sep 3, 2019
//
// Compile: g++ -std=c++17 nToData.cc
/* Run:
$ ./a.out
1231231233
First 8 bytes data:   1196349 32 280400
*/

#include <rlib/stdio.hpp>
#include <iomanip>

int main() {
    uint32_t originNumber = rlib::scanln().as<uint32_t>();
    uint32_t reverted = htobe32(originNumber);
    uint8_t *asChar = (uint8_t*)&reverted;

    rlib::println("First 8 bytes data: ", std::hex, reverted, asChar[0]^asChar[1]^asChar[2]^asChar[3], "280400");

}



