#pragma once

#include <string>

using namespace std;

class UUID {
    string uuid;

public: 
    UUID();
    UUID(string _uuid);
    UUID(UUID& other);

    UUID& operator=(UUID& other);

    bool operator==(UUID& other);
    bool operator!=(UUID& other);

    string getUUID();
    void setUUID(string _uuid);
};
