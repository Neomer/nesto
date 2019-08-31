//
// Created by vinokurov on 30.08.2019.
//

#ifndef NESTO_STOREDFILE_H
#define NESTO_STOREDFILE_H

#include <iostream>

namespace nesto {

    class StoredFile {
    public:
        StoredFile();
        ~StoredFile();

        std::iostream &stream();
    };

}


#endif //NESTO_STOREDFILE_H
