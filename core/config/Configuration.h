//
// Created by kir on 26.08.2019.
//

#ifndef NESTO_CONFIGURATION_H
#define NESTO_CONFIGURATION_H

#include "../JsonSerializable.h"

namespace nesto {

/**
 * Abstract class for any configurations stored in json format.
 */
class Configuration : JsonSerializable
{
public:
    /**
     * ctor
     * @param filename Path to the configuration file.
     * @param saveOnDestroy Set it to true if application should save configuration to file, on configuration instance destroys.
     */
    explicit Configuration(std::string_view filename, bool saveOnDestroy = false);

    ~Configuration() override;

    /**
     * Reads and deserializes configuration file.
     */
    void reload();

    /**
     * Save configuration to the file.
     */
    void save();

private:
    const char *_filename;
    bool _saveOnDestroy;
};

}

#endif //NESTO_CONFIGURATION_H
