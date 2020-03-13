#include <iostream>
#include <string>

using namespace std;

enum GENDER {
    U, M, F
};

enum HEALTH {
    A1, A2, A3, B1, B2, B3
};

enum GRADES {
    EX, GOOD
};

enum DIPLOM {
    RED, BlUE
};

// 1. Создать несколько Human.
// 2. Добавить несколько дополнительных полей (не забывать добавить значимые поля в конструктор)
// 3. Добавить getter'ы и setter'ы
// 4. Продемонстрировать обращение к полям объектов дочерних и родительских классов
// 5. Добавить несколько наследников от различных родителей (сделать дерево из 5 классов)

class Human {
    int age;
    GENDER gender;
    HEALTH health;

public:
    Human(int age, GENDER gender, HEALTH health) : age(age) {
        this->gender = gender;
        this->health = health;
    }

    int getAge() const {
        return age;
    }

    void setAge(int age) {
        this->age = age;
    }

    GENDER getGender() const {
        return gender;
    }

    void setGender(GENDER gender) {
        this->gender = gender;
    }

    HEALTH getHealth() const {
        return health;
    }

    void setHealth(HEALTH health) {
        this->health = health;
    }
};

class Student : public Human {
    std::string numberOfZachetka;
public:
    Student(int age, GENDER gender, HEALTH health, const std::string &numberOfZachetka) : Human(age, gender, health) {
        this->numberOfZachetka = numberOfZachetka;
    }

    const std::string &getNumberOfZachetka() const {
        return numberOfZachetka;
    }

    void setNumberOfZachetka(const std::string &numberOfZachetka) {
        this->numberOfZachetka = numberOfZachetka;
    }
};

class BadStudent: public Student {
    bool misconduct;
public:
    BadStudent(int age, GENDER gender, HEALTH health, const std::string &numberOfZachetka, bool misconduct): Student(age, gender, health, numberOfZachetka){
        this->misconduct = misconduct;
    }

    void setMisconduct(bool misconduct) {
        this->misconduct = misconduct;
    }

    bool getMisconduct() const {
        return misconduct;
    }
};

class GoodStudent: public Student {
    GRADES grades;
public:
    GoodStudent(int age, GENDER gender, HEALTH health, const std::string &numberOfZachetka, GRADES grades) : Student(
            age, gender, health, numberOfZachetka), grades(grades) {
        this -> grades = grades;
    }

    GRADES getGrades() const {
        return grades;
    }

    void setGrades(GRADES grades) {
        this->grades = grades;
    }
};

class Specialist: public GoodStudent {
    DIPLOM diplom;
public:
    Specialist(int age, GENDER gender, HEALTH health, const std::string &numberOfZachetka, GRADES grades, DIPLOM diplom)
            : GoodStudent(age, gender, health, numberOfZachetka, grades), diplom(diplom) {
        this->diplom = diplom;
    }

    DIPLOM getDiplom() const {
        return diplom;
    }

    void setDiplom(DIPLOM diplom) {
        this->diplom = diplom;
    }
};

class Zek: public BadStudent {
    bool conviction;
public:
    Zek(int age, GENDER gender, HEALTH health, const std::string &numberOfZachetka, bool misconduct, bool conviction)
            : BadStudent(age, gender, health, numberOfZachetka, misconduct), conviction(conviction) {
        this->conviction = conviction;
    }

    bool getConviction() const {
        return conviction;
    }

    void setConviction(bool conviction) {
        this->conviction = conviction;
    }
};

int main() {
    Human vasya(24, GENDER::M, HEALTH::B1);
    Human slava(20, GENDER::M, HEALTH::B3);
    Human tanya(19, GENDER::F, HEALTH::B3);

    Student olya(25, GENDER::F, HEALTH::A2, "345678907654");
    Student matvey(18, GENDER::M, HEALTH::A1, "77777777777");

    GoodStudent Petr(21, GENDER::U, HEALTH::A3, "007333445", GRADES::EX);

    BadStudent ivan(30, GENDER::U, HEALTH::A2, "228666", true);

    Specialist Serega(40, GENDER::M, HEALTH::A1, "5555444555", GRADES::EX, DIPLOM::RED);

    Zek Valya(47, GENDER::F, HEALTH::B2, "2281337", true, true);

    cout << "VASYA (human):" << endl;
    cout << "Age: " << vasya.getAge() << endl;
    cout << "Gender: " << vasya.getGender() << endl;
    cout << "Health: " << vasya.getHealth() << endl;

    cout << endl << "OLYA (student): " << endl;
    cout << "Age: " << olya.getAge() << endl;
    cout << "Gender: " << olya.getGender() << endl;
    cout << "Zachetka: " << olya.getNumberOfZachetka() << endl;

    cout << endl << "MATVEY (student): " << endl;
    cout << "Age: " << matvey.getAge() << endl;
    cout << "Gender: " << matvey.getGender() << endl;
    cout << "Zachetka: " << matvey.getNumberOfZachetka() << endl;

    cout << endl << "IVAN (bad student):" << endl;
    cout << "Zachetka: " << ivan.getNumberOfZachetka() << endl;
    cout << "Age: " << ivan.getAge() << endl;
    cout << "Gender: " << ivan.getGender() << endl;
    cout << "Miscondacts: " << ivan.getMisconduct() << endl;

    cout << endl << "PETR (good student): " << endl;
    cout << "Age: " << Petr.getAge() << endl;
    cout << "Gender: " << Petr.getGender() << endl;
    cout << "Zachetka: " << Petr.getNumberOfZachetka() << endl;
    cout << "Health: " << Petr.getHealth() << endl;
    cout << "Grades: " << Petr.getGrades() << endl;

    cout << endl << "SEREGA (specialist):" << endl;
    cout << "Age: " << Serega.getAge() << endl;
    cout << "Gender: " << Serega.getGender() << endl;
    cout << "Zachetka: " << Serega.getNumberOfZachetka() << endl;
    cout << "Health: " << Serega.getHealth() << endl;
    cout << "Grades: " << Serega.getGrades() << endl;
    cout << "Diplom: " << Serega.getDiplom() << endl;

    cout << endl << "VALYA (zek):" << endl;
    cout << "Zachetka: " << Valya.getNumberOfZachetka() << endl;
    cout << "Age: " << Valya.getAge() << endl;
    cout << "Gender: " << Valya.getGender() << endl;
    cout << "Miscondacts: " << Valya.getMisconduct() << endl;
    cout << "Convictions: " << Valya.getConviction() << endl;

    return 0;
}