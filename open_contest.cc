#include<bits/stdc++.h>

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    std::string F = buf;
    return F.substr(11, 8);
}

// time,id,numberofproblem,subtask,number

int main() {
    std:: cout << "Time : Contest ID : Number of Problems : Sub task(0,1) : Subtask Number" << '\n';

    std::string start_time;
    std::cin >> start_time;

    while (currentDateTime() != start_time);

    std::string contest_id;
    std::cin >> contest_id;

    int number_of_problems;
    std::cin >> number_of_problems;

    bool sub_task = true;
    std::cin >> sub_task;

    int subtask_number;
    std::cin >> subtask_number;

    for (int i = 0; i < std::min(number_of_problems, 26) - sub_task; i++) {
        std::string O = "open -a \"Google Chrome\" https://codeforces.com/contest/";

        O += contest_id;
        O += "/problem/";
        O += 'A' + i;
        if (sub_task && subtask_number == i + 1) {
            O += '1';
            system(O.c_str());
            O.back() = '2';
        }

        system(O.c_str());
    }
}