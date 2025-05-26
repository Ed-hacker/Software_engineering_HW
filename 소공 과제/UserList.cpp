#include "UserList.h"
#include <algorithm> // std::find_if 등 사용 시 필요 (현재는 직접 사용 안함)

// 새로운 사용자 목록 객체를 생성하고 기본 관리자 계정을 추가한다
UserList::UserList() {
    users.emplace_back("admin", "admin", "", UserType::ADMIN);
}

// 새로운 사용자를 목록에 추가한다
void UserList::addUser(const User& user) {
    users.push_back(user);
}

// 주어진 ID를 가진 사용자를 찾아 포인터를 반환한다 (없으면 nullptr)
User* UserList::findUserById(const std::string& id) {
    for (User& user : users) {
        if (user.getId() == id) {
            return &user;
        }
    }
    return nullptr;
}

// 등록된 모든 사용자 목록을 반환한다
const std::vector<User>& UserList::getAllUsers() const {
    return users;
} 