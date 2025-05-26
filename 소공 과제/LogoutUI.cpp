#include "LogoutUI.h"
#include <string>

// 새로운 로그아웃 UI 객체를 생성한다
LogoutUI::LogoutUI(LogoutControl* ctrl)
    : logoutControl(ctrl) {}

// 로그아웃 처리를 요청하고 결과를 출력한다
void LogoutUI::requestLogout(std::ostream& out, User* currentUser) {
    std::string userIdToLog = "";
    if (currentUser != nullptr) {
        userIdToLog = currentUser->getId(); // 로그아웃할 사용자 ID 저장
    }

    logoutControl->logout(); // control 계층에 로그아웃 요청
    
    out << "2.2. 로그아웃\n";
    if (!userIdToLog.empty()) {
        out << "> " << userIdToLog << "\n";
    } 
} 