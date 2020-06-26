
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
using namespace std;

typedef struct _point {
    double x;
    double y;

    _point operator +(const _point p) {
        _point ans;
        ans.x = x + p.x;
        ans.y = y + p.y;
        return ans;
    }
    _point operator -(const _point p) {
        _point ans;
        ans.x = x - p.x;
        ans.y = y - p.y;
        return ans;
    }
    _point operator *(const _point p) {
        _point ans;
        ans.x = x * p.x;
        ans.y = y * p.y;
        return ans;
    }
    _point operator /(const _point p) {
        _point ans;
        ans.x = x / p.x;
        ans.y = y / p.y;
        return ans;
    }


    _point operator +(const double d) {
        _point ans;
        ans.x = x + d;
        ans.y = y + d;
        return ans;
    }
    _point operator -(const double d) {
        _point ans;
        ans.x = x - d;
        ans.y = y - d;
        return ans;
    }
    _point operator *(const double d) {
        _point ans;
        ans.x = x * d;
        ans.y = y * d;
        return ans;
    }
    _point operator /(const double d) {
        _point ans;
        ans.x = x / d;
        ans.y = y / d;
        return ans;
    }
}point;


point* _KochCurve(const point pPoint[2], int& pointCnt, const int kochCnt) {
    point* outPoint;
    int cnt = 1;
    if (kochCnt > 0) {
        for (int i = 0;i < kochCnt;i++) {
            cnt *= 4;
        }
        pointCnt = cnt + 1;
        outPoint = new point[pointCnt];
        point newPoint[5];
        double length = sqrt((pPoint[1].x - pPoint[0].x) * (pPoint[1].x - pPoint[0].x) + (pPoint[1].y - pPoint[0].y) * (pPoint[1].y - pPoint[0].y));
        point normal, vec;
        normal.x = (pPoint[1].x - pPoint[0].x) / length;
        normal.y = (pPoint[1].y - pPoint[0].y) / length;


        newPoint[0] = pPoint[0];
        newPoint[1] = (normal * (length / 3)) + pPoint[0];
        vec = newPoint[1] - newPoint[0];
        newPoint[2].x = vec.x * cos(M_PI / 3) - vec.y * sin(M_PI / 3);
        newPoint[2].y = vec.x * sin(M_PI / 3) + vec.y * cos(M_PI / 3);
        newPoint[2] = newPoint[2] + newPoint[1];
        newPoint[3] = (normal * (length / 3) * 2) + pPoint[0];
        newPoint[4] = pPoint[1];

        point* buff;
        point  p[2];
        int num = 0;
        for (int i = 0;i < 4;i++) {
            p[0] = newPoint[i];
            p[1] = newPoint[i + 1];

            buff = _KochCurve(p, cnt, kochCnt - 1);
            if (buff != nullptr) {
                for (int j = 0;j < (cnt - 1);j++) {
                    outPoint[num] = buff[j];
                    num++;
                }
                delete[] buff;
            }
            else {
                outPoint[num] = newPoint[i];
                num++;
            }
        }
        outPoint[num] = newPoint[4];
        return outPoint;
    }
    else {
        outPoint = nullptr;
        pointCnt = 0;
        return outPoint;
    }
}

point* KochCurve(const point pPoint[2], int& pointCnt, const int kochCnt) {
    point* outPoint;
    if (kochCnt == 0) {
        outPoint = new point[2];
        outPoint[0] = pPoint[0];
        outPoint[1] = pPoint[1];
        pointCnt = 2;
        return outPoint;
    }
    return _KochCurve(pPoint, pointCnt, kochCnt);
}
