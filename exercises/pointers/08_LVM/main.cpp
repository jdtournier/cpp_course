#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>

struct Response {
  std::vector<float> yes, no;
};

Response load_lvm_data (const std::string& filename)
{
    // open file and check for errors:
    std::ifstream inFile(filename);
    if (!inFile)
        throw std::runtime_error ("Error opening file: \"" + filename + "\"");

    char yn;
    float lvm;
    std::vector<float> yes, no;
    // read data entries:
    while (inFile >> yn >> lvm) {
        if (yn == 'Y')
            yes.push_back(lvm);
        else
            no.push_back(lvm);
    }

    return { yes, no };
}



float compute_mean (const std::vector<float>& v)
{
    float mean = 0.0;
    for (auto x : v)
        mean += x;
    return mean / v.size();
}



int main(int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);
    if (args.size() < 2)
        throw std::runtime_error ("expected LVM data file as first argument");

    // load data:
    auto lvm = load_lvm_data ("lvm_data.txt");
    std::cout << lvm.yes.size() << ", " << lvm.no.size()
        << " values read for Y/N\n";

    // display means:
    std::cout << "Mean LVM for subjects with mutation = "
        << compute_mean (lvm.yes) << "\n";
    std::cout << "Mean LVM for subjects without mutation = "
        << compute_mean (lvm.no) << "\n";

    return 0;
}
