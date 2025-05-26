#pragma once
#include <iostream>
#include "JoinControl.h"
// using namespace std; // 헤더 파일에서는 사용 자제

// 회원가입 인터페이스를 담당하는 boundary 클래스
class JoinUI {
private:
    JoinControl* control; // 회원가입 로직을 처리하는 control 객체

public:
    // 회원가입 UI 객체를 생성한다
    JoinUI(JoinControl* control);
    
    // 회원가입 프로세스를 시작한다
    void createUser(std::istream& in, std::ostream& out);
}; 