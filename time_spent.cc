#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void add_time_to_report()
{
    string crs1{}, crs2{}, crs3{};
    int time1{}, time2{}, time3{};

    ifstream ifs{"report.txt"};
    ifs >> crs1 >> crs2 >> crs3;
    ifs.close();

    cout << "Set time for \"" << crs1 << "\": ";
    cin >> time1;
    cout << "Set time for \"" << crs2 << "\": ";
    cin >> time2;
    cout << "Set time for \"" << crs2 << "\": ";
    cin >> time3;

    ofstream ofs{"report.txt", ios_base::app};
    ofs << time1 << " " << time2 << " " << time3 << endl;
    ofs.close();
    return;
}
void display_report()
{
    string crs1{}, crs2{}, crs3{};
    int course1{}, course2{}, course3{};
    int sum1{}, sum2{}, sum3{};
    ifstream ifs{"report.txt"};

    ifs >> crs1 >> crs2 >> crs3;
    while(ifs >> course1 >> course2 >> course3)
    {
        sum1 += course1;
        sum2 += course2;
        sum3 += course3;
    }

    cout << crs1 << ": " << sum1 << endl;
    cout << crs2 << ": " << sum2 << endl;
    cout << crs3 << ": " << sum3 << endl << endl;

    ifs.close();
    return;
}
void set_courses_for_report()
{
    string crs1{}, crs2{}, crs3{};

    cout << "Ange första kursen: ";
    cin >> crs1;
    cout << "Ange andra kursen: ";
    cin >> crs2;
    cout << "Ange tredje kursen: ";
    cin >> crs3;

    ofstream ofs{"report.txt"};
    ofs << crs1 << " " << crs2 << " " << crs3 << endl;

    ofs.close();
    return;
}
void reset_time_report()
{
    std::ofstream ofs{"report.txt", std::ofstream::out | std::ofstream::trunc};
    ofs.close();
    return;
}

int main()
{
    bool running = true;
    int choice{};

    do{
        cout << "Welcome to Time Spent" << endl;
        cout << "Make a decision\n 1. Add time\n 2. Display time spent\n 3. Set courses\n 4. Reset\n 5. Quit \n(Don't forget to add courses if this is the first time)" << endl;

        cin >> choice;

        switch(choice)
        {
            case 1:
                add_time_to_report();
                break;
            case 2:
                display_report();
                break;
            case 3:
                set_courses_for_report();
                break;
            case 4:
                reset_time_report();
                break;
            case 5:
                running = false;
                break;
        }
    }
    while(running);

    return 0;
}
