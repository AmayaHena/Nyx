/*
** PERSONAL PROJECT, 2020
** Nyx
** File description:
** json
*/

#include "../lib/FormatParser/inc/JSONParser.hpp"

int main()
{
    FileManager::File f_tp("files/JSON/t1.json");
    FileManager::File f_p("files/JSON/t1_parsed.txt");

    if (!f_tp.isFile())
        return 84;
    if (!f_p.isFile())
        return 84;

    FormatParser::JSONParser j;

    size_t it = 0;
    std::vector<std::string> v = f_p.getContent();

    for (std::pair<std::string, std::string> p : j.parse(f_tp)) {

        std::cout << "[TP] " << p.first << " " << p.second << std::endl;
        std::cout << "[P] " << v[it] << std::endl;

        if (v[it] != (p.first + " " + p.second))
            return 84;
        it++;
    }

    std::cout << "---" << std::endl;

    if (!f_p.setPath("files/JSON/t2_parsed.txt"))
        return 84;

    it = 0;
    v = f_p.getContent();
    for (std::string s : j.getSection(f_tp)) {

        std::cout << "[TP] " << s << std::endl;
        std::cout << "[P] " << v[it] << std::endl;

        if (v[it] != s)
            return 84;
        it++;
    }

    std::cout << "---" << std::endl;

    if (!f_p.setPath("files/JSON/t3_parsed.txt"))
        return 84;

    it = 0;
    v = f_p.getContent();
    for (std::pair<std::string, std::string> p : j.parse(f_tp, "SelfEvaluation")) {

        std::cout << "[TP] " << p.first << " " << p.second << std::endl;
        std::cout << "[P] " << v[it] << std::endl;

        if (v[it] != (p.first + " " + p.second))
            return 84;
        it++;
    }

    return 0;
}
