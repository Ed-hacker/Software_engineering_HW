#include <iostream>
#include "JoinControl.h"
#include "JoinUI.h"
#include <string>
#include <limits>

// 새로운 회원가입 UI 객체를 생성한다
JoinUI::JoinUI(JoinControl* ctrl) : control(ctrl) {}

// 사용자로부터 정보를 입력받아 회원가입을 처리하고결과를 출력한다
void JoinUI::createUser(std::istream& in, std::ostream& out) {
    std::string id, pw, phone_number;
    in >> id >> pw;

    // 전화번호 입력 처리 (선택적)
    char next_char = in.peek();
    if (next_char != '\n' && next_char != EOF && next_char != '\r') {
        in >> phone_number;
    }
    
    control->addUser(id, pw, phone_number);
    out << "1.1. 회원가입\n> " << id << " " << pw;
    if (!phone_number.empty()) {
        out << " " << phone_number;
    }
    out << "\n";
} 