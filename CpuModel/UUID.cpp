#include <string>
#include "UUID.h"

using namespace std;

UUID::UUID() {
    for (int i = 0; i < 16; i++) {
        uuid += "0123456789abcdef"[rand() % 16];
    };
}

UUID::UUID(string _uuid) {
    uuid = _uuid;
}

UUID::UUID(UUID& other) {
    uuid = other.uuid;
}

UUID& UUID::operator=(UUID& other) {
    uuid = other.uuid;
    return *this;
}

bool UUID::operator==(UUID& other) {
    return uuid == other.uuid;
}

bool UUID::operator!=(UUID& other) {
    return uuid != other.uuid;
}

string UUID::getUUID() {
    return uuid;
}

void UUID::setUUID(string _uuid) {
    uuid = _uuid;
}
