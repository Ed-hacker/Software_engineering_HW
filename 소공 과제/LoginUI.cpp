#include "LoginUI.h"
#include <string>

// 새로운 로그인 UI 객체를 생성한다
LoginUI::LoginUI(LoginControl* ctrl) : control(ctrl) {}

// 사용자로부터 로그인 정보를 입력받아 로그인 처리를 요청하고 결과를 출력한다
void LoginUI::loginUser(std::istream& in, std::ostream& out) {
    std::string id, pw;
    in >> id >> pw;
    bool success = control->attemptLogin(id, pw);
    out << "2.1. 로그인\n";
    if (success) {
        out << ">" << id << " " << pw << "\n";
    } else {
        out << "> 로그인 실패\n";
    }
} 