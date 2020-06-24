
#include <iostream>
#include <math.h>
using namespace std;




int Allocation() {


    int baggageCnt, truckCnt, checkLine, aveWeight;
    int* weightList;
    int* truckWeight;
    int maxWeight, minWeight;
    bool loopFlag;


    cin >> baggageCnt;
    cin >> truckCnt;
    weightList = new int[baggageCnt];
    truckWeight = new int[truckCnt];
    aveWeight = 0;
    checkLine = 0;

    // トラック一台あたりの平均値を求める
    for (int i = 0;i < baggageCnt;i++) {
        cin >> weightList[i];
        aveWeight += weightList[i];
    }
    minWeight = checkLine;
    aveWeight /= truckCnt;
    checkLine = aveWeight;
    minWeight = checkLine;


    //　まず、平均値をもとに荷物を配分し、最大積載量を求め、最大積載量をもとに再分配を繰り返す
    do {
        // トラックを初期化
        for (int i = 0;i < truckCnt;i++) {
            truckWeight[i] = 0;
        }
        loopFlag = false;
        maxWeight = 0;
        for (int i = 0, j = 0;i < baggageCnt;i++) {
            if ((truckWeight[j] + weightList[i]) < checkLine) {
                truckWeight[j] += weightList[i];
            }
            else {
                if ((j + 1) < truckCnt)
                    j++;
                truckWeight[j] += weightList[i];
            }
            // ここで最大積載量を求める
            if (truckWeight[j] > maxWeight) {
                maxWeight = truckWeight[j];
            }
        }
        if (minWeight >= maxWeight) {
            minWeight = maxWeight;
        }
        else if (checkLine < maxWeight) {
            checkLine++;
            minWeight = checkLine;
            loopFlag = true;
        }
    } while (loopFlag);

    std::cout << minWeight << endl;


    delete[] weightList, truckWeight;
    return 0;
}