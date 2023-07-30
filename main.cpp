#include <iostream>

struct Student {
    int number;
    char name[100];
    double score;
};

void StudentDate(const Student students[], int numStudents) {
    for (int i = 0; i < numStudents; i++) 
    {
        std::cout << "번호: " << students[i].number << std::endl;
        std::cout << "이름: " << students[i].name << std::endl;
        std::cout << "점수: " << students[i].score << std::endl;
    }
}

double TotalScore(const Student students[], int numStudents) {
    double totalScore = 0;
    for (int i = 0; i < numStudents; ++i) {
        totalScore += students[i].score;
    }
    return totalScore;
}

void sortDescending(Student students[], int numStudents) {
    for (int i = 0; i < numStudents - 1; ++i) {
        for (int j = 0; j < numStudents - i - 1; ++j) {
            if (students[j].score < students[j + 1].score) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int numStudents;
    std::cout << "학생 수를 입력하세요 ";
    std::cin >> numStudents;

    const int maxStudents = 100;
    Student students[maxStudents];

    for (int i = 0; i < numStudents; ++i) {
        Student student;
        std::cout << "번호: ";
        std::cin >> student.number;
        std::cin.ignore(); 

        std::cout << "이름: ";
        std::cin.getline(student.name, sizeof(student.name));

        std::cout << "점수: ";
        std::cin >> student.score;

        std::cout << "---------------------------" << std::endl;

        students[i] = student;
    }

    int choice;
    std::cout << "하나를 선택하세요" << std::endl;
    std::cout << "1. 리스트 출력" << std::endl;
    std::cout << "2. 점수 총합" << std::endl;
    std::cout << "3. 내림차순 정렬" << std::endl;
    std::cin >> choice;

    switch (choice) {
    case 1:
        StudentDate(students, numStudents);
        break;

    case 2:
        std::cout << "총합 점수는:" << TotalScore(students, numStudents) << std::endl;
        break;

    case 3:
        sortDescending(students, numStudents);
        std::cout << "내림차순 정렬:" << std::endl;
        StudentDate(students, numStudents);
        break;

    default:
        std::cout << "종료" << std::endl;
        break;
    }
};