#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <windows.h>
#include <algorithm>

using namespace std;

const int MAX_STUDENTS = 200;

struct Name {
    string name,
        familia,
        otchestvo;
};

struct Marker {
    double math,
        physics,
        russian;
};

struct Address {
    string city,
        street,
        home;
};

struct Student {
    Name fullname;
    Marker marks;
    Address address;
};

// Функция для добавления нового студента в конец массива
void AddStudent(Student x[], int& n) {
    if (n < MAX_STUDENTS) {
        cout << "Введите ФИО абитуриента: ";
        cin >> x[n].fullname.familia >> x[n].fullname.name >> x[n].fullname.otchestvo;
        cout << "Введите город или нас.пункт абитуриента: ";
        cin.ignore();
        getline(cin, x[n].address.city);
        cout << "Введите улицу проживания абитуриента: ";
        getline(cin, x[n].address.street);
        cout << "Введите дом проживания абитуриента: ";
        getline(cin, x[n].address.home);
        cout << "Введите оценку по математике: ";
        cin >> x[n].marks.math;
        cin.ignore(); // Очищаем входной буфер
        cout << "Введите оценку по физике: ";
        cin >> x[n].marks.physics;
        cin.ignore(); // Очищаем входной буфер
        cout << "Введите оценку по русскому языку: ";
        cin >> x[n].marks.russian;
        cin.ignore(); // Очищаем входной буфер

        n++;
    }
    else {
        cout << "Достигнуто максимальное количество студентов (" << MAX_STUDENTS << ")." << endl;
    }
}

// Функция для вывода информации о студентах
void OutputStudent(Student x[], int n) {
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            cout << "| " << setw(4) << i + 1 << "| "
                << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                << "| " << setw(21) << left << x[i].marks.math
                << "| " << setw(17) << left << x[i].marks.physics
                << "| " << setw(18) << left << x[i].marks.russian
                << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                << "|\n";
        }
        else {
            cout << "| " << i + 1 << setw(5) << "   | "
                << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                << "| " << setw(21) << left << x[i].marks.math
                << "| " << setw(17) << left << x[i].marks.physics
                << "| " << setw(18) << left << x[i].marks.russian
                << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                << "|\n";
        }
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
}

// Функция для удаления записи
void DeleteStudent(Student x[], int& n, int index) {
    if (index < 0 || index >= n) {
        cout << "Ошибка: Некорректный номер записи." << endl;
        return;
    }

    cout << "Вы уверены, что хотите удалить эту запись? (y/n): ";
    char confirm;
    cin >> confirm;

    if (confirm == 'y' || confirm == 'Y') {
        for (int i = index; i < n - 1; ++i) {
            x[i] = x[i + 1];
        }

        n--;
    }
    else {
        cout << "Удаление отменено." << endl;
    }
}

void SaveToFile(Student x[], int n, string filename) {
    ofstream file(filename);
    if (file.is_open()) {
        file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
        file << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
        file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

        for (int i = 0; i < n; i++) {
            if (i < 9) {
                file << "| " << i + 1 << setw(5) << "   | "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
            if (i >= 9 && i < 99) {
                file << "| " << i + 1 << setw(4) << "  | "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
            if (i > 99) {
                file << "| " << i + 1 << setw(3) << " | "
                    << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                    << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                    << "| " << setw(21) << left << x[i].marks.math
                    << "| " << setw(17) << left << x[i].marks.physics
                    << "| " << setw(18) << left << x[i].marks.russian
                    << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                    << "|\n";
            }
        }

        file << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

        cout << "Данные успешно сохранены в файл " << filename << endl;
    }
    else {
        cout << "Ошибка при открытии файла " << filename << " для записи." << endl;
    }

    file.close();
}

bool CompareByFullName(const Student& a, const Student& b) {
    string full_name_a = a.fullname.familia + " " + a.fullname.name + " " + a.fullname.otchestvo;
    string full_name_b = b.fullname.familia + " " + b.fullname.name + " " + b.fullname.otchestvo;
    return full_name_a < full_name_b;
}

void LoadFromFile(Student x[], int& n, string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        n = 0; // Инициализируем количество студентов

        while (!file.eof() && n < MAX_STUDENTS) {
            file >> x[n].fullname.familia >> x[n].fullname.name >> x[n].fullname.otchestvo
                >> x[n].address.city >> x[n].address.street >> x[n].address.home
                >> x[n].marks.math >> x[n].marks.physics >> x[n].marks.russian;
            n++; // Увеличиваем количество студентов
        }

        cout << "Данные успешно загружены из файла " << filename << endl;
    }
    else {
        cout << "Ошибка при открытии файла " << filename << " для чтения." << endl;
    }

    file.close();
}


// Функция для сортировки студентов по ФИО
void SortStudentsByName(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.fullname.familia + " " + a.fullname.name + " " + a.fullname.otchestvo) <
            (b.fullname.familia + " " + b.fullname.name + " " + b.fullname.otchestvo);
        });
}

