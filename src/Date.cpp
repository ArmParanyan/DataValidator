#include "../header/Date.h"

bool Date::is_not_nubmer(const char sym) {
    return sym < '0' || sym > '9';
}

Date::Date(std::string& date, int format) 
: m_day{nullptr}
, m_month{nullptr}
, m_year{nullptr}
, m_flag{}
{
    init_forms();
    do {
        std::cin >> format;
    } while (format <= 0 || format > 6);
    auto it = std::find_if(forms.begin(), forms.end(),
                [&] (auto args) { return static_cast<int>(args.second) == format; });
    std::cout << "Format " << (it)->first << std::endl;
    std::cout << "Enter date : ";
    std::cin >> date;

    auto splited = this->spliter(date);
}

Date::~Date() {
    delete m_day;
    delete m_month;
    delete m_year;
    m_day = nullptr;
    m_month = nullptr;
    m_year = nullptr;
}

std::vector<std::string> Date::spliter(std::string& date) {
    std::vector<std::string> spilted;
    int j = 0;
    std::string tmp = "";
    int i{};
    for (i = 0; i < date.size(); ++i) {
        if (is_not_nubmer(date[i])) {
            tmp += date.substr(j, i - j);
            j = i + 1;
            if (tmp.empty()) {
                throw std::invalid_argument("Invalid syntax dublicate symbol next to each other");                 
            }
            spilted.push_back(tmp);
            tmp.clear();
        }
    }
    tmp.clear();
    tmp += date.substr(j, i - j);
    if (!tmp.empty()) {
        spilted.push_back(tmp);
    }
    return spilted;
}

void Date::init_forms() {
    forms["DD/MM/YY"] = DateFormat::Form1;
    forms["MM/DD/YY"] = DateFormat::Form2;
    forms["MM/YY/DD"] = DateFormat::Form3;
    forms["DD/YY/MM"] = DateFormat::Form4;
    forms["YY/DD/MM"] = DateFormat::Form5;
    forms["YY/MM/DD"] = DateFormat::Form6;
}

void Date::_switch(const int format, const std::vector<std::string>& splited) {
    switch(format) {
        case static_cast<int>(DateFormat::Form1):
            this->m_day = new Day(*splited.begin());
            this->m_month = new Month(*++splited.begin());
            this->m_year = new Year(*++splited.begin());
        break;
        case static_cast<int>(DateFormat::Form2):
            this->m_month = new Month(*splited.begin());
            this->m_day = new Day(*++splited.begin());
            this->m_year = new Year(*++splited.begin());
        break;
        case static_cast<int>(DateFormat::Form3):
            this->m_month = new Month(*splited.begin());
            this->m_year = new Year(*++splited.begin());
            this->m_day = new Day(*++splited.begin());
        break;
        case static_cast<int>(DateFormat::Form4):
            this->m_day = new Day(*splited.begin());
            this->m_year = new Year((*++splited.begin()));
            this->m_month = new Month(*++splited.begin());
        break;
        case static_cast<int>(DateFormat::Form5):
            this->m_year = new Year(*splited.begin());
            this->m_day = new Day(*++splited.begin());
            this->m_month = new Month(*(++splited.begin()));
        break;
        case static_cast<int>(DateFormat::Form6):
            this->m_year = new Year((*splited.begin()));
            this->m_month = new Month(*++splited.begin());
            this->m_day = new Day(*++splited.begin());
        break;
    }
}