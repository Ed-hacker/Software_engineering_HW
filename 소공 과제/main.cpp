#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "User.h"
#include "JoinControl.h"
#include "JoinUI.h"
#include "LoginControl.h"
#include "LoginUI.h"
#include "LogoutControl.h"
#include "LogoutUI.h"
#include "RegisterBikeControl.h"
#include "RegisterBikeUI.h"
#include "RentBikeControl.h"
#include "RentBikeUI.h"
#include "ListRentedBikeControl.h"
#include "ListRentedBikeUI.h"
#include "UserList.h"
#include "BikeList.h"
#include "ExitUI.h"

// 입력 파일 이름을 정의한다
#define INPUT_FILE_NAME "input.txt"
// 출력 파일 이름을 정의한다
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void doTask(std::ifstream& inFile, std::ofstream& outFile, User*& currentLoginUser, JoinUI* joinUI, LoginUI* loginUI, LogoutUI* logoutUI, RegisterBikeUI* registerBikeUI, RentBikeUI* rentBikeUI, ListRentedBikeUI* listRentedBikeUI, ExitUI* exitUI);

int main() {
    std::ifstream in_fp; // 입력 파일 스트림
    std::ofstream out_fp; // 출력 파일 스트림
    UserList userList; // 사용자 목록 관리 객체
    BikeList bikeList; // 자전거 목록 관리 객체
    User* currentLoginUser = nullptr; // 현재 로그인한 사용자 객체, 초기에는 아무도 로그인하지 않은 상태

    // 각 기능별 control 및 boundary 객체들을 생성한다
    JoinControl* joinCtrl = new JoinControl(&userList);
    JoinUI* joinUI = new JoinUI(joinCtrl);
    LoginControl* loginCtrl = new LoginControl(&userList, &currentLoginUser);
    LoginUI* loginUI = new LoginUI(loginCtrl);
    LogoutControl* logoutCtrl = new LogoutControl(&currentLoginUser);
    LogoutUI* logoutUI = new LogoutUI(logoutCtrl);
    
    RegisterBikeControl* registerBikeCtrl = new RegisterBikeControl(&bikeList);
    RegisterBikeUI* registerBikeUI = new RegisterBikeUI(registerBikeCtrl);
    
    RentBikeControl* rentBikeCtrl = new RentBikeControl(&bikeList, &currentLoginUser);
    RentBikeUI* rentBikeUI = new RentBikeUI(rentBikeCtrl);
    
    ListRentedBikeControl* listRentedBikeCtrl = new ListRentedBikeControl(&currentLoginUser);
    ListRentedBikeUI* listRentedBikeUI = new ListRentedBikeUI(listRentedBikeCtrl);

    ExitUI* exitUI = new ExitUI();

    // 입출력 파일을 연다
    in_fp.open(INPUT_FILE_NAME);
    out_fp.open(OUTPUT_FILE_NAME);
   
    // 파일로부터 명령을 읽어 처리하는 주 루프를 실행한다
    doTask(in_fp, out_fp, currentLoginUser, joinUI, loginUI, logoutUI, registerBikeUI, rentBikeUI, listRentedBikeUI, exitUI);
    
    // 동적으로 할당된 객체들의 메모리를 해제한다
    delete joinCtrl; delete joinUI;
    delete loginCtrl; delete loginUI;
    delete logoutCtrl; delete logoutUI;
    delete registerBikeCtrl; delete registerBikeUI;
    delete rentBikeCtrl; delete rentBikeUI;
    delete listRentedBikeCtrl; delete listRentedBikeUI;
    delete exitUI;
    
    // 열었던 파일들을 닫는다
    if (in_fp.is_open()) in_fp.close();
    if (out_fp.is_open()) in_fp.close();
    
    return 0; // 프로그램 정상 종료
}

// 파일로부터 입력을 받아 각 메뉴에 따른 작업을 수행하고 결과를 파일에 출력한다
void doTask(std::ifstream& inFile, std::ofstream& outFile, User*& currentLoginUser, JoinUI* joinUI, LoginUI* loginUI, LogoutUI* logoutUI, RegisterBikeUI* registerBikeUI, RentBikeUI* rentBikeUI, ListRentedBikeUI* listRentedBikeUI, ExitUI* exitUI) {
    int menu_level_1 = 0, menu_level_2 = 0; // 파일에서 읽어올 메뉴 번호
    int is_program_exit = 0; // 종료 메뉴 선택 여부 플래그
    
    // 파일의 끝에 도달할 때까지 메뉴 입력을 계속 읽는다
    while (inFile >> menu_level_1 >> menu_level_2) {
        if (is_program_exit) { // 종료 플래그가 설정되면 루프를 중단한다
            break;
        }
        // 첫 번째 메뉴 번호에 따라 분기한다
        switch(menu_level_1) {
            case 1: { // 회원가입 메뉴
                switch(menu_level_2) {
                    case 1: { joinUI->createUser(inFile, outFile); break; } // 회원가입 처리
                }
                break;
            }
            case 2: { // 로그인/로그아웃 메뉴
                switch(menu_level_2) {
                    case 1: { loginUI->loginUser(inFile, outFile); break; } // 로그인 처리
                    case 2: { logoutUI->requestLogout(outFile, currentLoginUser); break; } // 로그아웃 처리
                }
                break;
            }
            case 3: { // 자전거 등록 메뉴
                switch(menu_level_2) {
                    case 1: { registerBikeUI->handleBikeRegistration(inFile, outFile, currentLoginUser); break; } // 자전거 등록 처리
                }
                break;
            }
            case 4: { // 자전거 대여 메뉴
                switch(menu_level_2) {
                    case 1: { rentBikeUI->startRentBike(inFile, outFile); break; } // 자전거 대여 처리
                }
                break;
            }
            case 5: { // 대여 리스트 조회 메뉴
                switch(menu_level_2) {
                    case 1: { listRentedBikeUI->showRentedBikes(outFile); break; } // 대여 리스트 조회 처리
                }
                break;
            }
            case 6: { // 종료 메뉴
                switch(menu_level_2) {
                    case 1: {
                        exitUI->exitProgram(outFile); // 종료 메시지 출력
                        is_program_exit = 1; // 프로그램 종료 플래그 설정
                        break;
                    }
                }
                break;
            }
        }
    }
}
