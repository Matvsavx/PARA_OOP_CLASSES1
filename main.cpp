#include <iostream>
#include <string>

enum GENDER {
    U, M, F
};

enum HEALTH {
    A1, A2, A3, B1, B2, B3
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
};

class Specialist: public Human {
};

class Professor: public Specialist, GoodStudent {
};

class Dekan: public Specialist {
};

int main() {
    Human vasya(24, GENDER::M, HEALTH::B1);
    Human slava(20, GENDER::M, HEALTH::B3);
    Human tanya(19, GENDER::F, HEALTH::B3);

    Student olya(25, GENDER::F, HEALTH::A2, "345678907654");
    Student matvey(18, GENDER::M, HEALTH::A1, "77777777777");


    BadStudent ivan(30, GENDER::U, HEALTH::A2, "228666", 1);

    std::cout << vasya.getAge() << std::endl;
    std::cout << vasya.getGender() << std::endl;

    std::cout << olya.getAge() << std::endl;
    std::cout << olya.getGender() << std::endl;
    std::cout << olya.getNumberOfZachetka() << std::endl;

    std::cout << matvey.getAge() << std::endl;
    std::cout << matvey.getHealth() << std::endl;
    std::cout << matvey.getNumberOfZachetka() << std::endl;

    std::cout << ivan.getNumberOfZachetka() << std::endl;
    std::cout << ivan.getAge() << std::endl;
    std::cout << ivan.getGender() << std::endl;
    std::cout << ivan.getMisconduct() << std::endl;

    return 0;
}