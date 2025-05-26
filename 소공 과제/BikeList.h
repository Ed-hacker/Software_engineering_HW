#pragma once
#include <vector>
#include <string>
#include "Bike.h"

// 시스템의 모든 자전거 정보를 관리한다
class BikeList {
private:
    std::vector<Bike> bikes; // 자전거 객체들을 저장하는 벡터

public:
    // 새로운 자전거 목록 객체를 생성한다
    BikeList();
    // 새로운 자전거를 목록에 추가한다
    void addBike(const Bike& bike);
    // 주어진 ID를 가진 자전거를 찾아 포인터를 반환한다 (없으면 nullptr)
    Bike* findBikeById(const std::string& id);
    // 등록된 모든 자전거 목록을 반환한다
    const std::vector<Bike>& getAllBikes() const;
}; 