//
// Created by vinokurov on 30.08.2019.
//

#include <iostream>
#include "IndexFile.h"

using namespace nesto;
using namespace std;

IndexFile::IndexFile(filesystem::path &filename, Logger &logger) :
    _logger{ logger }
{
    if (!filesystem::exists(filename))
    {
        createIndexFile(filename);
    }
}

IndexFile::~IndexFile() {

}

ostream &nesto::operator<<(ostream &os, const IndexFile::Version &version) {
    os << version.Maintance << version.Major << version.Minor;
    return os;
}

std::istream &nesto::operator>>(std::istream &is, IndexFile::Version &version) {
    is >> version.Maintance >> version.Major >> version.Minor;
    return is;
}

void IndexFile::createIndexFile(filesystem::path &filename) {
    _logger.debug("creating index file...");
    ofstream stream(filename);
    Version version { 0, 1, 0};
    stream << "NST" << version;
    stream.close();
    _logger.debug("index file created.");
}

const IndexFile::Version &IndexFile::version() const
{
    return _indexFileVersion;
}
