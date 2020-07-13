/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** Loader
*/

#pragma once

    #include "File.hpp"

namespace FileManager {

    class Loader final {

        public:

            Loader(const std::string &path);
            ~Loader() noexcept;

            /* File Del & Load */
            bool load(const std::string &path);
            bool delFile(const std::string &path);
            bool delFile(size_t pos = 0);

            /* Getters */
            bool isFile(const std::string &s);
            size_t getFileNb();

            /* Overloading Operator */
            inline File &operator[](size_t pos) { return _cont.at(pos); }

        private:

            /* Container */
            std::vector<File> _cont;

            /* File object */
            File _f;

    };

}
