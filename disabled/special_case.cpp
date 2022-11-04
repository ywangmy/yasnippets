#include <filesystem>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
    filesystem::path path_now = filesystem::current_path();
    for (auto & dir_entry : filesystem::directory_iterator(path_now))
    {
        filesystem::path path_sub = dir_entry.path();
        string filename = path_sub.filename();
        if (filename.substr(0, 5) != "latex") continue;
        if (filename.back() == '-') continue;
//        if (filesystem::exists(path_sub + '-')) continue;
//        ofstream of{path_sub + "-"};
        ifstream ifs{path_sub};
        int line_number = 0;
        filesystem::path path_new = path_sub;
        path_new += "_";
        ofstream ofs{path_new};
        while (!ifs.eof())
        {
            string tmp;
            getline(ifs, tmp);
            ++ line_number;
            if (line_number == 5)
                tmp.insert(7, "$");
            if (line_number == 7)
                tmp.insert(0, "\\$");
            ofs << tmp;
        }
    }
    return 0;
}