// Функция для сортировки студентов по среднему баллу
void SortStudentsByAverageMarks(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.marks.math + a.marks.physics + a.marks.russian) / 3.0 >
            (b.marks.math + b.marks.physics + b.marks.russian) / 3.0;
        });
}

// Функция для сортировки студентов по оценкам по предметам
void SortStudentsBySubjectMarks(Student x[], int n) {
    sort(x, x + n, [](const Student& a, const Student& b) {
        return (a.marks.math + a.marks.physics + a.marks.russian) / 3.0 >
            (b.marks.math + b.marks.physics + b.marks.russian) / 3.0;
        });
}

void FindStudentsByCity(Student x[], int n, string city) {
    bool found = false;
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    for (int i = 0; i < n; i++) {
        if (x[i].address.city == city) {
            found = true;
            cout << "| " << i + 1 << setw(5) << "   | "
                << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                << "| " << setw(21) << left << x[i].marks.math
                << "| " << setw(17) << left << x[i].marks.physics
                << "| " << setw(18) << left << x[i].marks.russian
                << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                << "|\n";
        }
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    if (!found) {
        cout << "Студенты из указанного города не найдены." << endl;
    }
}

// Функция для поиска студентов по улице
void FindStudentsByStreet(Student x[], int n, string street) {
    bool found = false;
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";
    cout << "| №   |          Ф.И.О.                  |           Адрес              | Оценка по математике | Оценка по физике | Оценка по рус.яз. | Ср.балл |\n";
    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    for (int i = 0; i < n; i++) {
        if (x[i].address.street == street) {
            found = true;
            cout << "| " << i + 1 << setw(5) << "   | "
                << setw(33) << left << x[i].fullname.familia + " " + x[i].fullname.name + " " + x[i].fullname.otchestvo
                << "| " << setw(29) << left << x[i].address.city + ", " + x[i].address.street + ", " + x[i].address.home
                << "| " << setw(21) << left << x[i].marks.math
                << "| " << setw(17) << left << x[i].marks.physics
                << "| " << setw(18) << left << x[i].marks.russian
                << "| " << setw(8) << left << (x[i].marks.math + x[i].marks.physics + x[i].marks.russian) / 3.0
                << "|\n";
        }
    }

    cout << "+-----+----------------------------------+------------------------------+----------------------+------------------+-------------------+---------+\n";

    if (!found) {
        cout << "Студенты из указанной улицы не найдены." << endl;
    }
}

void OutputSubjectMarks(Student x[], int n) {
    cout << "+-------------------------------------+-----------+\n";
    cout << "|            Предмет                  | Средний   |\n";
    cout << "|                                     |  балл     |\n";
    cout << "+-------------------------------------+-----------+\n";

    double mathSum = 0, physicsSum = 0, russianSum = 0;

    for (int i = 0; i < n; i++) {
        mathSum += x[i].marks.math;
        physicsSum += x[i].marks.physics;
        russianSum += x[i].marks.russian;
    }

    double mathAverage = mathSum / n;
    double physicsAverage = physicsSum / n;
    double russianAverage = russianSum / n;

    cout << "| Математика                          | " << setw(10) << left << mathAverage << "|\n";
    cout << "+-------------------------------------+-----------+\n";
    cout << "| Физика                              | " << setw(10) << left << physicsAverage << "|\n";
    cout << "+-------------------------------------+-----------+\n";
    cout << "| Русский язык                        | " << setw(10) << left << russianAverage << "|\n";

    cout << "+-------------------------------------+-----------+\n";
}



int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Student studentList[MAX_STUDENTS];
    int studentCount = 0;
    int choice;
    char addMore;
    string loadFilename; // Переменная объявлена здесь
    string city, street, home;

    do {
        cout << "Меню:" << endl;
        cout << "(1)Ввести данные абитуриента" << endl;
        cout << "(2)Вывести данные абитуриентов в виде таблицы" << endl;
        cout << "(3)Удалить запись" << endl;
        cout << "(4)Сохранить данные в файл" << endl;
        cout << "(5)Загрузить данные из файла" << endl;
        cout << "(6)Сортировка по ФИО" << endl;
        cout << "(7)Сортировка по среднему баллу" << endl;
        cout << "(8)Сортировка по оценкам по предметам" << endl;
        cout << "(9)Поиск по адресу" << endl;
        cout << "(10)Перечень предметов с указанием среднего балла" << endl;
        cout << "(0)Выйти" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            system("cls");
            do {
                AddStudent(studentList, studentCount);
                cout << "Добавить еще абитуриента? (y/n): ";
                cin >> addMore;
            } while (addMore == 'y' || addMore == 'Y');
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            OutputStudent(studentList, studentCount);
            system("pause");
            system("cls");
            break;
        case 3:
            system("cls");
            int index;
            OutputStudent(studentList, studentCount);
            cout << "Введите номер записи для удаления(общее количество записей " << studentCount << "):";
            cin >> index;
            DeleteStudent(studentList, studentCount, index - 1);
            system("pause");
            system("cls");
            break;
        case 4:
            system("cls");
            SaveToFile(studentList, studentCount, "students.txt");
            system("pause");
            system("cls");
            break;
        case 5:
            cout << "Введите имя файла для загрузки данных: ";
            cin >> loadFilename;
            LoadFromFile(studentList, studentCount, loadFilename);
            break;
        case 6:
            system("cls");
            SortStudentsByName(studentList, studentCount);
            cout << "Студенты отсортированы по ФИО." << endl;
            break;
        case 7:
            system("cls");
            SortStudentsByAverageMarks(studentList, studentCount);
            cout << "Студенты отсортированы по среднему баллу." << endl;
            system("pause");
            system("cls");
            break;
        case 8:
            system("cls");
            SortStudentsBySubjectMarks(studentList, studentCount);
            cout << "Студенты отсортированы по оценкам по предметам." << endl;
            system("pause");
            system("cls");
            break;
        case 9:
            system("cls");
            int searchChoice;
            cout << "Поиск:" << endl;
            cout << "(1)По городу" << endl;
            cout << "(2)По улице" << endl;
            cout << "Выберите метод поиска: ";
            cin >> searchChoice;
            switch (searchChoice) {
            case 1:
                cout << "Введите город: ";
                cin.ignore();
                getline(cin, city);
                FindStudentsByCity(studentList, studentCount, city);
                break;
            case 2:
                cout << "Введите улицу: ";
                cin.ignore();
                getline(cin, street);
                FindStudentsByStreet(studentList, studentCount, street);
                break;
            default:
                cout << "Некорректный ввод. Повторите попытку." << endl;
            }
            system("pause");
            system("cls");
            break;
        case 10:
            system("cls");
            OutputSubjectMarks(studentList, studentCount);
            system("pause");
            system("cls");
            break;
        case 0:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Некорректный ввод. Повторите попытку." << endl;
        }
    } while (choice != 0);

    return 0;
}
