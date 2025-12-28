#pragma once

#include <vector>

class Sample
{
    public:
        void set_sample (const std::vector<float>& vals);
        float mean() const;
        float std_dev() const;
        void display() const;
    private:
        std::vector<float> m_data;
};

