#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

// ��ά������
class Vector2d
{
    public:
        ll x_, y_;
    public:
        Vector2d(ll x, ll y) : x_(x), y_(y) {}
        Vector2d() : x_(0), y_(0) {}

        // ��ά������ˣ�����ֻ���ǲ�������Ĵ�С
        ll CrossProduct(const Vector2d& v) const
        {
            return x_ * v.y_ - y_ * v.x_;
        }

        // ��ά�������
        ll DotProduct(const Vector2d& v) const
        {
            return x_ * v.x_ + y_ * v.y_;
        }

        // ��ά��������
        Vector2d operator-(const Vector2d& v) const
        {
            return Vector2d(x_ - v.x_, y_ - v.y_);
        }

        // ��ά�����ӷ�
        Vector2d operator+(const Vector2d& v) const
        {
            return Vector2d(x_ + v.x_, y_ + v.y_);
        }

        // �жϵ�M��N�Ƿ���ֱ��AB��ͬһ��
        static bool IsPointAtSameSideOfLine(const Vector2d& A, const Vector2d& B, const Vector2d& M, const Vector2d& N)
        {
            Vector2d AB = B - A;
            Vector2d AM = M - A;
            Vector2d AN = N - A;

            // ����0ʱ��ʾĳ������ֱ����
            return AB.CrossProduct(AM) * AB.CrossProduct(AN) >= 0;
        }
};

// ��������
class Triangle
{
    public:
        Vector2d pointA_;
        Vector2d pointB_;
        Vector2d pointC_;
    public:
        Triangle(const Vector2d& point1, const Vector2d& point2, const Vector2d& point3) :
                 pointA_(point1), pointB_(point2), pointC_(point3) { }
        Triangle() : pointA_(Vector2d()), pointB_(Vector2d()), pointC_(Vector2d()) { }

        // ���������ε����
        ll ComputeTriangleArea() const
        {
            Vector2d AB = pointB_ - pointA_;
            Vector2d AC = pointC_ - pointA_;

            return abs(AB.CrossProduct(AC) / 2.0);
        }

        // ����һ��ͨ������Ĵ�С��ϵ�ж�
        bool IsPointInTriangle1(const Vector2d& pointP) const
        {
            ll area_ABC = ComputeTriangleArea();
            ll area_PAB = Triangle(pointP, pointA_, pointB_).ComputeTriangleArea();
            ll area_PAC = Triangle(pointP, pointA_, pointC_).ComputeTriangleArea();
            ll area_PBC = Triangle(pointP, pointB_, pointC_).ComputeTriangleArea();

            if (area_ABC - (area_PAB + area_PAC + area_PBC) <= 1e-6)
                return true;
            else
                return false;
        }

        // ��������ͨ�����������Ƿ�����һ��ֱ�ߵ�ͬ���ж�
        bool IsPointInTriangle2(const Vector2d& pointP) const
        {
            // �жϵ�P�Ƿ��������ߵ�ͬһ��
            return Vector2d::IsPointAtSameSideOfLine(pointA_, pointB_, pointP, pointC_) &&
                   Vector2d::IsPointAtSameSideOfLine(pointB_, pointC_, pointP, pointA_) &&
                   Vector2d::IsPointAtSameSideOfLine(pointC_, pointA_, pointP, pointB_);
        }

        // ������������������������͵����������ڲ��ĳ�Ҫ�����ж�
        bool IsPointInTriangle3(const Vector2d& pointP) const
        {
            Vector2d AB = pointB_ - pointA_;
            Vector2d AC = pointC_ - pointA_;
            Vector2d AP = pointP - pointA_;
            ll dot_ac_ac = AC.DotProduct(AC);
            ll dot_ac_ab = AC.DotProduct(AB);
            ll dot_ac_ap = AC.DotProduct(AP);
            ll dot_ab_ab = AB.DotProduct(AB);
            ll dot_ab_ap = AB.DotProduct(AP);
            
            ll tmp = 1.0 / (dot_ac_ac * dot_ab_ab - dot_ac_ab * dot_ac_ab);
            // �����ĵ�˾��н�����
            
            ll u = (dot_ab_ab * dot_ac_ap - dot_ac_ab * dot_ab_ap) * tmp;
            if(u < 0 || u > 1)
            return false;

            ll v = (dot_ac_ac * dot_ab_ap - dot_ac_ab * dot_ac_ap) * tmp;
            if(v < 0 || v > 1)
            return false;

            return u + v <= 1;
        }

        // �����ģ�PA PB PC��������ˣ�������ͬ�����P���������ڲ�
        bool IsPointInTriangle4(const Vector2d& pointP) const
        {
            Vector2d PA = pointA_ - pointP;
            Vector2d PB = pointB_ - pointP;
            Vector2d PC = pointC_ - pointP;

            ll cross_PA_PB = PA.CrossProduct(PB);
            ll cross_PB_PC = PB.CrossProduct(PC);
            ll cross_PC_PA = PC.CrossProduct(PA);

            if (cross_PA_PB * cross_PB_PC >= 0 && cross_PB_PC * cross_PC_PA >= 0)
                return true;
            else
                return false;
        }
};

int main()
{
    Triangle a;

    while(scanf("%lf %lf %lf %lf %lf %lf", &a.pointA_.x_, &a.pointA_.y_, &a.pointB_.x_, &a.pointB_.y_, &a.pointC_.x_, &a.pointC_.y_) != EOF)
    {
        Vector2d p;
        scanf("%lf %lf", &p.x_, &p.y_);

        if (a.IsPointInTriangle1(p)) 
            printf("YES\n");
        else 
            printf("NO\n");
    }
    
    return 0;
}