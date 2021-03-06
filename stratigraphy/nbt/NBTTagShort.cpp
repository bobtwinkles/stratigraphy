#include "nbt/NBTTag.h"
#include "nbt/IOUtils.h"
#include <boost/format.hpp>

using namespace stratigraphy;
using namespace nbt;

using namespace std;

NBTTagShort::NBTTagShort(istream& from) {
    ReadFrom(from);
}

NBTTagShort::NBTTagShort(string& name) : _val(0), NBTTag(name) {
}

NBTTagShort::NBTTagShort(string& name, short val) : _val(val), NBTTag(name) {
}

NBTTagShort::~NBTTagShort() {
}

TagType NBTTagShort::GetTagType() {
    return SHORT;
}

void NBTTagShort::WriteData(ostream& o, char* buff) {
    WriteShortBE(o, _val, buff);
}

void NBTTagShort::ReadData(istream& is, char* buff) {
    _val = ReadShortBE(is, buff);
}

NBTTagShort& NBTTagShort::operator= (const NBTTagShort& rhs) {
    if (&rhs == this) {
        return *this;
    }

    delete &_name;

    _name = string(rhs._name);
    _val = rhs._val;

    return *this;
}

short NBTTagShort::GetValue() {
    return _val;
}

void NBTTagShort::SetValue(short s) {
    _val = s;
}
