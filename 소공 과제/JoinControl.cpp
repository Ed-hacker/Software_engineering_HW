#include "JoinControl.h"
#include "User.h"

// 새로운 회원가입 제어 객체를 생성한다
JoinControl::JoinControl(UserList* uList) : userList(uList) {}

// 새로운 사용자를 사용자 목록에 추가한다
void JoinControl::addUser(const std::string& id, const std::string& pw, const std::string& phone) {
    UserType type = (id == "admin") ? UserType::ADMIN : UserType::GENERAL; // ID가 "admin"이면 관리자 유형으로 설정한다
    User newUser(id, pw, phone, type);
    userList->addUser(newUser);
} 